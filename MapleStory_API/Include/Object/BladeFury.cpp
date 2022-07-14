#include "BladeFury.h"
#include "Player.h"
#include "../Scene/Scene.h"
#include "../Collision/ColliderBox.h"

CBladeFury::CBladeFury() : m_Direction(false)
{
	m_ObjType = EObject_Type::Effect;
}

CBladeFury::CBladeFury(const CBladeFury& obj) : CGameObject(obj)
{
	m_Direction = obj.m_Direction;
}

CBladeFury::~CBladeFury()
{
}

void CBladeFury::Start()
{
	CGameObject::Start();

	SetAnimationEndNotify<CBladeFury>("BladeFury", this, &CBladeFury::AnimationFinish);
}

bool CBladeFury::Init(bool Direction)
{
	if (!CGameObject::Init())
	{
		return false;
	}

	m_Direction = Direction;

	SetPivot(0.5f, 0.5f);

	CreateAnimation();
	AddAnimation("BladeFury", false, 0.5f);

	return true;
}

void CBladeFury::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CBladeFury::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CBladeFury::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CBladeFury::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CBladeFury* CBladeFury::Clone()
{
	return new CBladeFury(*this);
}

void CBladeFury::AnimationFinish()
{
	Destroy();
}
