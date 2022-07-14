#include "TutorialMap.h"
#include "../GameManager.h"
#include "../Object/Player.h"
#include "../Object/PhantomBlow.h"
#include "../Object/BladeFury.h"
#include "../Object/ShadowBlade.h"
#include "../Object/Potal.h"
#include "SceneResource.h"
#include "Camera.h"
#include "../UI/UITutorial.h"
#include "../UI/UICharacterStateHUD.h"
#include "../UI/UIDieNotice.h"
#include "../Map/ScrollMap.h"
#include "../Map/TileMap.h"

CTutorialMap::CTutorialMap()
{
}

CTutorialMap::~CTutorialMap()
{
}

bool CTutorialMap::Init()
{
	LoadAnimationSequence();

	LoadSound();

	GetCamera()->SetWorldResolution(1598.f, 800.f);

	RECT rc = { 0, 0, 1366, 768 };

	HWND hWnd = CGameManager::GetInst()->GetWindowHandle();

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	SetWindowPos(hWnd, HWND_TOPMOST, 1920, 100, rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE);

	ShowWindow(hWnd, SW_SHOW);

	UpdateWindow(hWnd);

	CPhantomBlow* RightPhantomBlow = CreatePrototype<CPhantomBlow>("RightPhantomBlow", false);
	CPhantomBlow* LeftPhantomBlow = CreatePrototype<CPhantomBlow>("LeftPhantomBlow", true);

	CBladeFury* BladeFury = CreatePrototype<CBladeFury>("BladeFury", false);

	CPlayer* Player = CreateObject<CPlayer>("Player", Vector2(100.f, 650.f));

	SetPlayer(Player);

	GetCamera()->SetTarget(Player);
	GetCamera()->SetTargetPivot(0.5f, 0.5f);

	CShadowBlade* ShadowBlade = CreateObject<CShadowBlade>("Monster", Vector2(1000.f, 650.f));

	CPotal* Potal = CreateObject<CPotal>("TutoMain", Vector2(1360.f, 508.f));

	CScrollMap* Map = CreateMap<CScrollMap>("TutorialMap");
	Map->SetSize(1598.f, 800.f);
	Map->SetTexture("TutorialMap", TEXT("20210928211449847_103050530.bmp"));
	Map->SetLoop(false);
	Map->SetScrollRatio(1.0f, 1.0f);
	Map->SetZOrder(0);

	Player->SetRange(1598.f, 800.f);
	ShadowBlade->SetRange(1598.f, 800.f);

	CTileMap* TileMap = CreateMap<CTileMap>("TutorialMap", Vector2(0.f, 0.f), Vector2(1598.f, 800.f));

	TileMap->LoadFile("TutorialMap");
	TileMap->SetZOrder(2);

	CUITutorial* TutorialWindow = CreateUIWindow<CUITutorial>("TutorialWindow");

	m_DieNotice = CreateUIWindow<CUIDieNotice>("DieNotice");

	CUICharacterStateHUD* StateWindow = CreateUIWindow<CUICharacterStateHUD>("CharacterStateHUD");

	return true;
}

bool CTutorialMap::Update(float DeltaTime)
{
	CScene::Update(DeltaTime);

	if (CPlayer::m_IsDie)
	{
		if (!m_DieNotice->GetVisibility())
		{
			m_DieNotice->SetVisibility(true);
		}
	}

	return true;
}

