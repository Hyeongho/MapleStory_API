#pragma once

#include "Scene.h"

class CMainMap :
    public CScene
{
	friend class CSceneManager;

private:
	CMainMap();
	virtual ~CMainMap();

public:
	virtual bool Init();

private:
	void LoadAnimationSequence();
	void LoadSound();
};

