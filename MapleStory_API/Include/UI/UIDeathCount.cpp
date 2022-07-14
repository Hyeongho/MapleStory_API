#include "UIDeathCount.h"
#include "UIImage.h"
#include "NumberWidget.h"
#include "../GameManager.h"
#include "../Scene/SceneManager.h"
#include "../Scene/SceneResource.h"
#include "../Scene/BossWillPase2.h"

CUIDeathCount::CUIDeathCount()
{
}

CUIDeathCount::~CUIDeathCount()
{
}

bool CUIDeathCount::Init()
{
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	CUIImage* Back = CreateWidget<CUIImage>("DeathCountInfo");

	Back->SetTexture("Back", TEXT("DeathCountInfo.bmp"));
	Back->SetTextureColorKey(255, 0, 255);

	Back->SetPos(RS.Width / 2.f - 44.5f, 45.f);

	m_NumberWidget = CreateWidget<CNumberWidget>("DeathNumber");

	std::vector<std::wstring>	vecCountFileName;

	Vector2 Pos = Back->GetPos();

	for (int i = 0; i < 10; ++i)
	{
		TCHAR	CountFileName[256] = {};

		wsprintf(CountFileName, TEXT("DeathCount/%d.bmp"), i);

		vecCountFileName.push_back(CountFileName);
	}

	m_NumberWidget->SetTexture("DeathNumber", vecCountFileName);

	for (int i = 0; i < 10; ++i)
	{
		m_NumberWidget->SetTextureColorKey(255, 0, 255, i);
	}

	m_NumberWidget->SetPos(Pos.x + 64.f, Pos.y + 29.f);
	//m_NumberWidget->SetSize(12.f, 17.f);

	m_NumberWidget->SetZOrder(3);

	m_Number1Widget = CreateWidget<CNumberWidget>("DeathNumber");

	m_Number1Widget->SetTexture("DeathNumber", vecCountFileName);

	for (int i = 0; i < 10; ++i)
	{
		m_Number1Widget->SetTextureColorKey(255, 0, 255, i);
	}

	m_Number1Widget->SetPos(Pos.x + 54.f, Pos.y + 29.f);
	//m_Number1Widget->SetSize(12.f, 17.f);

	m_Number1Widget->SetZOrder(3);

	return true;
}

void CUIDeathCount::Update(float DeltaTime)
{
	CUIWindow::Update(DeltaTime);

	int Number1, Number2;

	int DeathCount = CBossWillPase2::m_DeathCount;

	Number1 = DeathCount % 10;
	Number2 = DeathCount / 10;
	
	m_NumberWidget->SetNumber(Number1);
	m_Number1Widget->SetNumber(Number2);
}
