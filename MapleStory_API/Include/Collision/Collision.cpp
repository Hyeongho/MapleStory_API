#include "Collision.h"
#include "ColliderBox.h"
#include "ColliderSphere.h"

bool CCollision::CollisionBoxToBox(CColliderBox* Src, CColliderBox* Dest)
{
	if (CollisionBoxToBox(Src->GetInfo(), Dest->GetInfo()))
	{
		return true;
	}

	return false;
}

bool CCollision::CollisionBoxToBox(const RectInfo& Src, const RectInfo& Dest)
{
	if (Src.Left > Dest.Right)
	{
		return false;
	}

	else if (Dest. Left > Src.Right)
	{
		return false;
	}

	else if (Src.Top > Dest.Bottom)
	{
		return false;
	}

	else if (Dest.Top > Src.Bottom)
	{
		return false;
	}

	return true;
}

bool CCollision::CollisionSphereToSphere(CColliderSphere* Src, CColliderSphere* Dest)
{
	if (CollisionSphereToSphere(Src->GetInfo(), Dest->GetInfo()))
	{
		return true;
	}

	return false;
}

bool CCollision::CollisionSphereToSphere(const SphereInfo& Src, const SphereInfo& Dest)
{
	float Dist = Distance(Src.Center, Dest.Center);

	return Dist <= Src.Radius + Dest.Radius;
}

bool CCollision::CollisionBoxToSphere(CColliderBox* Src, CColliderSphere* Dest)
{
	if (CollisionBoxToSphere(Src->GetInfo(), Dest->GetInfo()))
	{
		return true;
	}

	return false;
}

bool CCollision::CollisionBoxToSphere(const RectInfo& Src, const SphereInfo& Dest)
{
	/*if ((Src.Left >= Dest.Center.x && Src.Right <= Dest.Center.x) || (Src.Top >= Dest.Center.y && Src.Bottom <= Dest.Center.y))
	{
		float DestLeft = Src.Left - Dest.Radius;
		float DestTop = Src.Top - Dest.Radius;
		float DestRight = Src.Right + Dest.Radius;
		float DestBottom = Src.Bottom + Dest.Radius;

		if ((DestLeft >= Dest.Center.x && DestRight <= Dest.Center.x) || (DestTop >= Dest.Center.y && DestBottom <= Dest.Center.y))
		{
			return true;
		}
	}

	else
	{
		float LTPoint = Distance(Dest.Center, Vector2(Src.Left, Src.Top));
		float LBPoint = Distance(Dest.Center, Vector2(Src.Left, Src.Bottom));
		float RTPoint = Distance(Dest.Center, Vector2(Src.Right, Src.Top));
		float RBPoint = Distance(Dest.Center, Vector2(Src.Right, Src.Bottom));

		if ((LTPoint <= Dest.Radius) || (LBPoint <= Dest.Radius) || (RTPoint <= Dest.Radius) || (RBPoint <= Dest.Radius))
		{
			return true;
		}
	}*/

	// 원의 중점이 사각형의 좌, 우, 위, 아래 영역에 존재하는지 판단한다.
	if ((Src.Left >= Dest.Center.x && Src.Right <= Dest.Center.x) || (Src.Top >= Dest.Center.y && Src.Bottom <= Dest.Center.y))
	{
		// 원의 반지름 만큼 사각형을 확장한다.
		RectInfo RC = Src;
		RC.Left -= Dest.Radius;
		RC.Top -= Dest.Radius;
		RC.Right -= Dest.Radius;
		RC.Bottom -= Dest.Radius;

		// 확장된 사각형 안에 원의 중점이 들어오는지 판단한다.
		if (RC.Left < Dest.Center.x)
		{
			return false;
		}

		else if (RC.Right < Dest.Center.x)
		{
			return false;
		}

		else if (RC.Top < Dest.Center.y)
		{
			return false;
		}

		else if (RC.Bottom < Dest.Center.y)
		{
			return false;
		}

		return true;
	}

	// 원의 중접이 사각형의 대각선 영역에 존재할 경우 사각형을 구성하는 4개의 점을 구해서 4개의 점들 중 하나라도 원 안에 존재한다면 충돌로 판단한다.
	Vector2 Pos[4] = {};

	Pos[0] = Vector2(Src.Left, Src.Top);
	Pos[1] = Vector2(Src.Right, Src.Top);
	Pos[2] = Vector2(Src.Left, Src.Bottom);
	Pos[3] = Vector2(Src.Right, Src.Bottom);

	for (int i = 0; i < 4; i++)
	{
		float Dist = Distance(Pos[i], Dest.Center);

		if (Dist <= Dest.Radius)
		{
			return true;
		}
	}

	return false;
}

bool CCollision::CollisionSphereToBox(CColliderSphere* Src, CColliderBox* Dest)
{
	if (CollisionSphereToBox(Src->GetInfo(), Dest->GetInfo()))
	{
		return true;
	}

	return false;
}

bool CCollision::CollisionSphereToBox(const SphereInfo& Src, const RectInfo& Dest)
{
	if ((Dest.Left >= Src.Center.x && Dest.Right <= Src.Center.x) || (Dest.Top >= Src.Center.y && Dest.Bottom <= Src.Center.y))
	{
		float DestLeft = Dest.Left - Src.Radius;
		float DestTop = Dest.Top - Src.Radius;
		float DestRight = Dest.Right + Src.Radius;
		float DestBottom = Dest.Bottom + Src.Radius;

		if ((DestLeft >= Src.Center.x && DestRight <= Src.Center.x) || (DestTop >= Src.Center.y && DestBottom <= Src.Center.y))
		{
			return true;
		}
	}

	else
	{
		float LTPoint = Distance(Src.Center, Vector2(Dest.Left, Dest.Top));
		float LBPoint = Distance(Src.Center, Vector2(Dest.Left, Dest.Bottom));
		float RTPoint = Distance(Src.Center, Vector2(Dest.Right, Dest.Top));
		float RBPoint = Distance(Src.Center, Vector2(Dest.Right, Dest.Bottom));

		if ((LTPoint <= Src.Radius) || (LBPoint <= Src.Radius) || (RTPoint <= Src.Radius) || (RBPoint <= Src.Radius))
		{
			return true;
		}
	}

	return false;
}
