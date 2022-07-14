#include "EditorScene.h"
#include "SceneResource.h"
#include "Camera.h"
#include "../UI/UIStart.h"
#include "../Input.h"
#include "EditorDlg.h"
#include "../Map/TileMap.h"
#include "../Map/ScrollMap.h"
#include "../GameManager.h"

CEditorScene::CEditorScene() : m_Dlg(nullptr), m_Start(false), m_TileMap(nullptr), m_ScroolSpeed(500.f)
{
	CGameManager::GetInst()->SetEditorMode(true);
}

CEditorScene::~CEditorScene()
{
	CGameManager::GetInst()->SetEditorMode(false);
	SAFE_DELETE(m_Dlg);
}

bool CEditorScene::Init()
{
	CScene::Init();

	LoadSound();

	LoadAnimationSequence();

	RECT rc = { 0, 0, 1366, 768 };

	HWND hWnd = CGameManager::GetInst()->GetWindowHandle();

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	SetWindowPos(hWnd, HWND_TOPMOST, 1920, 100, rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE);

	ShowWindow(hWnd, SW_SHOW);

	UpdateWindow(hWnd);

	m_Start = false;

	m_Dlg = new CEditorDlg;

	m_Dlg->SetScene(this);
	m_Dlg->Init(IDD_DIALOG_EDITOR);

	//CUIStart* StartWindow = CreateUIWindow<CUIStart>("StartWindow");

	return true;
}

bool CEditorScene::Update(float DeltaTime)
{
	CScene::Update(DeltaTime);

	if (!m_Start)
	{
		m_Start = true;

		CInput::GetInst()->SetCallback<CEditorScene>("Editor", KeyState_Down, this, &CEditorScene::OnEditor);

		CInput::GetInst()->SetCallback<CEditorScene>("MoveUp", KeyState_Push, this, &CEditorScene::CameraMoveUp);
		CInput::GetInst()->SetCallback<CEditorScene>("MoveDown", KeyState_Push, this, &CEditorScene::CameraMoveDown);
		CInput::GetInst()->SetCallback<CEditorScene>("MoveLeft", KeyState_Push, this, &CEditorScene::CameraMoveLeft);
		CInput::GetInst()->SetCallback<CEditorScene>("MoveRight", KeyState_Push, this, &CEditorScene::CameraMoveRight);

		CInput::GetInst()->SetCallback<CEditorScene>("MouseLButton", KeyState_Push, this, &CEditorScene::MouseLButton);
		CInput::GetInst()->SetCallback<CEditorScene>("MouseRButton", KeyState_Push, this, &CEditorScene::MouseRButton);
	}

	RECT rc = m_Dlg->GetRect();

	POINT ptMouse;
	GetCursorPos(&ptMouse);

	if (rc.left <= ptMouse.x && ptMouse.x <= rc.right && rc.top <= ptMouse.y && ptMouse.y <= rc.bottom)
	{
		if (!CInput::GetInst()->IsShowCursor())
		{
			CInput::GetInst()->SetShowCursor(true);
			ShowCursor(TRUE);
		}
	}

	else
	{
		if (CInput::GetInst()->IsShowCursor())
		{
			CInput::GetInst()->SetShowCursor(false);
			ShowCursor(FALSE);
		}
	}

	return false;
}

bool CEditorScene::PostUpdate(float DeltaTime)
{
	CScene::PostUpdate(DeltaTime);

	return false;
}

void CEditorScene::LoadAnimationSequence()
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

void CEditorScene::LoadSound()
{
	GetSceneResource()->LoadSound("UI", false, "ButtonMouseOn", "TeemoSmile.mp3");
	GetSceneResource()->LoadSound("UI", false, "ButtonClick", "TeemoStartClicck.mp3");

	GetSceneResource()->SetVolume("UI", 30);
}

void CEditorScene::OnEditor(float DeltaTiem)
{

}

void CEditorScene::CreateTileMap()
{
	if (m_TileMap)
	{
		return;
	}

	m_TileMap = CreateMap<CTileMap>("TileMap");
	m_TileMap->SetZOrder(3);
}

void CEditorScene::SetTileInfo(int CountX, int CountY, int SizeX, int SizeY)
{
	m_TileMap->CreateTile(CountX, CountY, Vector2((float)SizeX, (float)SizeY));
}

void CEditorScene::SetTileTexture(CTexture* Texture)
{
	m_TileMap->SetTileTexture(Texture);
}

