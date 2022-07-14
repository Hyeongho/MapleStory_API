#pragma once

#include "UIWindow.h"

class CUITutorial :
    public CUIWindow
{
    friend class CScene;

private:
    CUITutorial();
    virtual ~CUITutorial();

public:
    virtual bool Init();
};

