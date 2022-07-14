#pragma once

#include "GameObject.h"

class CBladeFury :
    public CGameObject
{
	friend class CScene;

protected:
	CBladeFury();
	CBladeFury(const CBladeFury& obj);
	virtual ~CBladeFury();

private:
	bool m_Direction;

public:
	virtual void Start();
	virtual bool Init(bool Direction);
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CBladeFury* Clone();

public:
	void AnimationFinish();
};