void CTutorialMap::LoadAnimationSequence()
{
	// Player 애니메이션
	GetSceneResource()->CreateAnimationSequence("PlayerRightIdle", "PlayerRightIdle", TEXT("Player/R/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightIdle", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftIdle", "PlayerLeftIdle", TEXT("Player/L/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftIdle", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftWalk", "PlayerLeftWalk", TEXT("Player/L/walk.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftWalk", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerRightWalk", "PlayerRightWalk", TEXT("Player/R/walk.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightWalk", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftAttack", "PlayerLeftAttack", TEXT("Player/L/stabD1.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftAttack", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerRightAttack", "PlayerRightAttack", TEXT("Player/R/stabD1.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightAttack", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftPhantomBlow", "PlayerLeftPhantomBlow", TEXT("Player/L/phantomBlow.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftPhantomBlow", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerRightPhantomBlow", "PlayerRightPhantomBlow", TEXT("Player/R/phatomBlow.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightPhantomBlow", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerRightBladeFury", "PlayerRightBladeFury", TEXT("Player/R/BladeFury.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightBladeFury", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftBladeFury", "PlayerLeftBladeFury", TEXT("Player/L/bladeFury.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftBladeFury", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerRightDead", "PlayerRightDead", TEXT("Player/R/Dead.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightDead", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftDead", "PlayerLeftDead", TEXT("Player/L/Dead.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftDead", 255, 0, 255);

	// Player 이펙트
	GetSceneResource()->CreateAnimationSequence("RightPhantomBlow", "RightPhantomBlow", TEXT("Player/Effect/R/PhantomBlow.bmp"));

	GetSceneResource()->SetTextureColorKey("RightPhantomBlow", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftPhantomBlow", "LeftPhantomBlow", TEXT("Player/Effect/L/PhantomBlow.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftPhantomBlow", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("BladeFury", "BladeFury", TEXT("Player/Effect/BladeFury.bmp"));

	GetSceneResource()->SetTextureColorKey("BladeFury", 255, 0, 255);

	// Monster 애니메이션
	GetSceneResource()->CreateAnimationSequence("RightShadowBladeStand", "RightShadowBladeStand", TEXT("Monster/ShadowBlade/Stand/R/Stand.bmp"));

	GetSceneResource()->SetTextureColorKey("RightShadowBladeStand", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftShadowBladeStand", "LeftShadowBladeStand", TEXT("Monster/ShadowBlade/Stand/L/Stand.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftShadowBladeStand", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightShadowBladeMove", "RightShadowBladeMove", TEXT("Monster/ShadowBlade/Move/R/Move.bmp"));

	GetSceneResource()->SetTextureColorKey("RightShadowBladeMove", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftShadowBladeMove", "LeftShadowBladeMove", TEXT("Monster/ShadowBlade/Move/L/Move.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftShadowBladeMove", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightShadowBladeAttack", "RightShadowBladeAttack", TEXT("Monster/ShadowBlade/Attack/R/Attack.bmp"));

	GetSceneResource()->SetTextureColorKey("RightShadowBladeAttack", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftShadowBladeAttack", "LeftShadowBladeAttack", TEXT("Monster/ShadowBlade/Attack/L/Attack.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftShadowBladeAttack", 255, 0, 255);

	// 아라냐
	GetSceneResource()->CreateAnimationSequence("RightAranyaStand", "RightAranyaStand", TEXT("Monster/Aranya/stand/R/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAranyaStand", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftAranyaStand", "LeftAranyaStand", TEXT("Monster/Aranya/stand/L/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAranyaStand", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightAranyaMove", "RightAranyaMove", TEXT("Monster/Aranya/move/R/move.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAranyaMove", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftAranyaMove", "LeftAranyaMove", TEXT("Monster/Aranya/move/L/move.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAranyaMove", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightAranyaAttack", "RightAranyaAttack", TEXT("Monster/Aranya/attack1/R/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAranyaAttack", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftAranyaAttack", "LeftAranyaAttack", TEXT("Monster/Aranya/attack1/L/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAranyaAttack", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightAranyaDie", "RightAranyaDie", TEXT("Monster/Aranya/die/R/die.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAranyaDie", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftAranyaDie", "LeftAranyaDie", TEXT("Monster/Aranya/die/L/die.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAranyaDie", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("AranyaEffect", "AranyaEffect", TEXT("Monster/Aranya/hit/L/hit.bmp"));

	GetSceneResource()->SetTextureColorKey("AranyaEffect", 255, 0, 255);

	// 아라네아
	GetSceneResource()->CreateAnimationSequence("RightAraneaStand", "RightAraneaStand", TEXT("Monster/Aranea/stand/R/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAraneaStand", 255, 0, 0);

	GetSceneResource()->CreateAnimationSequence("LeftAraneaStand", "LeftAraneaStand", TEXT("Monster/Aranea/stand/L/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAraneaStand", 255, 0, 0);

	GetSceneResource()->CreateAnimationSequence("RightAraneaMove", "RightAraneaMove", TEXT("Monster/Aranea/move/R/move.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAraneaMove", 255, 0, 0);

	GetSceneResource()->CreateAnimationSequence("LeftAraneaMove", "LeftAraneaMove", TEXT("Monster/Aranea/move/L/move.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAraneaMove", 255, 0, 0);

	GetSceneResource()->CreateAnimationSequence("RightAraneaAttack", "RightAraneaAttack", TEXT("Monster/Aranea/attack1/R/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAraneaAttack", 255, 0, 0);

	GetSceneResource()->CreateAnimationSequence("LeftAraneaAttack", "LeftAraneaAttack", TEXT("Monster/Aranea/attack1/L/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAraneaAttack", 255, 0, 0);

	GetSceneResource()->CreateAnimationSequence("RightAraneaDie", "RightAraneaDie", TEXT("Monster/Aranea/die/R/die.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAraneaDie", 255, 0, 0);

	GetSceneResource()->CreateAnimationSequence("LeftAraneaDie", "LeftAraneaDie", TEXT("Monster/Aranea/die/L/die.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAraneaDie", 255, 0, 0);

	GetSceneResource()->CreateAnimationSequence("AraneaEffect", "AraneaEffect", TEXT("Monster/Aranea/hit/L/hit.bmp"));

	GetSceneResource()->SetTextureColorKey("AraneaEffect", 255, 0, 0);

	//보스 몬스터
	GetSceneResource()->CreateAnimationSequence("RightWill", "RightWill", TEXT("Will/2/stand/R/Stand.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWill", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftWill", "LeftWill", TEXT("Will/2/stand/L/Stand.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWill", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightWillMove", "RightWillMove", TEXT("Will/2/move/R/Move.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillMove", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftWillMove", "LeftWillMove", TEXT("Will/2/move/L/Move.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillMove", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightWillAttack1", "RightWillAttack1", TEXT("Will/2/attack1/R/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack1", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack1", "LeftWillAttack1", TEXT("Will/2/attack1/L/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack1", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightWillAttack2", "RightWillAttack2", TEXT("Will/2/attack2/R/attack2.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack2", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack2", "LeftWillAttack2", TEXT("Will/2/attack2/L/attack2.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack2", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightWillAttack3", "RightWillAttack3", TEXT("Will/2/attack3/R/attack3.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack3", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack3", "LeftWillAttack3", TEXT("Will/2/attack3/L/attack3.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack3", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightWillAttack4", "RightWillAttack4", TEXT("Will/2/attack4/R/attack4.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack4", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack4", "LeftWillAttack4", TEXT("Will/2/attack4/L/attack4.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack4", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightWillAttack5", "RightWillAttack5", TEXT("Will/2/attack5/R/attack5.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack5", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack5", "LeftWillAttack5", TEXT("Will/2/attack5/L/attack5.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack5", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightWillAttack6", "RightWillAttack6", TEXT("Will/2/attack6/R/attack6.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack6", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack6", "LeftWillAttack6", TEXT("Will/2/attack6/L/attack6.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack6", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightWillAttack7", "RightWillAttack7", TEXT("Will/2/attack7/R/attack7.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack7", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack7", "LeftWillAttack7", TEXT("Will/2/attack7/L/attack7.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack7", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightWillHit", "RightWillHit", TEXT("Will/2/Hit/R/Hit.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillHit", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftWillHit", "LeftWillHit", TEXT("Will/2/Hit/L/Hit.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillHit", 255, 0, 255);

	// 윌 Hit Effect
	GetSceneResource()->CreateAnimationSequence("HitEffect", "HitEffect", TEXT("Will/HitEffect/Hit_Effect1_2.bmp"));

	GetSceneResource()->SetTextureColorKey("HitEffect", 255, 0, 255);

	// 보스몬스터 피격 이펙트
	GetSceneResource()->CreateAnimationSequence("AttackEffect1", "AttackEffect1", TEXT("Will/2/attack1/Effect/attackeffect.bmp"));

	GetSceneResource()->SetTextureColorKey("AttackEffect1", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftAttackEffect2", "LeftAttackEffect2", TEXT("Will/2/attack2/Effect/L/attack2effect.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAttackEffect2", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("RightAttackEffect2", "RightAttackEffect2", TEXT("Will/2/attack2/Effect/R/attack2effect.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAttackEffect2", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("AttackEffect4", "AttackEffect4", TEXT("Will/2/attack4/Effect/attack4effect.bmp"));

	GetSceneResource()->SetTextureColorKey("AttackEffect4", 255, 0, 0);

	// 맵 패턴
	GetSceneResource()->CreateAnimationSequence("UpSpiderLeg", "UpSpiderLeg", TEXT("Will/2/Effect/level0_4.bmp"));

	GetSceneResource()->SetTextureColorKey("UpSpiderLeg", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("DownSpiderLeg", "DownSpiderLeg", TEXT("Will/2/Effect/Strip 4.bmp"));

	GetSceneResource()->SetTextureColorKey("DownSpiderLeg", 0, 0, 0);

	GetSceneResource()->CreateAnimationSequence("Crack", "Crack", TEXT("Will/2/Effect/tile.bmp"));

	GetSceneResource()->SetTextureColorKey("Crack", 255, 0, 255);

	// 포탈
	GetSceneResource()->CreateAnimationSequence("Potal", "Potal", TEXT("Potal.bmp"));

	GetSceneResource()->SetTextureColorKey("Potal", 255, 0, 255);
}

void CTutorialMap::LoadSound()
{
	GetSceneResource()->LoadSound("BGM", true, "BGM", "secretFlower.mp3");

	GetSceneResource()->LoadSound("Effect", false, "PhantomBLow", "Player/PhantomBLow/Use.wav");
	GetSceneResource()->LoadSound("Effect", false, "BladeFury", "Player/BladeFury/Use.wav");
}
