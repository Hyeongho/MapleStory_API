#pragma once

#include "UIWindow.h"

class CUIDeathCount :
    public CUIWindow
{
	friend class CScene;

private:
	CUIDeathCount();
	virtual ~CUIDeathCount();

private:
	class CNumberWidget* m_NumberWidget;
	class CNumberWidget* m_Number1Widget;

public:
	virtual bool Init();
	virtual void Update(float DeltaTime);
};

