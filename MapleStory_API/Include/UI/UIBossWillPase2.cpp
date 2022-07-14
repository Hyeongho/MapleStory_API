#include "UIBossWillPase2.h"
#include "../GameManager.h"
#include "../Scene/SceneManager.h"

CUIBossWillPase2::CUIBossWillPase2()
{
}

CUIBossWillPase2::~CUIBossWillPase2()
{
}

bool CUIBossWillPase2::Init()
{
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	SetPos(RS.Width / 2.f - 400.5f, 0.f);

	CUIImage* Back = CreateWidget<CUIImage>("WillStatusBar");

	Back->SetTexture("WillStatusBar", TEXT("Will_HP_Backgrnd.bmp"));
	Back->SetTextureColorKey(255, 0, 255);
	Back->SetZOrder(3);

	m_HPBar1 = CreateWidget<CProgressBar>("m_HPBar1");
	m_HPBar1->SetTexture("m_HPBar1", TEXT("MobGage.Gage.1.bmp"));

	m_HPBar1->SetZOrder(4);

	m_HPBar1->SetPos(431.f, 4.f);

	m_HPBar2 = CreateWidget<CProgressBar>("m_HPBar2");
	m_HPBar2->SetTexture("m_HPBar2", TEXT("MobGage.Gage.2.bmp"));
		   
	m_HPBar2->SetZOrder(4);
		   
	m_HPBar2->SetPos(46.f, 4.f);

	m_HPBar3 = CreateWidget<CProgressBar>("m_HPBar3");
	m_HPBar3->SetTexture("m_HPBar3", TEXT("MobGage.Gage.3.bmp"));

	m_HPBar3->SetZOrder(4);

	m_HPBar3->SetPos(40.f, 4.f);

	return true;
}
