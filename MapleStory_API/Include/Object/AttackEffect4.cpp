#include "AttackEffect4.h"

CAttackEffect4::CAttackEffect4()
{
	m_ObjType = EObject_Type::Effect;
}

CAttackEffect4::CAttackEffect4(const CAttackEffect4& obj) : CGameObject(obj)
{
	m_Direction = obj.m_Direction;
}

CAttackEffect4::~CAttackEffect4()
{
}

void CAttackEffect4::Start()
{
	CGameObject::Start();

	SetAnimationEndNotify<CAttackEffect4>("AttackEffect4", this, &CAttackEffect4::AnimationFinish);
}

bool CAttackEffect4::Init(bool Direction)
{
	if (!CGameObject::Init())
	{
		return false;
	}

	SetPivot(0.5f, 0.5f);

	CreateAnimation();
	AddAnimation("AttackEffect4", false, 0.7f);

	return true;
}

void CAttackEffect4::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CAttackEffect4::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CAttackEffect4::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CAttackEffect4::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CAttackEffect4* CAttackEffect4::Clone()
{
	return new CAttackEffect4(*this);
}

void CAttackEffect4::AnimationFinish()
{
	Destroy();
}
