#pragma once

#include "Monster.h"

class CAranya :
    public CMonster
{
	friend class CScene;

public:
	CAranya();
	CAranya(const CAranya& obj);
	virtual ~CAranya();

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CAranya* Clone();
	virtual float SetDamage(float Damage);

protected:
	virtual void AIIdle(float DeltaTime);
	virtual void AIMove(float DeltaTime);
	virtual void AITrace(float DeltaTime);
	virtual void AIAttack(float DeltaTime);
	virtual void AIDeath(float DeltaTime);

public:
	void CollisionAttackBegin(class CCollider* Src, class CCollider* Dest, float DeltaTime);
	void CollisionAttackEnd(class CCollider* Src, class CCollider* Dest, float DeltaTime);

	void AttackStart();
	void AttackEnd();

	void Die();
};

