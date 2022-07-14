#include "Aranea.h"
#include "../Scene/Scene.h"
#include "../Scene/Stage1.h"
#include "../Collision/Collider.h"
#include "../Collision/CollisionManager.h"
#include "../Collision/ColliderBox.h"
#include "../Collision/ColliderSphere.h"

CAranea::CAranea()
{
}

CAranea::CAranea(const CAranea& obj) : CMonster(obj)
{
}

CAranea::~CAranea()
{
}

void CAranea::Start()
{
	CMonster::Start();

	CCollider* AttackSense = FindCollider("AttackSense");

	AttackSense->SetCollisionBeginFunction<CAranea>(this, &CAranea::CollisionAttackBegin);
	AttackSense->SetCollisionEndFunction<CAranea>(this, &CAranea::CollisionAttackEnd);

	AddAnimationNotify<CAranea>("RightAraneaAttack", 16, this, &CAranea::AttackEnd);
	AddAnimationNotify<CAranea>("LeftAraneaAttack", 16, this, &CAranea::AttackEnd);

	SetAnimationEndNotify<CAranea>("RightAraneaDie", this, &CAranea::Die);
	SetAnimationEndNotify<CAranea>("LeftAraneaDie", this, &CAranea::Die);
}

bool CAranea::Init()
{
	if (!CMonster::Init())
	{
		return false;
	}

	SetPivot(0.5f, 1.f);

	CreateAnimation();

	AddAnimation("RightAraneaStand");
	AddAnimation("RightAraneaMove");
	AddAnimation("RightAraneaAttack");
	AddAnimation("RightAraneaDie", false);

	AddAnimation("LeftAraneaStand");
	AddAnimation("LeftAraneaMove");
	AddAnimation("LeftAraneaAttack");
	AddAnimation("LeftAraneaDie", false);

	CColliderBox* AttackSense = AddCollider<CColliderBox>("AttackSense");
	AttackSense->SetExtent(500.f, 300.f);
	AttackSense->SetOffset(0.f, -100.f);

	CColliderBox* Body = AddCollider<CColliderBox>("Body");
	Body->SetExtent(258.f, 148.f);
	Body->SetOffset(0.f, -74.f);
	Body->SetCollisionProfile("Monster");

	m_MoveSpeed = 100.f;

	m_CharacterInfo.HP = 100;
	m_CharacterInfo.HPMax = 100;

	return true;
}

void CAranea::Update(float DeltaTime)
{
	CMonster::Update(DeltaTime);

	CGameObject* Player = m_Scene->GetPlayer();

	Vector2 Range = GetRange();

	if (CheckCurrentAnimation("RightAraneaAttack") || CheckCurrentAnimation("LeftAraneaAttack"))
	{
		if (m_Direction)
		{
			SetOffset(-162.f, 75.f);
		}

		else
		{
			SetOffset(162.f, 75.f);
		}
	}

	else if (CheckCurrentAnimation("LeftAraneaDie") || CheckCurrentAnimation("RightAraneaDie"))
	{
		SetOffset(0.f, 14.f);
	}

	else
	{
		SetOffset(0.f, 0.f);
	}

	float Dist = Distance(Player->GetPos(), m_Pos);

	if (m_Pos.x < 400.f)
	{
		m_Pos.x = 400.f;
	}

	if (m_Pos.x > Range.x + m_Size.x + (m_Size.x / 2))
	{
		m_Pos.x = Range.x + m_Size.x + (m_Size.x / 2);
	}

	if (!m_IsAttackAni)
	{
		m_ActiveTime += DeltaTime;

		if (m_ActiveTime > m_RandActive)
		{
			if (m_IsAttack)
			{
				m_IsMove = rand() % 3;
			}

			else
			{
				m_IsMove = rand() % 2;
			}

			if (!m_IsAttackAni)
			{
				m_ActiveTime = 0.f;

				if (m_IsMove == 0)
				{
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

					m_AI = EMonsterAI::Move;
				}

				else if (m_IsMove == 1)
				{
					m_AI = EMonsterAI::Idle;
				}

				else
				{
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

					m_AI = EMonsterAI::Attack;
				}
			}

			m_RandActive = (float)(rand() % 3);
		}
	}

	if (m_CharacterInfo.HP <= 0)
	{
		m_AI = EMonsterAI::Death;
	}
}

void CAranea::PostUpdate(float DeltaTime)
{
	CMonster::PostUpdate(DeltaTime);

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

void CAranea::Collision(float DeltaTime)
{
	CMonster::Collision(DeltaTime);
}

void CAranea::Render(HDC hDC)
{
	CMonster::Render(hDC);
}

CAranea* CAranea::Clone()
{
	return new CAranea(*this);
}

float CAranea::SetDamage(float Damage)
{
	Damage = CCharacter::SetDamage(Damage);

	return Damage;
}

void CAranea::AIIdle(float DeltaTime)
{
	CMonster::AIIdle(DeltaTime);

	if (CheckCurrentAnimation("LeftAraneaMove"))
	{
		ChangeAnimation("LeftAraneaStand");
	}

	if (CheckCurrentAnimation("RightAraneaMove"))
	{
		ChangeAnimation("RightAraneaStand");
	}
}

void CAranea::AIMove(float DeltaTime)
{
	CMonster::AIMove(DeltaTime);

	if (m_Direction)
	{
		ChangeAnimation("LeftAraneaMove");

		Move(Vector2(-1.f, 0), m_MoveSpeed);
	}

	else
	{
		ChangeAnimation("RightAraneaMove");

		Move(Vector2(1.f, 0), m_MoveSpeed);
	}
}

void CAranea::AITrace(float DeltaTime)
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
		ChangeAnimation("LeftAraneaMove");
	}

	else
	{
		ChangeAnimation("RightAraneaMove");
	}

	Move(Dir, m_MoveSpeed);
}

void CAranea::AIAttack(float DeltaTime)
{
	CMonster::AIAttack(DeltaTime);

	if (!m_IsAttackAni && m_IsAttack)
	{
		m_IsAttackAni = true;

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
			ChangeAnimation("LeftAraneaAttack");
		}

		else
		{
			ChangeAnimation("RightAraneaAttack");
		}
	}
}

void CAranea::AIDeath(float DeltaTime)
{
	CMonster::AIDeath(DeltaTime);

	if (m_Direction)
	{
		ChangeAnimation("LeftAraneaDie");
	}

	else
	{
		ChangeAnimation("RightAraneaDie");
	}
}

void CAranea::CollisionAttackBegin(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	if (Dest->GetOwner()->GetName() == "Player")
	{
		m_IsAttack = true;
	}
}

void CAranea::CollisionAttackEnd(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	m_IsAttack = false;
}

void CAranea::AttackStart()
{
	m_IsAttackAni = true;
}

void CAranea::AttackEnd()
{
	m_IsAttackAni = false;

	if (m_Direction)
	{
		ChangeAnimation("LeftAraneaStand");
	}

	else
	{
		ChangeAnimation("RightAraneaStand");
	}
}

void CAranea::Die()
{
	Destroy();

	CStage1::m_Active++;
}
