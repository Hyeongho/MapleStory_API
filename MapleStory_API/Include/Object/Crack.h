#pragma once

#include "GameObject.h"

class CCrack :
    public CGameObject
{
	friend class CScene;

public:
	CCrack();
	CCrack(const CCrack& obj);
	virtual ~CCrack();

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CCrack* Clone();

public:
	void AnimationFinish();

	void ColliderBegin(class CCollider* Src, class CCollider* Dest, float DeltaTime);
};

