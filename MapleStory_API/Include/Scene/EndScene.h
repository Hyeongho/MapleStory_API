#pragma once

#include "Scene.h"

class CEndScene :
    public CScene
{
	friend class CSceneManager;

private:
	CEndScene();
	virtual ~CEndScene();

public:
	virtual bool Init();
	virtual bool Update(float DeltaTime);
	virtual bool PostUpdate(float DeltaTime);
	virtual bool Collision(float DeltaTime);
	virtual bool Render(HDC hDC);

private:
	void LoadAnimationSequence();
	void LoadSound();
};

