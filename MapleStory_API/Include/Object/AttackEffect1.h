#pragma once

#include "GameObject.h"

class CAttackEffect1 :
    public CGameObject
{
	friend class CScene;

protected:
	CAttackEffect1();
	CAttackEffect1(const CAttackEffect1& obj);
	virtual ~CAttackEffect1();

public:
	virtual void Start();
	virtual bool Init(bool Direction);
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CAttackEffect1* Clone();

public:
	void AnimationFinish();
};

