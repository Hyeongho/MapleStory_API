#include "MainScene.h"
#include "../Object/Player.h"
#include "SceneResource.h"
#include "Camera.h"
#include "../UI/UIMain.h"
#include "../UI/UIImage.h"
#include "../UI/UICharacterStateHUD.h"
#include "../Map/ScrollMap.h"
#include "../Map/TileMap.h"

CMainScene::CMainScene()
{
}

CMainScene::~CMainScene()
{
}

bool CMainScene::Init()
{
	LoadSound();

	LoadAnimationSequence();

	GetCamera()->SetWorldResolution(10000.f, 10000.f);

	CPlayer* Player = CreateObject<CPlayer>("Player", Vector2(1000.f, 300.f));

	SetPlayer(Player);

	GetCamera()->SetTarget(Player);
	GetCamera()->SetTargetPivot(0.5f, 0.5f);

	/*CUIWindow* TestWindow = CreateUIWindow<CUIWindow>("TestWindow");

	CUIImage* Image = TestWindow->CreateWidget<CUIImage>("TestImage");

	Image->SetTexture("Test", TEXT("teemo.bmp"));
	Image->SetPos(100.f, 100.f);
	Image->SetZOrder(1);

	CUIImage* Image1 = TestWindow->CreateWidget<CUIImage>("TestImage1");

	Image1->SetTexture("Test1", TEXT("Start.bmp"));
	Image1->SetPos(150.f, 100.f);*/

	GetCamera()->SetWorldResolution(3000.f, 1200.f);
	//GetCamera()->SetWorldResolution(30000.f, 12000.f);

	//float ScrollWidth = 1500.f - GetCamera()->GetResolution().x;
	//float ScrollHeight = 1200.f - GetCamera()->GetResolution().y;

	//float TileMapWidth = 3000.f - GetCamera()->GetResolution().x;
	//float TileMapHeight = 1200.f - GetCamera()->GetResolution().y;

	//CScrollMap* Map = CreateMap<CScrollMap>("ScrollMap");
	//Map->SetSize(1280.f, 720.f);
	//Map->SetTexture("ScrollBack", TEXT("Sky.bmp"));
	//Map->SetLoop(true);
	////Map->SetScrollRatio(ScrollWidth / TileMapWidth, ScrollHeight / TileMapHeight);
	//Map->SetZOrder(0);

	CUIMain* MainWindow = CreateUIWindow<CUIMain>("MainWindow");

	return true;
}

void CMainScene::LoadAnimationSequence()
{
	GetSceneResource()->CreateAnimationSequence("PlayerRightIdle", "PlayerRightIdle", TEXT("Player/R/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightIdle", 255, 0, 255);

	for (int i = 0; i < 3; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerRightIdle", i * 72.f, 0.f, 72.f, 71.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerRightWalk", "PlayerRightWalk", TEXT("Player/R/walk.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightWalk", 255, 0, 255);

	for (int i = 0; i < 4; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerRightWalk", i * 75.f, 0.f, 75.f, 71.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerRightAttack", "PlayerRightWalk", TEXT("Player/R/stabD1.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightAttack", 255, 0, 255);

	for (int i = 0; i < 4; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerRightAttack", i * 107.f, 0.f, 107.f, 68.f);
	}
}

void CMainScene::LoadSound()
{

}
