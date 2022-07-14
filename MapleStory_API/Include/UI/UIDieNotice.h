#pragma once

#include "UIWindow.h"

class CUIDieNotice :
    public CUIWindow
{
    friend class CScene;

private:
    CUIDieNotice();
    virtual ~CUIDieNotice();

public:
    virtual bool Init();

public:
    void OKClick();
};

