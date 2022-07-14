#pragma once
#include "Scene.h"
class CStage1 :
    public CScene
{
	friend class CSceneManager;
	friend class CUIWave;

private:
	CStage1();
	virtual ~CStage1();

private:
	class CUIStage* m_StageWindow;
	class CUIDieNotice* m_DieNotice;

public:
	static std::list<CSharedPtr<CGameObject>> m_MonsterList;
	static int m_Active;
	static EWave m_Wave;

public:
	virtual bool Init();
	virtual bool Update(float DeltaTime);
	virtual bool PostUpdate(float DeltaTime);
	virtual bool Collision(float DeltaTime);
	virtual bool Render(HDC hDC);

private:
	void WaveStart();
	void WaveNormal();
	void WaveEnd();

private:
	void LoadAnimationSequence();
	void LoadSound();
};

