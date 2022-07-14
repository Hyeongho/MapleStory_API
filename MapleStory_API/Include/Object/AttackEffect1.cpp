#include "AttackEffect1.h"

CAttackEffect1::CAttackEffect1()
{
	m_ObjType = EObject_Type::Effect;
}

CAttackEffect1::CAttackEffect1(const CAttackEffect1& obj) : CGameObject(obj)
{
	m_Direction = obj.m_Direction;
}

CAttackEffect1::~CAttackEffect1()
{
}

void CAttackEffect1::Start()
{
	CGameObject::Start();

	SetAnimationEndNotify<CAttackEffect1>("AttackEffect1", this, &CAttackEffect1::AnimationFinish);
}

bool CAttackEffect1::Init(bool Direction)
{
	if (!CGameObject::Init())
	{
		return false;
	}

	SetPivot(0.5f, 0.5f);

	CreateAnimation();
	AddAnimation("AttackEffect1", false, 0.6f);

	return true;
}

void CAttackEffect1::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CAttackEffect1::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CAttackEffect1::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CAttackEffect1::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CAttackEffect1* CAttackEffect1::Clone()
{
	return new CAttackEffect1(*this);
}

void CAttackEffect1::AnimationFinish()
{
	Destroy();
}
