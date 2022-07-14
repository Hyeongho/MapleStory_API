#pragma once

#include "../GameInfo.h"
#include "Scene.h"
#include "../Object/GameObjectManager.h"

class CSceneManager
{
private:
	CSceneManager();
	~CSceneManager();

private:
	CScene* m_Scene;
	CScene* m_NextScene;

	std::string m_Name;
	std::string m_NextName;

public:
	void SetName(const std::string Name)
	{
		m_Name = Name;
	}

public:
	CScene* GetScene()
	{
		return m_Scene;
	}

	std::string GetName() const
	{
		return m_Name;
	}

public:
	bool Init();
	bool Update(float DeltaTime);
	bool PostUpdate(float DeltaTime);
	bool Collision(float DeltaTime);
	bool Render(HDC hDC);

private:
	bool ChangeScene();

private:
	static CSceneManager* m_Inst;

public:
	static CSceneManager* GetInst()
	{
		if (!m_Inst)
		{
			m_Inst = new CSceneManager;
		}

		return m_Inst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_Inst);
	}

public:
	template <typename T>
	bool CreateScene(const std::string Name = " ")
	{
		m_NextScene = new T;

		m_NextName = Name;

		if (m_Scene->GetPlayer())
		{
			CGameObjectManager::GetInst()->GivePlayer((CPlayer*)m_Scene->GetPlayer());
		}

		if (!m_NextScene->Init())
		{
			SAFE_DELETE(m_NextScene);
			return false;
		}

		return true;
	}
};

