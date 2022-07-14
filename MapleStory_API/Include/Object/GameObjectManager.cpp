#include "GameObjectManager.h"
#include "../Scene/Scene.h"
#include "../Scene/SceneManager.h"

CGameObjectManager* CGameObjectManager::m_Inst = nullptr;

CGameObjectManager::CGameObjectManager() : m_Player(nullptr)
{
}

CGameObjectManager::~CGameObjectManager()
{
}

void CGameObjectManager::GivePlayer(CPlayer* Player)
{
	m_Player = Player;
}

void CGameObjectManager::PassPlayer(CPlayer* Player)
{
	if (!m_Player)
	{
		return;
	}

	Player->SetCharacterInfo(m_Player->GetCharacterInfo());
}
