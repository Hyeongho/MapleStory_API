#pragma once

#include "UIWindow.h"
#include "UIImage.h"

class CUIStage :
    public CUIWindow
{
    friend class CScene;

private:
    CUIStage();
    virtual ~CUIStage();

private:
    CUIImage* m_CountImage;
    CUIImage* m_WaveImage;

public:
    static int m_Count;

public:
    virtual bool Init();
    virtual void Update(float DeltaTime);
    virtual void PostUpdate(float DeltaTime);
    virtual void Collision(float DeltaTime);
    virtual void Render(HDC hDC);

public:
    void Finsh();
};