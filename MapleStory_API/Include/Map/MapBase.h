#pragma once

#include "../GameInfo.h"

class CMapBase
{
	friend class CScene;

protected:
	CMapBase();
	virtual ~CMapBase();

protected:
	class CScene* m_Scene;
	std::string m_Name;
	Vector2 m_Pos;
	Vector2 m_Size;
	int m_ZOrder;
	bool m_Enable;
	bool m_Active;

public:
	bool IsActive() const
	{
		return m_Active;
	}

	bool IsEnable() const
	{
		return m_Enable;
	}

	int GetZOrder() const
	{
		return m_ZOrder;
	}

	const std::string& GetName() const
	{
		return m_Name;
	}

	Vector2 GetPos() const
	{
		return m_Pos;
	}

	Vector2 GetSize() const
	{
		return m_Size;
	}

public:
	void SetZOrder(int ZOrder)
	{
		m_ZOrder = ZOrder;
	}

	void SetScene(class CScene* Scene)
	{
		m_Scene = Scene;
	}

	void SetName(const std::string& Name)
	{
		m_Name = Name;
	}

	void SetPos(const Vector2& Pos)
	{
		m_Pos = Pos;
	}

	void SetPos(float x, float y)
	{
		m_Pos.x = x;
		m_Pos.y = y;
	}

	void SetSize(const Vector2& Size)
	{
		m_Size = Size;
	}

	void SetSize(float x, float y)
	{
		m_Size.x = x;
		m_Size.y = y;
	}

public:
	virtual void Start();
	virtual bool Init();
	virtual void Update(float DeltaTime);
	virtual void PostUpdate(float DeltaTime);
	virtual void PrevRender();
	virtual void Render(HDC hDC);
	virtual void SaveFile(const char* FileName, const std::string& PathName = MAP_PATH);
	virtual void SaveFullPath(const char* FullPath);
	virtual void Save(FILE* pFile);
	virtual void LoadFile(const char* FileName, const std::string& PathName = MAP_PATH);
	virtual void LoadFullPath(const char* FullPath);
	virtual void Load(FILE* pFile);
};

