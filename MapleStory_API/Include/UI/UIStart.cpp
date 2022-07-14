#include "UIStart.h"
#include "Button.h"
#include "UIImage.h"
#include "../GameManager.h"
#include "../Scene/TutorialMap.h"
#include "../Scene/BossWillPase2.h"
#include "../Scene/Stage1.h"
#include "../Scene/EditorScene.h"
#include "../Scene/SceneManager.h"
#include "UIText.h"

CUIStart::CUIStart()
{
}

CUIStart::~CUIStart()
{
}

bool CUIStart::Init()
{
	CUIImage* Back = CreateWidget<CUIImage>("Back");

	Back->SetTexture("StartBack", TEXT("CustomizeChar.dualBlade.0.0.bmp"));

	CButton* Button = CreateWidget<CButton>("StartButton");

	Button->SetTexture("StartButton", TEXT("grey_button15.bmp"));
	Button->SetTextureColorKey(255, 0, 255);
	Button->SetPos(1024.f / 2.f - 100.f, 768.f / 2.f - 175.f);
	Button->SetZOrder(1);

	Button->SetClickCallback<CUIStart>(this, &CUIStart::StartClick);

	CUIText* Text = CreateWidget<CUIText>("StartButtonText");

	Text->SetText(TEXT("START"));
	Text->SetTextColor(100, 150, 200);
	Text->SetPos(1024.f / 2.f - 50.f, 768.f / 2.f - 155.f);
	Text->SetZOrder(2);

	Button = CreateWidget<CButton>("EditorButton");

	Button->SetTexture("StartButton", TEXT("grey_button15.bmp"));
	Button->SetTextureColorKey(255, 0, 255);
	Button->SetPos(1024.f / 2.f - 100.f, 768.f / 2.f - 50.f);
	Button->SetZOrder(1);

	Button->SetClickCallback<CUIStart>(this, &CUIStart::EditorClick);

	Text = CreateWidget<CUIText>("EditorButtonText");

	Text->SetText(TEXT("EDITOR"));
	Text->SetTextColor(100, 150, 200);
	Text->SetPos(1024.f / 2.f - 50.f, 768.f / 2.f - 30.f);
	Text->SetZOrder(2);

	Button = CreateWidget<CButton>("ExitButton");

	Button->SetTexture("StartButton", TEXT("grey_button15.bmp"));
	Button->SetTextureColorKey(255, 0, 255);
	Button->SetPos(1024.f / 2.f - 100.f, 768.f / 2.f + 75.f);
	Button->SetZOrder(1);

	Button->SetClickCallback<CUIStart>(this, &CUIStart::ExitClick);

	Text = CreateWidget<CUIText>("ExitButtonText");

	Text->SetText(TEXT("EXIT"));
	Text->SetTextColor(100, 150, 200);
	Text->SetPos(1024.f / 2.f - 50.f, 768.f / 2.f + 95.f);
	Text->SetZOrder(2);

	return true;
}

void CUIStart::StartClick()
{
	CSceneManager::GetInst()->CreateScene<CTutorialMap>("TutorialMap");
	//CSceneManager::GetInst()->CreateScene<CStage1>("Stage1");
	//CSceneManager::GetInst()->CreateScene<CBossWillPase2>("BossWillPase2");
}

void CUIStart::ExitClick()
{
	CGameManager::GetInst()->Exit();
}

void CUIStart::EditorClick()
{
	CSceneManager::GetInst()->CreateScene<CEditorScene>("EditorScene");
}
