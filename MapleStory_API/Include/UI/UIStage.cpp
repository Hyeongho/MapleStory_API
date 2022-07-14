#include "UIStage.h"
#include "../GameManager.h"
#include "../Scene/Stage1.h"

int CUIStage::m_Count = 0;

CUIStage::CUIStage()
{
}

CUIStage::~CUIStage()
{
	
}

bool CUIStage::Init()
{
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	m_CountImage = CreateWidget<CUIImage>("Count");

	m_CountImage->SetTexture("Count", TEXT("count.bmp"));
	m_CountImage->SetTextureColorKey(255, 0, 255);

	m_Count = 0;

	for (int i = 0; i < 23; i++)
	{
		m_CountImage->AddFrameData(Vector2(i * 91.f, 0.f), Vector2(91.f, 121.f));
	}

	m_CountImage->SetZOrder(1);

	m_CountImage->SetPlayTime(3.f);

	m_CountImage->SetVisibility(false);

	m_CountImage->SetPos(RS.Width / 2.f - 45.5f, RS.Height / 2.f - 60.5f);

	m_Count++;

	return true;
}

void CUIStage::Update(float DeltaTime)
{
	CUIWindow::Update(DeltaTime);

	if (m_Visibility)
	{
		if (CStage1::m_Wave == EWave::Start)
		{
			if (!m_CountImage->GetVisibility())
			{
				m_CountImage->SetVisibility(true);	
			}
		}
	}	
}

void CUIStage::PostUpdate(float DeltaTime)
{
	CUIWindow::PostUpdate(DeltaTime);

	if (m_Visibility)
	{
		if (m_CountImage->GetFrameIndex() == 22)
		{
			m_CountImage->SetFrameIndex(0);
			m_CountImage->SetVisibility(false);

			m_Visibility = false;

			CStage1::m_Wave = EWave::Normal;
		}
	}
}

void CUIStage::Collision(float DeltaTime)
{
	CUIWindow::Collision(DeltaTime);
}

void CUIStage::Render(HDC hDC)
{
	CUIWindow::Render(hDC);
}

void CUIStage::Finsh()
{
}
