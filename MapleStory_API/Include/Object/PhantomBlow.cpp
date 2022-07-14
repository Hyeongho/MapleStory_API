#include "PhantomBLow.h"
#include "Player.h"
#include "../Scene/Scene.h"
#include "../Collision/ColliderBox.h"
#include "DamageFont.h"

CPhantomBlow::CPhantomBlow() : m_Direction(false), m_IsHit(false)
{
	m_ObjType = EObject_Type::Effect;
}

CPhantomBlow::CPhantomBlow(const CPhantomBlow& obj) : CGameObject(obj)
{
	m_Direction = obj.m_Direction;
}

CPhantomBlow::~CPhantomBlow()
{
}

void CPhantomBlow::Start()
{
	CGameObject::Start();

	if (m_Direction)
	{
		CCollider* Body = FindCollider("Body");

		Body->SetCollisionBeginFunction<CPhantomBlow>(this, &CPhantomBlow::ColliderBegin);

		SetAnimationEndNotify<CPhantomBlow>("LeftPhantomBlow", this, &CPhantomBlow::AnimationFinish);
	}

	else
	{
		CCollider* Body = FindCollider("Body");

		Body->SetCollisionBeginFunction<CPhantomBlow>(this, &CPhantomBlow::ColliderBegin);

		SetAnimationEndNotify<CPhantomBlow>("RightPhantomBlow", this, &CPhantomBlow::AnimationFinish);
	}
	
}

bool CPhantomBlow::Init(bool Direction)
{
	if (!CGameObject::Init())
	{
		return false;
	}

	m_Direction = Direction;

	SetPivot(0.5f, 0.5f);

	if (m_Direction)
	{
		CreateAnimation();
		AddAnimation("LeftPhantomBlow", false);

		CColliderBox* Body = AddCollider<CColliderBox>("Body");
		Body->SetExtent(270.f, 150.f);
		Body->SetOffset(-40.f, 0.f);
		Body->SetCollisionProfile("PlayerAttack");
	}

	else
	{
		CreateAnimation();
		AddAnimation("RightPhantomBlow", false);

		CColliderBox* Body = AddCollider<CColliderBox>("Body");
		Body->SetExtent(270.f, 150.f);
		Body->SetOffset(40, 0.f);
		Body->SetCollisionProfile("PlayerAttack");
	}

	return true;
}

void CPhantomBlow::Update(float DeltaTime)
{
	CGameObject::Update(DeltaTime);

	CGameObject* Player = m_Scene->GetPlayer();

	Vector2 Pos = Player->GetPos();
	Vector2 Size = Player->GetSize();

	if (m_Direction)
	{
		SetPos(Pos.x - Size.x, Pos.y - 50.f);
	}

	else
	{
		SetPos(Pos.x + Size.x, Pos.y - 50.f);
	}
}

void CPhantomBlow::PostUpdate(float DeltaTime)
{
	CGameObject::PostUpdate(DeltaTime);
}

void CPhantomBlow::Collision(float DeltaTime)
{
	CGameObject::Collision(DeltaTime);
}

void CPhantomBlow::Render(HDC hDC)
{
	CGameObject::Render(hDC);
}

CPhantomBlow* CPhantomBlow::Clone()
{
	return new CPhantomBlow(*this);
}

void CPhantomBlow::ChangeAnimation(bool Direction)
{
	
}

void CPhantomBlow::AnimationFinish()
{
	Destroy();
}

void CPhantomBlow::ColliderBegin(CCollider* Src, CCollider* Dest, float DeltaTime)
{
	if (Dest->GetProfile()->Channel == ECollision_Channel::Channel_Monster)
	{
		m_IsHit = true;

		Pos = Dest->GetOwner()->GetPos();
		Size = Dest->GetOwner()->GetSize();

		for (int i = 0; i < 6; i++)
		{
			if (m_Direction)
			{
				Dest->GetOwner()->SetDamage(10);

				AddAnimationNotify<CPhantomBlow>("LeftPhantomBlow", i, this, &CPhantomBlow::Attack);
			}

			else
			{
				Dest->GetOwner()->SetDamage(10);

				AddAnimationNotify<CPhantomBlow>("RightPhantomBlow", i, this, &CPhantomBlow::Attack);
			}
		}
	}
}

void CPhantomBlow::Attack()
{
	int Frame = m_Animation->GetFrame();

	CDamageFont* DamageFont = m_Scene->CreateDamageFont<CDamageFont>("DamageFont", Vector2(Pos.x - 31.f, Pos.y - (Size.y / 2) - (Frame * 30)));

	DamageFont->SetDamageNumber(10);
}
