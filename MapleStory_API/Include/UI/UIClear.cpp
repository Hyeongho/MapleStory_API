#include "UIClear.h"
#include "../GameManager.h"
#include "UIImage.h"

CUIClear::CUIClear()
{
}

CUIClear::~CUIClear()
{
}

bool CUIClear::Init()
{
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	SetPos(RS.Width / 2.f - 209.f, RS.Height / 2.f - 79.f);

	CUIImage* Clear = CreateWidget<CUIImage>("Clear");

	Clear->SetTexture("Clear", TEXT("Clear.bmp"));
	Clear->SetTextureColorKey(255, 255, 255);

	Clear->SetZOrder(1);

	Clear->SetPlayTime(1.5f);

	for (int i = 0; i < 12; i++)
	{
		Clear->AddFrameData(Vector2(i * 418.f, 0.f), Vector2(418.f, 158.f));
	}

	return true;
}

void CUIClear::Update(float DeltaTime)
{
	CUIWindow::Update(DeltaTime);
}

void CUIClear::PostUpdate(float DeltaTime)
{
	CUIWindow::PostUpdate(DeltaTime);
}

void CUIClear::Collision(float DeltaTime)
{
	CUIWindow::Collision(DeltaTime);
}

void CUIClear::Render(HDC hDC)
{
	CUIWindow::Render(hDC);
}

void CUIClear::Finsh()
{
}
