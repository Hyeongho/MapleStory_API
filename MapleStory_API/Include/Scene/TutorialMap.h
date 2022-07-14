#pragma once

#include "Scene.h"

class CTutorialMap :
    public CScene
{
	friend class CSceneManager;

private:
	CTutorialMap();
	virtual ~CTutorialMap();

private:
	class CUIDieNotice* m_DieNotice;

public:
	virtual bool Init();
	virtual bool Update(float DeltaTime);

private:
	void LoadAnimationSequence();
	void LoadSound();
};

