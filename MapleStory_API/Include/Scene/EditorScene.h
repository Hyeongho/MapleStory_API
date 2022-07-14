#pragma once
#include "Scene.h"
class CEditorScene :
	public CScene
{
	friend class CSceneManager;

private:
	CEditorScene();
	virtual ~CEditorScene();

private:
	bool m_Start;
	class CEditorDlg* m_Dlg;
	class CTileMap* m_TileMap;
	float m_ScroolSpeed;

	class CScrollMap* m_ScrolMap;

public:
	virtual bool Init();
	virtual bool Update(float DeltaTime);
	virtual bool PostUpdate(float DeltaTime);

private:
	void LoadAnimationSequence();
	void LoadSound();

public:
	void OnEditor(float DeltaTiem);
	void CreateTileMap();
	void SetTileInfo(int CountX, int CountY, int SizeX, int SizeY);
	void SetTileTexture(class CTexture* Texture);
	void CreateBack();
	void SetBackInfo(int SizeX, int SizeY);
	void SetBackTexture(std::string MapName, std::string TextureName);

public:
	void CameraMoveUp(float DeltaTime);
	void CameraMoveDown(float DeltaTime);
	void CameraMoveLeft(float DeltaTime);
	void CameraMoveRight(float DeltaTime);

	void MouseLButton(float DeltaTime);
	void MouseRButton(float DeltaTime);

public:
	void Save(const char* FullPath);
	void Load(const char* FullPath);
	void TileImageAllClear();
};

