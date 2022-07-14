#include "Potal.h"
#include "Player.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneManager.h"
#include "../Scene/MainMap.h"
#include "../Scene/Stage1.h"
#include "../Scene/BossWillPase2.h"
#include "../Collision/ColliderBox.h"

CPotal::CPotal()
{
	m_ObjType = EObject_Type::GameObject;
}

CPotal::CPotal(const CPotal& obj) : CGameObject(obj)
{
}

CPotal::~CPotal()
{
}

void CPotal::Start()
{
	CGameObject::Start();

	CCollider* Body = FindCollider("Body");

	Body->SetCollisionBeginFunction<CPotal>(this, &CPotal::ColliderBegin);
}

bool CPotal::Init()
{
	if (!CGameObject::Init())
	{
		return false;
	}

	CreateAnimation();
	AddAnimation("Potal", true);

	CColliderBox* Body = AddCollider<CColliderBox>("Body");
	Body->SetExtent(30.f, 30.f);
	Body->SetOffset(m_Size.x / 2.f, m_Size.y + 30.f);

	return true;
}

void CPotal::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CPotal::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CPotal::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CPotal::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CPotal* CPotal::Clone()
{
	return new CPotal(*this);
}

void CPotal::ColliderBegin(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	if (Dest->GetProfile()->Name == "Player")
	{
		if (Src->GetOwner()->GetName() == "TutoMain")
		{
			CSceneManager::GetInst()->CreateScene<CMainMap>("MainMap");
		}

		else if (Src->GetOwner()->GetName() == "MaintoStage1")
		{
			CSceneManager::GetInst()->CreateScene<CStage1>("Stage1");
		}

		else if (Src->GetOwner()->GetName() == "StagetoWill")
		{
			CSceneManager::GetInst()->CreateScene<CBossWillPase2>("BossWillPase2");
		}
	}	
}
