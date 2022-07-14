#include "Shadowblade.h"
#include "../Scene/Scene.h"
#include "../Collision/Collider.h"
#include "../Collision/CollisionManager.h"
#include "../Collision/ColliderBox.h"
#include "../Collision/ColliderSphere.h"

CShadowBlade::CShadowBlade()
{
}

CShadowBlade::CShadowBlade(const CShadowBlade& obj) : CMonster(obj)
{
}

CShadowBlade::~CShadowBlade()
{
}

void CShadowBlade::Start()
{
	CMonster::Start();

	CCollider* Trace = FindCollider("Trace");

	Trace->SetCollisionBeginFunction<CShadowBlade>(this, &CShadowBlade::CollisionTargetBegin);
	Trace->SetCollisionEndFunction<CShadowBlade>(this, &CShadowBlade::CollisionTargetEnd);

	CCollider* AttackSense = FindCollider("AttackSense");

	AttackSense->SetCollisionBeginFunction<CShadowBlade>(this, &CShadowBlade::CollisionAttackBegin);
	AttackSense->SetCollisionEndFunction<CShadowBlade>(this, &CShadowBlade::CollisionAttackEnd);

	CCollider* LeftAttackCollider = FindCollider("LeftAttackBox");

	LeftAttackCollider->SetCollisionBeginFunction<CShadowBlade>(this, &CShadowBlade::CollisionHitBegin);
	LeftAttackCollider->SetCollisionEndFunction<CShadowBlade>(this, &CShadowBlade::CollisionHitEnd);

	CCollider* RightAttackCollider = FindCollider("RightAttackBox");

	RightAttackCollider->SetCollisionBeginFunction<CShadowBlade>(this, &CShadowBlade::CollisionHitBegin);
	RightAttackCollider->SetCollisionEndFunction<CShadowBlade>(this, &CShadowBlade::CollisionHitEnd);


	AddAnimationNotify<CShadowBlade>("RightShadowBladeAttack", 0, this, &CShadowBlade::AttackAnimationStart);
	AddAnimationNotify<CShadowBlade>("LeftShadowBladeAttack", 0, this, &CShadowBlade::AttackAnimationStart);

	AddAnimationNotify<CShadowBlade>("RightShadowBladeAttack", 6, this, &CShadowBlade::AttackStart);
	AddAnimationNotify<CShadowBlade>("LeftShadowBladeAttack", 6, this, &CShadowBlade::AttackStart);

	AddAnimationNotify<CShadowBlade>("RightShadowBladeAttack", 7, this, &CShadowBlade::AttackEnd);
	AddAnimationNotify<CShadowBlade>("LeftShadowBladeAttack", 7, this, &CShadowBlade::AttackEnd);

	AddAnimationNotify<CShadowBlade>("RightShadowBladeAttack", 8, this, &CShadowBlade::AttackAnimationEnd);
	AddAnimationNotify<CShadowBlade>("LeftShadowBladeAttack", 8, this, &CShadowBlade::AttackAnimationEnd);

}

bool CShadowBlade::Init()
{
	if (!CMonster::Init())
	{
		return false;
	}

	SetPivot(0.5f, 1.f);

	CreateAnimation();
	AddAnimation("RightShadowBladeStand");
	AddAnimation("LeftShadowBladeStand");
	AddAnimation("RightShadowBladeMove");
	AddAnimation("LeftShadowBladeMove");
	AddAnimation("RightShadowBladeAttack");
	AddAnimation("LeftShadowBladeAttack");

	CColliderBox* Trace = AddCollider<CColliderBox>("Trace");
	Trace->SetExtent(500.f, 300.f);
	Trace->SetOffset(0.f, -100.f);

	CColliderBox* AttackSense = AddCollider<CColliderBox>("AttackSense");
	AttackSense->SetExtent(50.f, 100.f);
	AttackSense->SetOffset(0.f, -36.5f);
	AttackSense->SetCollisionProfile("Monster");

	CColliderBox* LeftAttackBox = AddCollider<CColliderBox>("LeftAttackBox");
	LeftAttackBox->SetExtent(50.f, 100.f);
	LeftAttackBox->SetOffset(-50.f, -36.5f);
	LeftAttackBox->SetCollisionProfile("MonsterAttack");

	CColliderBox* RightAttackBox = AddCollider<CColliderBox>("RightAttackBox");
	RightAttackBox->SetExtent(50.f, 100.f);
	RightAttackBox->SetOffset(50.f, -36.5f);
	RightAttackBox->SetCollisionProfile("MonsterAttack");

	m_MoveSpeed = 100.f;

	m_RandActive = (float)(rand() % 2);

	return true;
}

