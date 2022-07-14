#include "UITutorial.h"
#include "UIImage.h"
#include "../GameManager.h"
#include "../Scene/TutorialMap.h"
#include "../Scene/SceneManager.h"
#include "UIText.h"

CUITutorial::CUITutorial()
{
}

CUITutorial::~CUITutorial()
{
}

bool CUITutorial::Init()
{
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	SetZOrder(2);

	SetPos(RS.Width - 350.f, RS.Height - 83.f);

	CUIImage* QuickSlot = CreateWidget<CUIImage>("QuickSlot");

	QuickSlot->SetTexture("QuickSlot", TEXT("QuickSlot.bmp"));

	QuickSlot->SetTextureColorKey(255, 0, 255);

	return true;
}
