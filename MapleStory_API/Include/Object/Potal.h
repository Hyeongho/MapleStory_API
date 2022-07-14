#pragma once

#include "GameObject.h"

class CPotal :
    public CGameObject
{
	friend class CScene;

public:
	CPotal();
	CPotal(const CPotal& obj);
	virtual ~CPotal();

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CPotal* Clone();

public:
	void ColliderBegin(class CCollider* Src, class CCollider* Dest, float DeltaTime);
};

