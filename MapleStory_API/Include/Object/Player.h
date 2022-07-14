#pragma once
#include "Character.h"

class CPlayer :
    public CCharacter
{
	friend class CScene;

public:
	CPlayer();
	CPlayer(const CPlayer& obj);
	virtual ~CPlayer();

protected:
	bool m_Skill1Enable;
	bool m_AttackEnable;
	float m_Skill1Time;
	CSharedPtr<CWidgetComponent> m_StatusWidget;
	CSharedPtr<CWidgetComponent> m_NameWidget;

private:
	bool m_IsHit;

public:
	static bool m_IsDie;

public: 
	void SetAttackSpeed(float Speed)
	{
		CCharacter::SetAttackSpeed(Speed);
 		SetAnimationPlayScale("LucidNunNaRightAttack", Speed);
	}

	void SetHit(bool Hit)
	{
		m_IsHit = Hit;
	}

	void SetHP()
	{
		m_CharacterInfo.HP = m_CharacterInfo.HPMax;
	}

public:
	bool GetHit() const
	{
		return m_IsHit;
	}

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual CPlayer* Clone();
	virtual float SetDamage(float Damage);

public:
	void MoveUp(float DeltaTime);
	void MoveDown(float DeltaTime);
	void MoveLeft(float DeltaTime);
	void MoveRight(float DeltaTime);
	void PhantomBlow(float DeltaTime);
	void BladeFury(float DeltaTime);

	void Pause(float DeltaTime);
	void Resume(float DeltaTime);
	void JumpKey(float DeltaTime);

	void Potal(float DeltaTime);

	void Dead(float DeltaTime);

public:
	void AttackEnd();

	void CrackDamage(CCollider* Src, CCollider* Dest, float DeltaTime);

	void SkillEnd();
	void Skill1Enable();
};

