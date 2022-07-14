#pragma once

#include "Monster.h"

class CWillPase2 :
    public CMonster
{
	friend class CScene;
	friend class CSceneManager;

public:
	CWillPase2();
	CWillPase2(const CWillPase2& obj);
	virtual ~CWillPase2();

private:
	EWillPase2Pattern m_Pattern;
	int m_HPCount;

	bool m_Groggy;
	float m_GroggyTime;

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CWillPase2* Clone();
	virtual float SetDamage(float Damage);

public:
	void SetWillPase2Pattern(EWillPase2Pattern Pattern)
	{
		m_Pattern = Pattern;
	}

	void SetGroggy(bool Groggy)
	{
		m_Groggy = Groggy;

		if (m_HPCount == 1)
		{
			m_HPCount--;
		}

		if (m_Direction)
		{
			ChangeAnimation("LeftWillHit");
		}

		else
		{
			ChangeAnimation("RightWillHit");
		}
	}

public:
	bool GetGroggy() const
	{
		return m_Groggy;
	}

	int GetHPCount() const
	{
		return m_HPCount;
	}

protected:
	virtual void AIIdle(float DeltaTime);
	virtual void AIMove(float DeltaTime);
	virtual void AIAttack(float DeltaTime);
	virtual void AIDeath(float DeltaTime);

public:
	void CollisionAttackBegin(class CCollider* Src, class CCollider* Dest, float DeltaTime);
	void CollisionAttackEnd(class CCollider* Src, class CCollider* Dest, float DeltaTime);

	void AttackAnimationStart();
	void AttackAnimationEnd();

	void AttackStart();
	void AttackEnd();

	void CreateCollider();
	void DestoryCollider();

	void CollisionAttack(class CCollider* Src, class CCollider* Dest, float DeltaTime);

	void Cheat1(float DeltaTime);
};

