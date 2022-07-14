#include "EffectHit.h"
#include "../Scene/Scene.h"
#include "../Collision/ColliderBox.h"

CEffectHit::CEffectHit()
{
	m_ObjType = EObject_Type::Effect;
}

CEffectHit::CEffectHit(const CEffectHit& obj) : CGameObject(obj)
{
}

CEffectHit::~CEffectHit()
{
}

void CEffectHit::Start()
{
	CGameObject::Start();

	SetAnimationEndNotify<CEffectHit>("HitEffect", this, &CEffectHit::AnimationFinish);
}

bool CEffectHit::Init(bool Direction)
{
	if (!CGameObject::Init())
	{
		return false;
	}

	SetPivot(0.5f, 0.5f);

	CreateAnimation();
	AddAnimation("HitEffect", false, 0.7f);

	return true;
}

void CEffectHit::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CEffectHit::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CEffectHit::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CEffectHit::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CEffectHit* CEffectHit::Clone()
{
	return new CEffectHit(*this);
}

void CEffectHit::AnimationFinish()
{
	Destroy();
}
