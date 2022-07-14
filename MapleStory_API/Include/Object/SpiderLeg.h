#pragma once

#include "GameObject.h"

class CSpiderLeg :
    public CGameObject
{
	friend class CScene;

public:
	CSpiderLeg();
	CSpiderLeg(const CSpiderLeg& obj);
	virtual ~CSpiderLeg();

private:
	bool m_IsHit;

public:
	virtual void Start();
	virtual bool Init(bool Direction);
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CSpiderLeg* Clone();

public:
	void AnimationFinish();
	void Attack();
	void AttackEnd();


	void ColliderBegin(class CCollider* Src, class CCollider* Dest, float DeltaTime);
};

