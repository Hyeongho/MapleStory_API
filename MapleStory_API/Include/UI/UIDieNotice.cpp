#include "UIDieNotice.h"
#include "Button.h"
#include "UIImage.h"
#include "../GameManager.h"
#include "../Scene/Stage1.h"
#include "../Scene/BossWillPase2.h"
#include "../Scene/MainMap.h"
#include "../Scene/SceneManager.h"
#include "../Object/Player.h"

CUIDieNotice::CUIDieNotice()
{
}

CUIDieNotice::~CUIDieNotice()
{
}

bool CUIDieNotice::Init()
{
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	CUIImage* Back = CreateWidget<CUIImage>("Back");

	Back->SetPos(RS.Width / 2.f - 150.f, RS.Height / 2.f - 65.5f);

	Back->SetTexture("DieNoticeBack", TEXT("Notice.8.bmp"));
	Back->SetTextureColorKey(255, 0, 255);

	Back->SetZOrder(6);

	CButton* Button = CreateWidget<CButton>("OKButton");

	Vector2 Pos = Back->GetPos();

	Button->SetTexture("OKButton", TEXT("OKButton.bmp"));
	Button->SetTextureColorKey(255, 0, 255);
	Button->SetPos(Pos.x + 240.f, Pos.y + 99.f);
	Button->SetFrameData(EButton_State::Normal, Vector2(0.f, 0.f), Vector2(40.f, 16.f));
	Button->SetFrameData(EButton_State::MouseOn, Vector2(40.f, 0.f), Vector2(40.f, 16.f));
	Button->SetFrameData(EButton_State::Click, Vector2(80.f, 0.f), Vector2(40.f, 16.f));
	Button->SetFrameData(EButton_State::Disable, Vector2(120.f, 0.f), Vector2(40.f, 16.f));

	Button->SetZOrder(7);

	Button->SetClickCallback<CUIDieNotice>(this, &CUIDieNotice::OKClick);

	m_Visibility = false;

	return true;
}

void CUIDieNotice::OKClick()
{
	if (m_Visibility)
	{
		CPlayer* Player = (CPlayer*)m_Scene->GetPlayer();

		Player->SetHP();

		CPlayer::m_IsDie = false;

		m_Visibility = false;

		if (CSceneManager::GetInst()->GetName() == "BossWillPase2" && CBossWillPase2::m_DeathCount <= 0)
		{
			CSceneManager::GetInst()->CreateScene<CMainMap>("MainMap");
		}
	}
}
