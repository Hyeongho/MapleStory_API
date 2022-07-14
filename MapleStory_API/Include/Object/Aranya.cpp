#include "Aranya.h"
#include "../Scene/Scene.h"
#include "../Scene/Stage1.h"
#include "../Collision/Collider.h"
#include "../Collision/CollisionManager.h"
#include "../Collision/ColliderBox.h"
#include "../Collision/ColliderSphere.h"

CAranya::CAranya()
{
}

CAranya::CAranya(const CAranya& obj) : CMonster(obj)
{
}

CAranya::~CAranya()
{
}

void CAranya::Start()
{
	CMonster::Start();

	CCollider* AttackSense = FindCollider("AttackSense");

	AttackSense->SetCollisionBeginFunction<CAranya>(this, &CAranya::CollisionAttackBegin);
	AttackSense->SetCollisionEndFunction<CAranya>(this, &CAranya::CollisionAttackEnd);

	AddAnimationNotify<CAranya>("RightAranyaAttack", 16, this, &CAranya::AttackEnd);
	AddAnimationNotify<CAranya>("LeftAranyaAttack", 16, this, &CAranya::AttackEnd);

	SetAnimationEndNotify<CAranya>("RightAranyaDie", this, &CAranya::Die);
	SetAnimationEndNotify<CAranya>("LeftAranyaDie", this, &CAranya::Die);
}

bool CAranya::Init()
{
	if (!CMonster::Init())
	{
		return false;
	}

	SetPivot(0.5f, 1.f);

	CreateAnimation();

	AddAnimation("RightAranyaStand");
	AddAnimation("RightAranyaMove");
	AddAnimation("RightAranyaAttack");
	AddAnimation("RightAranyaDie", false);

	AddAnimation("LeftAranyaStand");
	AddAnimation("LeftAranyaMove");
	AddAnimation("LeftAranyaAttack");
	AddAnimation("LeftAranyaDie", false);

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

void CAranya::Update(float DeltaTime)
{
	CMonster::Update(DeltaTime);

	CGameObject* Player = m_Scene->GetPlayer();

	Vector2 Range = GetRange();

	if (CheckCurrentAnimation("RightAranyaAttack") || CheckCurrentAnimation("LeftAranyaAttack"))
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

	else if (CheckCurrentAnimation("LeftAranyaDie") || CheckCurrentAnimation("RightAranyaDie"))
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

void CAranya::PostUpdate(float DeltaTime)
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

void CAranya::Collision(float DeltaTime)
{
	CMonster::Collision(DeltaTime);
}

void CAranya::Render(HDC hDC)
{
	CMonster::Render(hDC);
}

CAranya* CAranya::Clone()
{
	return new CAranya(*this);
}

float CAranya::SetDamage(float Damage)
{
	Damage = CCharacter::SetDamage(Damage);

	return Damage;
}

void CAranya::AIIdle(float DeltaTime)
{
	CMonster::AIIdle(DeltaTime);

	if (CheckCurrentAnimation("LeftAranyaMove"))
	{
		ChangeAnimation("LeftAranyaStand");
	}

	if (CheckCurrentAnimation("RightAranyaMove"))
	{
		ChangeAnimation("RightAranyaStand");
	}
}

void CAranya::AIMove(float DeltaTime)
{
	CMonster::AIMove(DeltaTime);

	if (m_Direction)
	{
		ChangeAnimation("LeftAranyaMove");

		Move(Vector2(-1.f, 0), m_MoveSpeed);
	}

	else
	{
		ChangeAnimation("RightAranyaMove");

		Move(Vector2(1.f, 0), m_MoveSpeed);
	}
}

void CAranya::AITrace(float DeltaTime)
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
		ChangeAnimation("LeftAranyaMove");
	}

	else
	{
		ChangeAnimation("RightAranyaMove");
	}

	Move(Dir, m_MoveSpeed);
}

void CAranya::AIAttack(float DeltaTime)
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
			ChangeAnimation("LeftAranyaAttack");
		}

		else
		{
			ChangeAnimation("RightAranyaAttack");
		}
	}
}

void CAranya::AIDeath(float DeltaTime)
{
	CMonster::AIDeath(DeltaTime);

	if (m_Direction)
	{
		ChangeAnimation("LeftAranyaDie");
	}

	else
	{
		ChangeAnimation("RightAranyaDie");
	}
}

void CAranya::CollisionAttackBegin(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	if (Dest->GetOwner()->GetName() == "Player")
	{
		m_IsAttack = true;
	}
}

void CAranya::CollisionAttackEnd(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	m_IsAttack = false;
}

void CAranya::AttackStart()
{
	m_IsAttackAni = true;
}

void CAranya::AttackEnd()
{
	m_IsAttackAni = false;

	if (m_Direction)
	{
		ChangeAnimation("LeftAranyaStand");
	}

	else
	{
		ChangeAnimation("RightAranyaStand");
	}
}

void CAranya::Die()
{
	Destroy();

	CStage1::m_Active++;
}
