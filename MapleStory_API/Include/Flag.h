#pragma once

enum EKeyState
{
	KeyState_Down, 
	KeyState_Push,
	KeyState_Up, 
	KeyState_Max
};

enum class ETexture_Type
{
	Atlas,
	Frame
};

enum class ECollider_Type
{
	Box, 
	Sphere, 
	Point
};

enum ECollision_Channel
{
	Channel_Object, 
	Channel_Player, 
	Channel_Monster, 
	Channel_PlayerAttack, 
	Channel_MonsterAttack, 
	Channel_Max
};

enum class ECollision_State
{
	Ignore, 
	Collision
};

enum class EButton_State
{
	Normal, 
	MouseOn, 
	Click, 
	Disable, 
	End
};

enum class EObject_Type
{
	GameObject, 
	Character, 
	Effect
};

enum class ETileOption
{
	Normal, 
	Wall, 
	Slow, 
	End
};

enum class ETileEditMode
{
	Option, 
	Image, 
	End
};

enum class EMonsterAI
{
	Idle,
	Move, 
	Trace,
	Attack,
	Death,
};

enum class EWillPase2
{
	Success, 
	Fail, 
	End
};

enum class EWillPase2Pattern
{
	Start, 
	Normal
};

enum class EWave
{
	Start, 
	Normal, 
	End
};