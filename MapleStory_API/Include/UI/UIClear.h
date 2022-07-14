#pragma once

#include "UIWindow.h"

class CUIClear :
    public CUIWindow
{
    friend class CScene;

private:
    CUIClear();
    virtual ~CUIClear();

public:
    virtual bool Init();
    virtual void Update(float DeltaTime);
    virtual void PostUpdate(float DeltaTime);
    virtual void Collision(float DeltaTime);
    virtual void Render(HDC hDC);

public:
    void Finsh();
};

