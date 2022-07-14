#pragma once

#include "Character.h"

class CMonster :
    public CCharacter
{
	friend class CScene;

protected:
	CMonster();
	CMonster(const CMonster& obj);
	virtual ~CMonster();

protected:
	EMonsterAI m_AI;
	Vector2 m_Dir;
	float m_ActiveTime;
	float m_DetectDistance;
	float m_AttackDistance;
	bool m_AttackEnable;

	int m_IsMove;
	float m_RandActive;

	bool m_IsTarget;

	bool m_IsAttack;
	bool m_IsAttackAni;
	bool m_IsHit;

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CMonster* Clone();
	virtual float SetDamage(float Damage);

protected:
	virtual void AIIdle(float DeltaTime);
	virtual void AIMove(float DeltaTime);
	virtual void AITrace(float DeltaTime);
	virtual void AIAttack(float DeltaTime);
	virtual void AIDeath(float DeltaTime);

};

