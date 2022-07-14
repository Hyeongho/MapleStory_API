#pragma once

#include "GameObject.h"

class CAttackEffect2 :
    public CGameObject
{
	friend class CScene;

protected:
	CAttackEffect2();
	CAttackEffect2(const CAttackEffect2& obj);
	virtual ~CAttackEffect2();

public:
	virtual void Start();
	virtual bool Init(bool Direction);
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CAttackEffect2* Clone();

public:
	void AnimationFinish();
};

