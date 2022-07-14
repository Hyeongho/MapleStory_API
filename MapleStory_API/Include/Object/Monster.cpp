#include "Monster.h"

CMonster::CMonster() : m_ActiveTime(0.f), m_AI(EMonsterAI::Idle), m_DetectDistance(500.f), m_AttackDistance(200.f), m_AttackEnable(false), m_IsMove(0), m_RandActive(0.f), m_IsTarget(false), 
	m_IsAttack(false), m_IsAttackAni(false), m_IsHit(false)
{
}

CMonster::CMonster(const CMonster& obj) : CCharacter(obj)
{
}

CMonster::~CMonster()
{
}

void CMonster::Start()
{
	CCharacter::Start();
}

bool CMonster::Init()
{
	if (!CCharacter::Init())
	{
		return false;
	}

	return true;
}

void CMonster::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);
}

void CMonster::PostUpdate(float DeltaTime)
{
	CCharacter::PostUpdate(DeltaTime);
}

void CMonster::Collision(float DeltaTime)
{
	CCharacter::Collision(DeltaTime);
}

void CMonster::Render(HDC hDC)
{
	CCharacter::Render(hDC);
}

CMonster* CMonster::Clone()
{
	return new CMonster(*this);
}

float CMonster::SetDamage(float Damage)
{
	Damage = CCharacter::SetDamage(Damage);

	return Damage;
}

void CMonster::AIIdle(float DeltaTime)
{
}

void CMonster::AIMove(float DeltaTime)
{
}

void CMonster::AITrace(float DeltaTime)
{
}

void CMonster::AIAttack(float DeltaTime)
{
}

void CMonster::AIDeath(float DeltaTime)
{
}
