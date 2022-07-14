#pragma once

#include "Scene.h"

class CLoadScene :
    public CScene
{
	friend class CSceneManager;

private:
	CLoadScene();
	virtual ~CLoadScene();

public:
	virtual bool Init();
	virtual bool Update(float DeltaTime);
	virtual bool PostUpdate(float DeltaTime);
	virtual bool Collision(float DeltaTime);
	virtual bool Render(HDC hDC);

private:
	void LoadAnimationSequence();
};

