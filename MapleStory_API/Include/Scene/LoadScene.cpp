#include "LoadScene.h"
#include "SceneResource.h"
#include "SceneManager.h"
#include "StartScene.h"
#include "BossWillPase2.h"

CLoadScene::CLoadScene()
{
}

CLoadScene::~CLoadScene()
{
}

bool CLoadScene::Init()
{
	LoadAnimationSequence();

	return true;
}

bool CLoadScene::Update(float DeltaTime)
{
	CScene::Update(DeltaTime);

	CSceneManager::GetInst()->CreateScene<CStartScene>();
	//CSceneManager::GetInst()->CreateScene<CBossWillPase2>("BossWillPase2");

	return true;
}

bool CLoadScene::PostUpdate(float DeltaTime)
{
	CScene::PostUpdate(DeltaTime);

	return true;
}

bool CLoadScene::Collision(float DeltaTime)
{
	CScene::Collision(DeltaTime);

	return true;
}

bool CLoadScene::Render(HDC hDC)
{
	CScene::Render(hDC);

	return true;
}

void CLoadScene::LoadAnimationSequence()
{
	// Player
	GetSceneResource()->CreateAnimationSequence("PlayerRightIdle", "PlayerRightIdle", TEXT("Player/R/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightIdle", 255, 0, 255);

	for (int i = 0; i < 3; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerRightIdle", i * 72.f, 0.f, 72.f, 71.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerLeftIdle", "PlayerLeftIdle", TEXT("Player/L/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftIdle", 255, 0, 255);

	for (int i = 0; i < 3; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerLeftIdle", i * 72.f, 0.f, 72.f, 71.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerLeftWalk", "PlayerLeftWalk", TEXT("Player/L/walk.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftWalk", 255, 0, 255);

	for (int i = 0; i < 4; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerLeftWalk", i * 75.f, 0.f, 75.f, 71.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerRightWalk", "PlayerRightWalk", TEXT("Player/R/walk.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightWalk", 255, 0, 255);

	for (int i = 0; i < 4; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerRightWalk", i * 75.f, 0.f, 75.f, 71.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerLeftAttack", "PlayerLeftAttack", TEXT("Player/L/stabD1.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftAttack", 255, 0, 255);

	for (int i = 0; i < 4; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerLeftAttack", i * 107.f, 0.f, 107.f, 68.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerRightAttack", "PlayerRightAttack", TEXT("Player/R/stabD1.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightAttack", 255, 0, 255);

	for (int i = 0; i < 4; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerRightAttack", i * 107.f, 0.f, 107.f, 68.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerLeftPhantomBlow", "PlayerLeftPhantomBlow", TEXT("Player/L/phantomBlow.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftPhantomBlow", 255, 0, 255);

	for (int i = 0; i < 9; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerLeftPhantomBlow", i * 114.f, 0.f, 114.f, 81.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerRightPhantomBlow", "PlayerRightPhantomBlow", TEXT("Player/R/phatomBlow.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightPhantomBlow", 255, 0, 255);

	for (int i = 0; i < 9; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerRightPhantomBlow", i * 114.f, 0.f, 114.f, 81.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerRightBladeFury", "PlayerRightBladeFury", TEXT("Player/R/BladeFury.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightBladeFury", 255, 0, 255);

	for (int i = 0; i < 10; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerRightBladeFury", i * 109.f, 0.f, 109.f, 161.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerLeftBladeFury", "PlayerLeftBladeFury", TEXT("Player/L/bladeFury.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftBladeFury", 255, 0, 255);

	for (int i = 0; i < 10; i++)
	{
		GetSceneResource()->AddAnimationFrameData("PlayerLeftBladeFury", i * 109.f, 0.f, 109.f, 161.f);
	}

	GetSceneResource()->CreateAnimationSequence("PlayerRightDead", "PlayerRightDead", TEXT("Player/R/Dead.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerRightDead", 255, 0, 255);

	GetSceneResource()->AddAnimationFrameData("PlayerRightDead", 0.f, 0.f, 43.f, 67.f);

	GetSceneResource()->CreateAnimationSequence("PlayerLeftDead", "PlayerLeftDead", TEXT("Player/L/Dead.bmp"));

	GetSceneResource()->SetTextureColorKey("PlayerLeftDead", 255, 0, 255);

	GetSceneResource()->AddAnimationFrameData("PlayerLeftDead", 0.f, 0.f, 43.f, 67.f);

	// Player 이펙트
	GetSceneResource()->CreateAnimationSequence("RightPhantomBlow", "RightPhantomBlow", TEXT("Player/Effect/R/PhantomBlow.bmp"));

	GetSceneResource()->SetTextureColorKey("RightPhantomBlow", 255, 0, 255);

	for (int i = 0; i < 10; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightPhantomBlow", i * 412.f, 0.f, 412.f, 210.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftPhantomBlow", "LeftPhantomBlow", TEXT("Player/Effect/L/PhantomBlow.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftPhantomBlow", 255, 0, 255);

	for (int i = 0; i < 10; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftPhantomBlow", i * 412.f, 0.f, 412.f, 210.f);
	}

	GetSceneResource()->CreateAnimationSequence("BladeFury", "BladeFury", TEXT("Player/Effect/BladeFury.bmp"));

	GetSceneResource()->SetTextureColorKey("BladeFury", 255, 0, 255);

	for (int i = 0; i < 8; i++)
	{
		GetSceneResource()->AddAnimationFrameData("BladeFury", i * 469.f, 0.f, 469.f, 195.f);
	}

	// Monster 애니메이션
	GetSceneResource()->CreateAnimationSequence("RightShadowBladeStand", "RightShadowBladeStand", TEXT("Monster/ShadowBlade/Stand/R/Stand.bmp"));

	GetSceneResource()->SetTextureColorKey("RightShadowBladeStand", 255, 0, 255);

	for (int i = 0; i < 4; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightShadowBladeStand", i * 65.f, 0.f, 65.f, 67.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftShadowBladeStand", "LeftShadowBladeStand", TEXT("Monster/ShadowBlade/Stand/L/Stand.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftShadowBladeStand", 255, 0, 255);

	for (int i = 0; i < 4; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftShadowBladeStand", i * 65.f, 0.f, 65.f, 67.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightShadowBladeMove", "RightShadowBladeMove", TEXT("Monster/ShadowBlade/Move/R/Move.bmp"));

	GetSceneResource()->SetTextureColorKey("RightShadowBladeMove", 255, 0, 255);

	for (int i = 0; i < 6; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightShadowBladeMove", i * 64.f, 0.f, 64.f, 63.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftShadowBladeMove", "LeftShadowBladeMove", TEXT("Monster/ShadowBlade/Move/L/Move.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftShadowBladeMove", 255, 0, 255);

	for (int i = 0; i < 6; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftShadowBladeMove", i * 64.f, 0.f, 64.f, 63.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightShadowBladeAttack", "RightShadowBladeAttack", TEXT("Monster/ShadowBlade/Attack/R/Attack.bmp"));

	GetSceneResource()->SetTextureColorKey("RightShadowBladeAttack", 255, 0, 255);

	for (int i = 0; i < 9; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightShadowBladeAttack", i * 153.f, 0.f, 153.f, 137.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftShadowBladeAttack", "LeftShadowBladeAttack", TEXT("Monster/ShadowBlade/Attack/L/Attack.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftShadowBladeAttack", 255, 0, 255);

	for (int i = 0; i < 9; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftShadowBladeAttack", i * 153.f, 0.f, 153.f, 137.f);
	}

	// 포탈
	GetSceneResource()->CreateAnimationSequence("Potal", "Potal", TEXT("Potal.bmp"));

	GetSceneResource()->SetTextureColorKey("Potal", 255, 0, 255);

	for (int i = 0; i < 8; i++)
	{
		GetSceneResource()->AddAnimationFrameData("Potal", i * 104.f, 0.f, 104.f, 142.f);
	}

	//보스 몬스터
	GetSceneResource()->CreateAnimationSequence("RightWill", "RightWill", TEXT("Will/2/stand/R/Stand.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWill", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightWill", i * 203.f, 0.f, 203.f, 365.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftWill", "LeftWill", TEXT("Will/2/stand/L/Stand.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWill", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftWill", i * 203.f, 0.f, 203.f, 365.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightWillMove", "RightWillMove", TEXT("Will/2/move/R/Move.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillMove", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightWillMove", i * 203.f, 0.f, 203.f, 364.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftWillMove", "LeftWillMove", TEXT("Will/2/move/L/Move.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillMove", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftWillMove", i * 203.f, 0.f, 203.f, 364.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightWillAttack1", "RightWillAttack1", TEXT("Will/2/attack1/R/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack1", 255, 0, 255);

	for (int i = 0; i < 20; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightWillAttack1", i * 593.f, 0.f, 593.f, 534.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack1", "LeftWillAttack1", TEXT("Will/2/attack1/L/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack1", 255, 0, 255);

	for (int i = 0; i < 20; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftWillAttack1", i * 593.f, 0.f, 593.f, 534.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightWillAttack2", "RightWillAttack2", TEXT("Will/2/attack2/R/attack2.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack2", 255, 0, 255);

	for (int i = 0; i < 20; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightWillAttack2", i * 728.f, 0.f, 728.f, 516.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack2", "LeftWillAttack2", TEXT("Will/2/attack2/L/attack2.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack2", 255, 0, 255);

	for (int i = 0; i < 20; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftWillAttack2", i * 728.f, 0.f, 728.f, 516.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightWillAttack3", "RightWillAttack3", TEXT("Will/2/attack3/R/attack3.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack3", 255, 0, 255);

	for (int i = 0; i < 20; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightWillAttack3", i * 860.f, 0.f, 860.f, 444.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack3", "LeftWillAttack3", TEXT("Will/2/attack3/L/attack3.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack3", 255, 0, 255);

	for (int i = 0; i < 20; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftWillAttack3", i * 860.f, 0.f, 860.f, 444.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightWillAttack4", "RightWillAttack4", TEXT("Will/2/attack4/R/attack4.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack4", 255, 0, 255);

	for (int i = 0; i < 30; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightWillAttack4", i * 622.f, 0.f, 622.f, 589.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack4", "LeftWillAttack4", TEXT("Will/2/attack4/L/attack4.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack4", 255, 0, 255);

	for (int i = 0; i < 30; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftWillAttack4", i * 622.f, 0.f, 622.f, 589.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightWillAttack5", "RightWillAttack5", TEXT("Will/2/attack5/R/attack5.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack5", 255, 0, 255);

	for (int i = 0; i < 20; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightWillAttack5", i * 665.f, 0.f, 655.f, 499.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack5", "LeftWillAttack5", TEXT("Will/2/attack5/L/attack5.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack5", 255, 0, 255);

	for (int i = 0; i < 20; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftWillAttack5", i * 665.f, 0.f, 655.f, 499.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightWillAttack6", "RightWillAttack6", TEXT("Will/2/attack6/R/attack6.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack6", 255, 0, 255);

	for (int i = 0; i < 20; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightWillAttack6", i * 701.f, 0.f, 701.f, 442.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack6", "LeftWillAttack6", TEXT("Will/2/attack6/L/attack6.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack6", 255, 0, 255);

	for (int i = 0; i < 20; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftWillAttack6", i * 701.f, 0.f, 701.f, 442.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightWillAttack7", "RightWillAttack7", TEXT("Will/2/attack7/R/attack7.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillAttack7", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightWillAttack7", i * 334.f, 0.f, 334.f, 513.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftWillAttack7", "LeftWillAttack7", TEXT("Will/2/attack7/L/attack7.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillAttack7", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftWillAttack7", i * 334.f, 0.f, 334.f, 513.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightWillHit", "RightWillHit", TEXT("Will/2/Hit/R/Hit.bmp"));

	GetSceneResource()->SetTextureColorKey("RightWillHit", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightWillHit", i * 204.f, 0.f, 204.f, 445.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftWillHit", "LeftWillHit", TEXT("Will/2/Hit/L/Hit.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftWillHit", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftWillHit", i * 204.f, 0.f, 204.f, 445.f);
	}

	// 보스몬스터 피격 이펙트
	GetSceneResource()->CreateAnimationSequence("AttackEffect1", "AttackEffect1", TEXT("Will/2/attack1/Effect/attackeffect.bmp"));

	GetSceneResource()->SetTextureColorKey("AttackEffect1", 255, 0, 255);

	for (int i = 0; i < 6; i++)
	{
		GetSceneResource()->AddAnimationFrameData("AttackEffect1", i * 243.f, 0.f, 243.f, 236.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftAttackEffect2", "LeftAttackEffect2", TEXT("Will/2/attack2/Effect/L/attack2effect.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAttackEffect2", 255, 0, 255);

	for (int i = 0; i < 6; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftAttackEffect2", i * 443.f, 0.f, 443.f, 236.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightAttackEffect2", "RightAttackEffect2", TEXT("Will/2/attack2/Effect/R/attack2effect.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAttackEffect2", 255, 0, 255);

	for (int i = 0; i < 6; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightAttackEffect2", i * 443.f, 0.f, 443.f, 236.f);
	}

	GetSceneResource()->CreateAnimationSequence("AttackEffect4", "AttackEffect4", TEXT("Will/2/attack4/Effect/attack4effect.bmp"));

	GetSceneResource()->SetTextureColorKey("AttackEffect4", 255, 0, 0);

	for (int i = 0; i < 7; i++)
	{
		GetSceneResource()->AddAnimationFrameData("AttackEffect4", i * 320.f, 0.f, 320.f, 295.f);
	}

	// 아라냐
	GetSceneResource()->CreateAnimationSequence("RightAranyaStand", "RightAranyaStand", TEXT("Monster/Aranya/stand/R/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAranyaStand", 255, 0, 255);

	for (int i = 0; i < 12; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightAranyaStand", i * 258.f, 0.f, 258.f, 148.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftAranyaStand", "LeftAranyaStand", TEXT("Monster/Aranya/stand/L/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAranyaStand", 255, 0, 255);

	for (int i = 0; i < 12; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftAranyaStand", i * 258.f, 0.f, 258.f, 148.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightAranyaMove", "RightAranyaMove", TEXT("Monster/Aranya/move/R/move.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAranyaMove", 255, 0, 255);

	for (int i = 0; i < 8; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightAranyaMove", i * 278.f, 0.f, 278.f, 167.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftAranyaMove", "LeftAranyaMove", TEXT("Monster/Aranya/move/L/move.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAranyaMove", 255, 0, 255);

	for (int i = 0; i < 8; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftAranyaMove", i * 278.f, 0.f, 278.f, 167.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightAranyaAttack", "RightAranyaAttack", TEXT("Monster/Aranya/attack1/R/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAranyaAttack", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightAranyaAttack", i * 748.f, 0.f, 748.f, 317.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftAranyaAttack", "LeftAranyaAttack", TEXT("Monster/Aranya/attack1/L/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAranyaAttack", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftAranyaAttack", i * 748.f, 0.f, 748.f, 317.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightAranyaDie", "RightAranyaDie", TEXT("Monster/Aranya/die/R/die.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAranyaDie", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightAranyaDie", i * 425.f, 0.f, 425.f, 250.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftAranyaDie", "LeftAranyaDie", TEXT("Monster/Aranya/die/L/die.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAranyaDie", 255, 0, 255);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftAranyaDie", i * 425.f, 0.f, 425.f, 250.f);
	}

	GetSceneResource()->CreateAnimationSequence("AranyaEffect", "AranyaEffect", TEXT("Monster/Aranya/hit/L/hit.bmp"));

	GetSceneResource()->SetTextureColorKey("AranyaEffect", 255, 0, 255);

	for (int i = 0; i < 7; i++)
	{
		GetSceneResource()->AddAnimationFrameData("AranyaEffect", i * 208.f, 0.f, 208.f, 174.f);
	}

	// 아라네아
	GetSceneResource()->CreateAnimationSequence("RightAraneaStand", "RightAraneaStand", TEXT("Monster/Aranea/stand/R/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAraneaStand", 255, 0, 0);

	for (int i = 0; i < 12; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightAraneaStand", i * 258.f, 0.f, 258.f, 148.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftAraneaStand", "LeftAraneaStand", TEXT("Monster/Aranea/stand/L/stand.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAraneaStand", 255, 0, 0);

	for (int i = 0; i < 12; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftAraneaStand", i * 258.f, 0.f, 258.f, 148.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightAraneaMove", "RightAraneaMove", TEXT("Monster/Aranea/move/R/move.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAraneaMove", 255, 0, 0);

	for (int i = 0; i < 8; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightAraneaMove", i * 278.f, 0.f, 278.f, 167.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftAraneaMove", "LeftAraneaMove", TEXT("Monster/Aranea/move/L/move.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAraneaMove", 255, 0, 0);

	for (int i = 0; i < 8; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftAraneaMove", i * 278.f, 0.f, 278.f, 167.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightAraneaAttack", "RightAraneaAttack", TEXT("Monster/Aranea/attack1/R/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAraneaAttack", 255, 0, 0);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightAraneaAttack", i * 748.f, 0.f, 748.f, 317.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftAraneaAttack", "LeftAraneaAttack", TEXT("Monster/Aranea/attack1/L/attack1.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAraneaAttack", 255, 0, 0);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftAraneaAttack", i * 748.f, 0.f, 748.f, 317.f);
	}

	GetSceneResource()->CreateAnimationSequence("RightAraneaDie", "RightAraneaDie", TEXT("Monster/Aranea/die/R/die.bmp"));

	GetSceneResource()->SetTextureColorKey("RightAraneaDie", 255, 0, 0);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("RightAraneaDie", i * 425.f, 0.f, 425.f, 250.f);
	}

	GetSceneResource()->CreateAnimationSequence("LeftAraneaDie", "LeftAraneaDie", TEXT("Monster/Aranea/die/L/die.bmp"));

	GetSceneResource()->SetTextureColorKey("LeftAraneaDie", 255, 0, 0);

	for (int i = 0; i < 16; i++)
	{
		GetSceneResource()->AddAnimationFrameData("LeftAraneaDie", i * 425.f, 0.f, 425.f, 250.f);
	}

	GetSceneResource()->CreateAnimationSequence("AraneaEffect", "AraneaEffect", TEXT("Monster/Aranea/hit/L/hit.bmp"));

	GetSceneResource()->SetTextureColorKey("AraneaEffect", 255, 0, 0);

	for (int i = 0; i < 7; i++)
	{
		GetSceneResource()->AddAnimationFrameData("AraneaEffect", i * 208.f, 0.f, 208.f, 174.f);
	}

	// 맵 패턴
	GetSceneResource()->CreateAnimationSequence("UpSpiderLeg", "UpSpiderLeg", TEXT("Will/2/Effect/level0_4.bmp"));

	GetSceneResource()->SetTextureColorKey("UpSpiderLeg", 255, 0, 255);

	for (int i = 0; i < 30; i++)
	{
		GetSceneResource()->AddAnimationFrameData("UpSpiderLeg", i * 680.f, 0.f, 680.f, 720.f);
	}

	GetSceneResource()->CreateAnimationSequence("DownSpiderLeg", "DownSpiderLeg", TEXT("Will/2/Effect/Strip 4.bmp"));

	GetSceneResource()->SetTextureColorKey("DownSpiderLeg", 0, 0, 0);

	for (int i = 0; i < 30; i++)
	{
		GetSceneResource()->AddAnimationFrameData("DownSpiderLeg", i * 608.f, 0.f, 608.f, 744.f);
	}

	GetSceneResource()->CreateAnimationSequence("Crack", "Crack", TEXT("Will/2/Effect/tile.bmp"));

	GetSceneResource()->SetTextureColorKey("Crack", 255, 0, 255);

	for (int i = 0; i < 8; i++)
	{
		GetSceneResource()->AddAnimationFrameData("Crack", i * 1425.f, 0.f, 1425.f, 392.f);
	}

	GetSceneResource()->CreateAnimationSequence("HitEffect", "HitEffect", TEXT("Will/HitEffect/Hit_Effect1_2.bmp"));

	GetSceneResource()->SetTextureColorKey("HitEffect", 255, 0, 255);

	for (int i = 0; i < 7; i++)
	{
		GetSceneResource()->AddAnimationFrameData("HitEffect", i * 296.f, 0.f, 296.f, 296.f);
	}
}
