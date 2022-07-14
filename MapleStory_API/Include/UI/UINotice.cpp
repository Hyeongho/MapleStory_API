#include "UINotice.h"
#include "../GameManager.h"
#include "../Scene/BossWillPase2.h"
#include "../Scene/SceneManager.h"
#include "UIText.h"

CUINotice::CUINotice()
{
}

CUINotice::~CUINotice()
{
}

bool CUINotice::Init()
{
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	SetPos(RS.Width / 2.f - 262.f, 100.f);

	m_Notice = CreateWidget<CUIImage>("Notice");

	m_Notice->SetTexture("Notice", TEXT("Notice1_2.bmp"));

	m_Notice->SetTextureColorKey(255, 0, 255);

	m_Notice->SetZOrder(5);

	return true;
}

void CUINotice::Update(float DeltaTime)
{
	CUIWindow::Update(DeltaTime);
}

void CUINotice::Finsh()
{
	Destroy();
}