void CShadowBlade::Update(float DeltaTime)
{
	CMonster::Update(DeltaTime);

	CGameObject* Player = m_Scene->GetPlayer();

	Vector2 Range = GetRange();

	float Dist = Distance(Player->GetPos(), m_Pos);

	if (m_Pos.x < 800.f)
	{
		m_Pos.x = 800.f;
	}

	if (m_Pos.x > Range.x + m_Size.x + (m_Size.x / 2))
	{
		m_Pos.x = Range.x + m_Size.x + (m_Size.x / 2);
	}

	if (!m_IsAttackAni)
	{
		if (m_IsTarget)
		{
			m_ActiveTime = 0.f;

			m_AI = EMonsterAI::Trace;

			if (m_IsAttack)
			{
				m_AI = EMonsterAI::Attack;
			}
		}

		else
		{
			m_ActiveTime += DeltaTime;

			if (m_ActiveTime > m_RandActive)
			{
				m_ActiveTime = 0.f;

				m_IsMove = rand() % 2;

				if (m_IsMove)
				{
					m_Direction = (bool)(rand() % 2);

					m_AI = EMonsterAI::Move;
				}

				else
				{
					m_AI = EMonsterAI::Idle;
				}

				m_RandActive = (float)(rand() % 2);
			}
		}
	}

	if (CheckCurrentAnimation("RightShadowBladeAttack") || CheckCurrentAnimation("LeftShadowBladeAttack"))
	{
		SetOffset(0.f, 10.f);
	}

	else
	{
		SetOffset(0.f, 0.f);
	}

	switch (m_AI)
	{
	case EMonsterAI::Idle:
		AIIdle(DeltaTime);
		break;

	case EMonsterAI::Move:
		AIMove(DeltaTime);
		break;

	case EMonsterAI::Trace:
		AITrace(DeltaTime);
		break;

	case EMonsterAI::Attack:
		AIAttack(DeltaTime);
		break;

	case EMonsterAI::Death:
		AIDeath(DeltaTime);
		break;
	}
}

void CShadowBlade::PostUpdate(float DeltaTime)
{
	CMonster::PostUpdate(DeltaTime);
}

void CShadowBlade::Collision(float DeltaTime)
{
	CMonster::Collision(DeltaTime);
}

void CShadowBlade::Render(HDC hDC)
{
	CMonster::Render(hDC);
}

CShadowBlade* CShadowBlade::Clone()
{
	return new CShadowBlade(*this);
}

float CShadowBlade::SetDamage(float Damage)
{
	Damage = CCharacter::SetDamage(Damage);

	return Damage;
}

void CShadowBlade::AIIdle(float DeltaTime)
{
	CMonster::AIIdle(DeltaTime);

	if (CheckCurrentAnimation("LeftShadowBladeMove"))
	{
		ChangeAnimation("LeftShadowBladeStand");
	}

	if (CheckCurrentAnimation("RightShadowBladeMove"))
	{
		ChangeAnimation("RightShadowBladeStand");
	}
}

void CShadowBlade::AIMove(float DeltaTime)
{
	CMonster::AIMove(DeltaTime);

	if (m_Direction)
	{
		ChangeAnimation("LeftShadowBladeMove");

		Move(Vector2(-1.f, 0), m_MoveSpeed);
	}

	else
	{
		ChangeAnimation("RightShadowBladeMove");

		Move(Vector2(1.f, 0), m_MoveSpeed);
	}
}

void CShadowBlade::AITrace(float DeltaTime)
{
	CMonster::AITrace(DeltaTime);

	CGameObject* Player = m_Scene->GetPlayer();

	Vector2	Dir = Player->GetPos() - m_Pos;
	Dir.Normalize();

	if (Dir.x < 0)
	{
		m_Direction = true;
	}

	else
	{
		m_Direction = false;
	}

	if (m_Direction)
	{
		ChangeAnimation("LeftShadowBladeMove");
	}

	else
	{
		ChangeAnimation("RightShadowBladeMove");
	}

	Move(Dir, m_MoveSpeed);
}

void CShadowBlade::AIAttack(float DeltaTime)
{
	CMonster::AIAttack(DeltaTime);

	if (m_Direction)
	{
		ChangeAnimation("LeftShadowBladeAttack");
	}

	else
	{
		ChangeAnimation("RightShadowBladeAttack");
	}
}

void CShadowBlade::AIDeath(float DeltaTime)
{
	CMonster::AIDeath(DeltaTime);
}

void CShadowBlade::CollisionTargetBegin(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	if (Dest->GetOwner()->GetName() == "Player")
	{
		m_IsTarget = true;
	}
}

void CShadowBlade::CollisionTargetEnd(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	m_IsTarget = false;
}

void CShadowBlade::CollisionAttackBegin(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	if (Dest->GetOwner()->GetName() == "Player")
	{
		m_IsAttack = true;
	}	
}

void CShadowBlade::CollisionAttackEnd(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	m_IsAttack = false;
}

void CShadowBlade::AttackAnimationStart()
{
	m_IsAttackAni = true;
}

void CShadowBlade::AttackAnimationEnd()
{
	if (!m_IsAttack)
	{
		m_IsAttackAni = false;
	}

	CGameObject* Player = m_Scene->GetPlayer();

	Vector2	Dir = Player->GetPos() - m_Pos;
	Dir.Normalize();

	if (Dir.x < 0)
	{
		m_Direction = true;
	}

	else
	{
		m_Direction = false;
	}
}

void CShadowBlade::AttackStart()
{
	if (m_IsHit)
	{
		CGameObject* Player = m_Scene->GetPlayer();

		Player->SetDamage(10);
	}
}

void CShadowBlade::AttackEnd()
{

}

void CShadowBlade::CollisionHitBegin(class CCollider* Src, class CCollider* Dest, float DeltaTime)
{
	m_IsHit = true;
}

void CShadowBlade::CollisionHitEnd(class CCollider* Src, class CCollider* Dest, float DeltaTime)
{
	m_IsHit = false;
}
