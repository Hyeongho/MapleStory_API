#include "SpiderLeg.h"
#include "Player.h"
#include "EffectHit.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneManager.h"
#include "../Collision/ColliderBox.h"
#include "../UI/UINotice.h"


CSpiderLeg::CSpiderLeg() : m_IsHit(false)
{
	m_ObjType = EObject_Type::GameObject;
}

CSpiderLeg::CSpiderLeg(const CSpiderLeg& obj) : CGameObject(obj), m_IsHit(false)
{
	m_Direction = obj.m_Direction;
}

CSpiderLeg::~CSpiderLeg()
{
}

void CSpiderLeg::Start()
{
	CGameObject::Start();

	if (m_Direction)
	{
		SetAnimationEndNotify<CSpiderLeg>("UpSpiderLeg", this, &CSpiderLeg::AnimationFinish);

		AddAnimationNotify<CSpiderLeg>("UpSpiderLeg", 21, this, &CSpiderLeg::Attack);

		AddAnimationNotify<CSpiderLeg>("UpSpiderLeg", 24, this, &CSpiderLeg::AttackEnd);
	}

	else
	{
		SetAnimationEndNotify<CSpiderLeg>("DownSpiderLeg", this, &CSpiderLeg::AnimationFinish);

		AddAnimationNotify<CSpiderLeg>("DownSpiderLeg", 21, this, &CSpiderLeg::Attack);

		AddAnimationNotify<CSpiderLeg>("DownSpiderLeg", 24, this, &CSpiderLeg::AttackEnd);
	}
}

bool CSpiderLeg::Init(bool Direction)
{
	if (!CGameObject::Init())
	{
		return false;
	}

	m_Direction = Direction;

	if (m_Direction)
	{
		SetPivot(0.5f, 0.f);

		CreateAnimation();

		AddAnimation("UpSpiderLeg", false, 2.0f);
	}

	else
	{
		SetPivot(0.5f, 1.f);

		CreateAnimation();

		AddAnimation("DownSpiderLeg", false, 2.0f);
	}

	return true;
}

void CSpiderLeg::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);
}

void CSpiderLeg::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CSpiderLeg::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CSpiderLeg::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CSpiderLeg* CSpiderLeg::Clone()
{
	return new CSpiderLeg(*this);
}

void CSpiderLeg::AnimationFinish()
{
	Destroy();

	CPlayer* Player = (CPlayer*)(m_Scene->GetPlayer());

	Player->SetHit(false);
}

void CSpiderLeg::Attack()
{
	if (m_Direction)
	{
		CColliderBox* Body = AddCollider<CColliderBox>("UpBody");
		Body->SetExtent(60.f, 1440.f);
		Body->SetOffset(-60.f, 0.f);
		Body->SetName("LegAttack");
	}

	else
	{
		CColliderBox* Body = AddCollider<CColliderBox>("DownBody");
		Body->SetExtent(60.f, 720.f);
		Body->SetOffset(-60.f, -500.f);
		Body->SetName("LegAttack");
	}

	CCollider* ColliderBody = FindCollider("LegAttack");

	if (ColliderBody)
	{
		ColliderBody->SetCollisionBeginFunction<CSpiderLeg>(this, &CSpiderLeg::ColliderBegin);
	}
}

void CSpiderLeg::AttackEnd()
{
	
}

void CSpiderLeg::ColliderBegin(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	if (m_Scene->FindUIWindow<CUINotice>("Notice"))
	{
		if (m_Scene->FindObject("Crack"))
		{
			CPlayer* Player = (CPlayer*)(m_Scene->GetPlayer());

			if (Player->GetHit())
			{
				if (m_Direction)
				{
					CCollider* ColliderUP = FindCollider("UpBody");

					if (ColliderUP)
					{
						ColliderUP->Destroy();
					}
				}

				else
				{
					CCollider* ColliderDown = FindCollider("DownBody");

					if (ColliderDown)
					{
						ColliderDown->Destroy();
					}
				}

				return;
			}

			else
			{
				Player->SetDamage(100);

				Vector2 Pos = Player->GetPos();

				CEffectHit* Hit = m_Scene->CreateObject<CEffectHit>("HitEffect", "HitEffect", Pos, Vector2(296.f, 296.f));
			}
		}

		if (Dest->GetProfile()->Name == "Player" && !m_Scene->FindObject("Crack"))
		{
			Dest->GetOwner()->SetDamage(100);

			Vector2 Pos = Dest->GetOwner()->GetPos();

			CEffectHit* Hit = m_Scene->CreateObject<CEffectHit>("HitEffect", "HitEffect", Pos, Vector2(296.f, 296.f));
		}
	}

	else
	{
		if (Dest->GetProfile()->Name == "Player")
		{
			Dest->GetOwner()->SetDamage(100);

			Vector2 Pos = Dest->GetOwner()->GetPos();

			CEffectHit* Hit = m_Scene->CreateObject<CEffectHit>("HitEffect", "HitEffect", Pos, Vector2(296.f, 296.f));

		}
	}
}
