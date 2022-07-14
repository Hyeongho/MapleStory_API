#pragma once

#include "Scene.h"

class CBossWillPase2 :
    public CScene
{
	friend class CSceneManager;

private:
	CBossWillPase2();
	virtual ~CBossWillPase2();

private:
	bool m_UpLegActive;
	bool m_DownLegActive;
	bool m_CrackActive;

	EWillPase2 m_EWillPase2;
	EWillPase2Pattern m_EWillPase2Partern;

	CSharedPtr<CGameObject> m_Crack;
	class CUINotice* m_Notice;
	class CUIDieNotice* m_DieNotice;

private:
	float m_Time;

	std::vector<float> m_vecLeg;
	std::vector<float> m_vecPLeg;

	int m_PLegCount;

	float m_PatternCount;
	float m_PatternTime;
	float m_RPatternTime;

	bool m_DeathFlag;

public:
	static int m_DeathCount;

public:
	void SetUpLegActive(bool UpLegActive)
	{
		m_UpLegActive = UpLegActive;
	}

	void SetDownLegActive(bool DownLegActive)
	{
		m_DownLegActive = DownLegActive;
	}

	void SetCrackActive(bool CrackActive)
	{
		m_CrackActive = CrackActive;
	}

	void SetTime(float Time)
	{
		m_Time = Time;
	}

public:
	bool GetUpLegActive() const
	{
		return m_UpLegActive;
	}

	bool GetDownLegActive() const
	{
		return m_DownLegActive;
	}

	bool GetCrackActive() const
	{
		return m_CrackActive;
	}

	float GetTime() const
	{
		return m_Time;
	}

	EWillPase2 GetWillPase2() const
	{
		return m_EWillPase2;
	}

	EWillPase2Pattern GetWillPase2Pattern() const
	{
		return m_EWillPase2Partern;
	}

public:
	virtual bool Init();
	virtual bool Update(float DeltaTime);
	virtual bool PostUpdate(float DeltaTime);
	virtual bool Collision(float DeltaTime);
	virtual bool Render(HDC hDC);

private:
	void LoadAnimationSequence();
	void LoadSound();

	void Success();
	void Fail();
};

