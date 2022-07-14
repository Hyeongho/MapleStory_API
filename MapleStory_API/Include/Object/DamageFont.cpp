#include "DamageFont.h"

CDamageFont::CDamageFont()
{
	m_ObjType = EObject_Type::Effect;
}

CDamageFont::CDamageFont(const CDamageFont& obj) : CGameObject(obj)
{
}

CDamageFont::~CDamageFont()
{
	CGameObject::Start();
}

void CDamageFont::Start()
{
}

bool CDamageFont::Init()
{
	if (!CGameObject::Init())
	{
		return false;
	}

	CWidgetComponent* Widget = CreateWidgetComponent("DamageFont");

	m_NumberWidget = Widget->CreateWidget<CNumberWidget>("DamageFont");

	std::vector<std::wstring> vecNumberFileName;

	for (int i = 0; i < 10; ++i)
	{
		TCHAR	FileName[256] = {};

		wsprintf(FileName, TEXT("DamageNumber/%d.bmp"), i);

		vecNumberFileName.push_back(FileName);
	}

	m_NumberWidget->SetTexture("Number", vecNumberFileName);

	for (int i = 0; i < 10; ++i)
	{
		m_NumberWidget->SetTextureColorKey(255, 0, 255, i);
	}

	m_NumberWidget->SetSize(31.f, 33.f);

	SetLifeTime(0.3f);

	return true;
}

void CDamageFont::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CDamageFont::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CDamageFont::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CDamageFont::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CDamageFont* CDamageFont::Clone()
{
	return new CDamageFont(*this);
}
