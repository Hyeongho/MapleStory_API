#pragma once

#include "../GameInfo.h"
#include "Player.h"

class CGameObjectManager
{
	friend class CScene;

private:
	CGameObjectManager();
	~CGameObjectManager();

private:
	static CGameObjectManager* m_Inst;

private:
	class CScene* m_Scene;
	CPlayer* m_Player;

public:
	void GivePlayer(CPlayer* Player);
	void PassPlayer(CPlayer* Player);

public:
	static CGameObjectManager* GetInst()
	{
		if (!m_Inst)
		{
			m_Inst = new CGameObjectManager;
		}

		return m_Inst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_Inst);
	}
};

