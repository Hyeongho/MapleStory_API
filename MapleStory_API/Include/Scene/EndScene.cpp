#include "EndScene.h"
#include "Stage1.h"
#include "../GameManager.h"
#include "../Object/GameObjectManager.h"
#include "../Object/Player.h"
#include "../Object/PhantomBlow.h"
#include "../Object/BladeFury.h"
#include "../Object/Aranea.h"
#include "../Object/Aranya.h"
#include "../Object/Potal.h"
#include "SceneResource.h"
#include "SceneManager.h"
#include "Camera.h"
#include "../UI/UITutorial.h"
#include "../UI/UICharacterStateHUD.h"
#include "../UI/UIClear.h"
#include "../Map/ScrollMap.h"
#include "../Map/TileMap.h"

CEndScene::CEndScene()
{
}

CEndScene::~CEndScene()
{
}

bool CEndScene::Init()
{
	CUIClear* ClearUI = CreateUIWindow<CUIClear>("Clear");

	return true;
}

bool CEndScene::Update(float DeltaTime)
{
	CScene::Update(DeltaTime);

	return true;
}

bool CEndScene::PostUpdate(float DeltaTime)
{
	CScene::PostUpdate(DeltaTime);

	return true;
}

bool CEndScene::Collision(float DeltaTime)
{
	CScene::Collision(DeltaTime);

	return true;
}

bool CEndScene::Render(HDC hDC)
{
	CScene::Render(hDC);

	return true;
}

void CEndScene::LoadAnimationSequence()
{
	// Player
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

	// Player 이펙트
	GetSceneResource()->CreateAnimationSequence("RightPhantomBlow", "RightPhantomBlow", TEXT("Player/Effect/R/PhantomBlow.bmp"));

	GetSceneResource()->SetTextureColorKey("RightPhantomBlow", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("LeftPhantomBlow", "LeftPhantomBlow", TEXT("Player/Effect/L/PhantomBlow.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftPhantomBlow", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("BladeFury", "BladeFury", TEXT("Player/Effect/BladeFury.bmp"));

	GetSceneResource()->SetTextureColorKey("BladeFury", 255, 0, 255);

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

	GetSceneResource()->CreateAnimationSequence("PlayerRightDead", "PlayerRightDead", TEXT("Player/R/Dead.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightDead", 255, 0, 255);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftDead", "PlayerLeftDead", TEXT("Player/L/Dead.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftDead", 255, 0, 255);

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
}

void CEndScene::LoadSound()
{
}
