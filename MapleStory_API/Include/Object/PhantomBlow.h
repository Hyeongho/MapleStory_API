#pragma once

#include "GameObject.h"

class CPhantomBlow :
	public CGameObject
{
	friend class CScene;

protected:
	CPhantomBlow();
	CPhantomBlow(const CPhantomBlow& obj);
	virtual ~CPhantomBlow();

private:
	bool m_Direction;
	bool m_IsHit;

	Vector2 Pos;
	Vector2 Size;

public:
	virtual void Start();
	virtual bool Init(bool Direction);
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CPhantomBlow* Clone();

public:
	void ChangeAnimation(bool Direction);
	void AnimationFinish();

	void ColliderBegin(class CCollider* Src, class CCollider* Dest, float DeltaTime);
	void Attack();
};

