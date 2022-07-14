#include "UIMonitorBreak.h"
#include "../Resource/ResourceManager.h"
#include "../GameManager.h"
#include "../Scene/SceneManager.h"
#include "../Scene/EndScene.h"
#include "../Scene/Scene.h"

CUIMonitorBreak::CUIMonitorBreak() : m_Time(0.f)
{
}

CUIMonitorBreak::~CUIMonitorBreak()
{
}

bool CUIMonitorBreak::Init()
{
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	m_MonitorBreak = CreateWidget<CUIImage>("MonitorBreak");

	std::vector<std::wstring>	vecMonitorFileName;

	for (int i = 1; i <= 35; ++i)
	{
		TCHAR	FileName[256] = {};

		wsprintf(FileName, TEXT("MonitorBreak/%d.bmp"), i);

		vecMonitorFileName.push_back(FileName);
	}

	m_MonitorBreak->SetTexture("Number", vecMonitorFileName);

	for (int i = 0; i < 35; ++i)
	{
		m_MonitorBreak->SetTextureColorKey(255, 0, 255, i);
	}

	/*m_MonitorBreak->SetTexture("MonitorBreak", TEXT("Sheet_0003.bmp"));
	m_MonitorBreak->SetTextureColorKey(255, 0, 255);*/
	
	m_MonitorBreak->SetZOrder(1);

	m_MonitorBreak->SetPlayTime(3.f);

	for (int i = 0; i < 35; i++)
	{
		m_MonitorBreak->AddFrameData(Vector2(0.f, 0.f), Vector2(1368.f, 768.f));
	}

	/*for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m_MonitorBreak->AddFrameData(Vector2(j * 1368.f, i * 768.f), Vector2(1368.f, 768.f));
		}
	}*/

	return true;
}

void CUIMonitorBreak::Update(float DeltaTime)
{
	CUIWindow::Update(DeltaTime);

	if (m_MonitorBreak)
	{
		if (m_MonitorBreak->GetFrameIndex() == 34)
		{
			m_Visibility = false;
			CSceneManager::GetInst()->CreateScene<CEndScene>("EndScene");
		}		
	}
}

void CUIMonitorBreak::PostUpdate(float DeltaTime)
{
	CUIWindow::PostUpdate(DeltaTime);
}

void CUIMonitorBreak::Collision(float DeltaTime)
{
	CUIWindow::Collision(DeltaTime);
}

void CUIMonitorBreak::Render(HDC hDC)
{
	CUIWindow::Render(hDC);
}

void CUIMonitorBreak::Finsh()
{
	Destroy();
}
