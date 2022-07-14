#pragma once

#include "UIWindow.h"
#include "ProgressBar.h"
#include "Button.h"
#include "UIImage.h"

class CUIBossWillPase2 :
    public CUIWindow
{
    friend class CScene;

private:
    CUIBossWillPase2();
    virtual ~CUIBossWillPase2();

private:
    CSharedPtr<CProgressBar> m_HPBar1;
    CSharedPtr<CProgressBar> m_HPBar2;
    CSharedPtr<CProgressBar> m_HPBar3;

public:
    void SetHPPercent1(float Percent)
    {
        m_HPBar1->SetPercent(Percent);
    }

    void SetHPPercent2(float Percent)
    {
        m_HPBar2->SetPercent(Percent);
    }

    void SetHPPercent3(float Percent)
    {
        m_HPBar3->SetPercent(Percent);
    }

public:
    virtual bool Init();
};

