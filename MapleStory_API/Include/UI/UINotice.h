#pragma once

#include "UIWindow.h"
#include "UIImage.h"

class CUINotice :
    public CUIWindow
{
    friend class CScene;

private:
    CUINotice();
    virtual ~CUINotice();

private:
    CSharedPtr<CUIImage> m_Notice;

public:
    virtual bool Init();
    virtual void Update(float DeltaTime);

public:
    void Finsh();
};

