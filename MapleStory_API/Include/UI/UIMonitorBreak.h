#pragma once

#include "UIWindow.h"
#include "UIImage.h"

class CUIMonitorBreak :
    public CUIWindow
{
    friend class CScene;

private:
    CUIMonitorBreak();
    virtual ~CUIMonitorBreak();

private:
    float m_Time;
    CUIImage* m_MonitorBreak;

public:
    virtual bool Init();
    virtual void Update(float DeltaTime);
    virtual void PostUpdate(float DeltaTime);
    virtual void Collision(float DeltaTime);
    virtual void Render(HDC hDC);

public:
    void Finsh();
};

