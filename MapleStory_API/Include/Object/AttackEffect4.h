#pragma once

#include "GameObject.h"

class CAttackEffect4 :
    public CGameObject
{
	friend class CScene;

protected:
	CAttackEffect4();
	CAttackEffect4(const CAttackEffect4& obj);
	virtual ~CAttackEffect4();

public:
	virtual void Start();
	virtual bool Init(bool Direction);
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CAttackEffect4* Clone();

public:
	void AnimationFinish();
};