void CEditorScene::CreateBack()
{
	if (m_ScrolMap)
	{
		return;
	}

	m_ScrolMap = CreateMap<CScrollMap>("ScrollMap");
	m_ScrolMap->SetZOrder(1);
}

void CEditorScene::SetBackInfo(int SizeX, int SizeY)
{
	m_ScrolMap->SetSize((float)SizeX, (float)SizeY);
}

void CEditorScene::SetBackTexture(std::string MapName, std::string TextureName)
{
	TCHAR str[256] = L"";

	size_t Size = 0;
	size_t conSize = 0;

	Size = strlen(TextureName.c_str()) + 1;

	mbstowcs_s(&conSize, str, Size, TextureName.c_str(), _TRUNCATE);

	m_ScrolMap->SetTexture(MapName, str);
}

void CEditorScene::CameraMoveUp(float DeltaTime)
{
	CCamera* Camera = GetCamera();

	Camera->Move(Vector2(0.f, -1.f) * m_ScroolSpeed * DeltaTime);
}

void CEditorScene::CameraMoveDown(float DeltaTime)
{
	CCamera* Camera = GetCamera();

	Camera->Move(Vector2(0.f, 1.f) * m_ScroolSpeed * DeltaTime);
}

void CEditorScene::CameraMoveLeft(float DeltaTime)
{
	CCamera* Camera = GetCamera();

	Camera->Move(Vector2(-1.f, 0.f) * m_ScroolSpeed * DeltaTime);
}

void CEditorScene::CameraMoveRight(float DeltaTime)
{
	CCamera* Camera = GetCamera();

	Camera->Move(Vector2(1.f, 0.f) * m_ScroolSpeed * DeltaTime);
}

void CEditorScene::MouseLButton(float DeltaTime)
{
	if (!m_TileMap)
	{
		return;
	}

	Vector2 MousePos = CInput::GetInst()->GetMousePos();

	CCamera* Camera = GetCamera();

	if (MousePos.x < 0.f || MousePos.x > Camera->GetResolution().x || MousePos.y < 0.f || MousePos.y > Camera->GetResolution().y)
	{
		return;
	}

	ETileEditMode EditMode = m_Dlg->GetTileEditMode();

	MousePos += Camera->GetPos();

	switch (EditMode)
	{
	case ETileEditMode::Option:
	{
		ETileOption Option = m_Dlg->GetTileOption();

		m_TileMap->ChangeTileOption(MousePos, Option);

		m_TileMap->ChangeTileSideCollision(MousePos, m_Dlg->GetSideCollision());
	}
	break;

	case ETileEditMode::Image:
	{
		TileFrmaeData FrameData = m_Dlg->GetTileFrameData();

		m_TileMap->SetTileFrmae(MousePos, FrameData.Start, FrameData.End);
	}
	break;
	}
}

void CEditorScene::MouseRButton(float DeltaTime)
{
	if (!m_TileMap)
	{
		return;
	}

	Vector2 MousePos = CInput::GetInst()->GetMousePos();

	CCamera* Camera = GetCamera();

	if (MousePos.x < 0.f || MousePos.x > Camera->GetResolution().x || MousePos.y < 0.f || MousePos.y > Camera->GetResolution().y)
	{
		return;
	}

	ETileEditMode EditMode = m_Dlg->GetTileEditMode();

	MousePos += Camera->GetPos();

	switch (EditMode)
	{
	case ETileEditMode::Option:
	{
		m_TileMap->ChangeTileOption(MousePos, ETileOption::Normal);
	}
	break;
	case ETileEditMode::Image:
	{
		m_TileMap->SetTileTexture(MousePos, nullptr);
	}
	break;
	}
}

void CEditorScene::Save(const char* FullPath)
{
	if (!m_TileMap)
	{
		MessageBox(0, TEXT("맵을 생성하세요"), TEXT("Error"), MB_OK);
		return;
	}

	m_TileMap->SaveFullPath(FullPath);
}

void CEditorScene::Load(const char* FullPath)
{
	if (!m_TileMap)
	{
		m_TileMap = CreateMap<CTileMap>("TileMap");
	}

	m_TileMap->LoadFullPath(FullPath);
}

void CEditorScene::TileImageAllClear()
{
	if (!m_TileMap)
	{
		return;
	}

	m_TileMap->TileImageAllClear();
}
