#include "AttackEffect2.h"

CAttackEffect2::CAttackEffect2()
{
	m_ObjType = EObject_Type::Effect;
}

CAttackEffect2::CAttackEffect2(const CAttackEffect2& obj) : CGameObject(obj)
{
	m_Direction = obj.m_Direction;
}

CAttackEffect2::~CAttackEffect2()
{
}

void CAttackEffect2::Start()
{
	CGameObject::Start();

	if (m_Direction)
	{
		SetAnimationEndNotify<CAttackEffect2>("LeftAttackEffect2", this, &CAttackEffect2::AnimationFinish);
	}

	else
	{
		SetAnimationEndNotify<CAttackEffect2>("RightAttackEffect2", this, &CAttackEffect2::AnimationFinish);
	}
}

bool CAttackEffect2::Init(bool Direction)
{
	if (!CGameObject::Init())
	{
		return false;
	}

	m_Direction = Direction;

	SetPivot(0.5f, 0.5f);

	CreateAnimation();

	if (Direction)
	{
		AddAnimation("LeftAttackEffect2", false, 0.6f);
	}

	else
	{
		AddAnimation("RightAttackEffect2", false, 0.6f);
	}

	return true;
}

void CAttackEffect2::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CAttackEffect2::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CAttackEffect2::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CAttackEffect2::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CAttackEffect2* CAttackEffect2::Clone()
{
	return new CAttackEffect2(*this);
}

void CAttackEffect2::AnimationFinish()
{
	Destroy();
}
