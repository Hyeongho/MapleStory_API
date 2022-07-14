#include "Crack.h"

CCrack::CCrack()
{
}

CCrack::CCrack(const CCrack& obj) : CGameObject(obj)
{
}

CCrack::~CCrack()
{
}

void CCrack::Start()
{
	CGameObject::Start();
}

bool CCrack::Init()
{
	if (!CGameObject::Init())
	{
		return false;
	}

	CreateAnimation();
	AddAnimation("Crack", false);

	return true;
}

void CCrack::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CCrack::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CCrack::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CCrack::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CCrack* CCrack::Clone()
{
	return new CCrack(*this);
}

void CCrack::AnimationFinish()
{
	Destroy();
}

void CCrack::ColliderBegin(CCollider* Src, CCollider* Dest, float DeltaTime)
{
}
