#include "TileMap.h"
#include "../Scene/Scene.h"
#include "../Scene/Camera.h"

CTileMap::CTileMap() : m_TileCountX(0), m_TileCountY(0), m_StartX(-1), m_StartY(-1), m_EndX(-1), m_EndY(-1)
{
}

CTileMap::~CTileMap()
{
	size_t Size = m_vecTile.size();

	for (size_t i = 0; i < Size; i++)
	{
		SAFE_DELETE(m_vecTile[i]);
	}

	m_vecTile.clear();
}

bool CTileMap::CreateTile(int CountX, int CountY, const Vector2& TileSize)
{
	m_TileCountX = CountX;
	m_TileCountY = CountY;
	m_TileSize = TileSize;

	{
		auto iter = m_vecTile.begin();
		auto iterEnd = m_vecTile.end();

		for (; iter != iterEnd; iter++)
		{
			SAFE_DELETE((*iter));
		}

		m_vecTile.clear();
	}

	m_Size = m_TileSize * Vector2((float)m_TileCountX, (float)m_TileCountY);

	CCamera* Camera = m_Scene->GetCamera();
	Camera->SetWorldResolution(m_Size);

	for (int i = 0; i < m_TileCountY; i++)
	{
		for (int j = 0; j < m_TileCountX; j++)
		{
			CTile* Tile = new CTile;
			Tile->m_Scene = m_Scene;

			Tile->Init();

			Vector2 Pos = Vector2((float)j, (float)i) * m_TileSize;

			Tile->SetTileInfo(Pos, m_TileSize, j, i, i * m_TileCountX + j, m_TileTexture);

			m_vecTile.push_back(Tile);
		}
	}

	for (int i = 0; i < m_TileCountY; i++)
	{
		for (int j = 0; j < m_TileCountX; j++)
		{
			m_vecTile[i * m_TileCountX + j]->SetTileTexture(m_TileTexture);
		}
	}

	return true;
}

bool CTileMap::SetTileTexture(CTexture* Texture)
{
	m_TileTexture = Texture;

	for (int i = 0; i < m_TileCountY; i++)
	{
		for (int j = 0; j < m_TileCountX; j++)
		{
			m_vecTile[i * m_TileCountX + j]->SetTileTexture(m_TileTexture);
		}
	}

	return true;
}

bool CTileMap::SetTileTexture(CTexture* Texture, int IndexX, int IndexY)
{
	m_TileTexture = Texture;

	m_vecTile[IndexY * m_TileCountX + IndexX]->SetTileTexture(m_TileTexture);

	return true;
}

void CTileMap::SetTileTexture(const Vector2& Pos, CTexture* Texture)
{
	CTile* Tile = GetTile(Pos);

	if (!Tile)
	{
		return;
	}

	Tile->SetTileTexture(Texture);
}

void CTileMap::ChangeTileOption(const Vector2& Pos, ETileOption Option)
{
	CTile* Tile = GetTile(Pos);

	if (!Tile)
	{
		return;
	}

	Tile->SetTileOption(Option);
}

void CTileMap::ChangeTileSideCollision(const Vector2 Pos, bool SideCollision)
{
	CTile* Tile = GetTile(Pos);

	if (!Tile)
	{
		return;
	}

	Tile->SetSideCollision(SideCollision);
}

void CTileMap::SetTileFrmae(const Vector2& Pos, const Vector2& Start, const Vector2& End)
{
	CTile* Tile = GetTile(Pos);

	if (!Tile)
	{
		return;
	}

	Tile->SetTileTexture(m_TileTexture);
	Tile->SetStartFrame(Start);
	Tile->SetEndFrame(End);
}

CTile* CTileMap::GetTile(const Vector2& Pos)
{
	int IndexX = (int)(Pos.x / m_TileSize.x);
	int IndexY = (int)(Pos.y / m_TileSize.y);

	if (IndexX < 0 || IndexX >= m_TileCountX)
	{
		return nullptr;
	}

	if (IndexY < 0 || IndexY >= m_TileCountY)
	{
		return nullptr;
	}

	return m_vecTile[IndexY * m_TileCountX + IndexX];
}

CTile* CTileMap::GetTile(int Index)
{
	return m_vecTile[Index];
}

CTile* CTileMap::GetTile(int IndexX, int IndexY)
{
	return m_vecTile[IndexY * m_TileCountX + IndexX];
}

int CTileMap::GetTileIndexX(float PosX)
{
	int IndexX = (int)(PosX / m_TileSize.x);

	if (IndexX < 0 || IndexX >= m_TileCountX)
	{
		return -1;
	}

	return IndexX;
}

int CTileMap::GetTileIndexY(float PosY)
{
	int IndexY = (int)(PosY / m_TileSize.y);

	if (IndexY < 0 || IndexY >= m_TileCountY)
	{
		return -1;
	}

	return IndexY;
}

int CTileMap::GetTileIndex(const Vector2& Pos)
{
	int IndexX = GetTileIndexX(Pos.x);
	int IndexY = GetTileIndexY(Pos.y);

	if (IndexX == -1 || IndexY == -1)
	{
		return -1;
	}

	return IndexY * m_TileCountX + IndexX;
}

int CTileMap::GetOriginTileIndexX(float PosX)
{
	return (int)(PosX / m_TileSize.x);
}

int CTileMap::GetOriginTileIndexY(float PosY)
{
	return (int)(PosY / m_TileSize.y);;
}

void CTileMap::TileImageAllClear()
{
	size_t Size = m_vecTile.size();

	for (size_t i = 0; i < Size; i++)
	{
		m_vecTile[i]->SetTileTexture(nullptr);
	}
}

void CTileMap::Start()
{
	CMapBase::Start();
}

bool CTileMap::Init()
{
	CMapBase::Init();

	return true;
}

void CTileMap::Update(float DeltaTime)
{
	CMapBase::Update(DeltaTime);

	if (!m_vecTile.empty())
	{
		CCamera* Camera = m_Scene->GetCamera();

		Vector2 CameraPos = Camera->GetPos();
		Vector2 Resolution = Camera->GetResolution();

		m_StartX = (int)(CameraPos.x / m_TileSize.x);
		m_StartY = (int)(CameraPos.y / m_TileSize.y);
		m_EndX = (int)((CameraPos.x  + Resolution.x) / m_TileSize.x);
		m_EndY = (int)((CameraPos.y + Resolution.y) / m_TileSize.y);

		m_StartX = m_StartX < 0 ? 0 : m_StartX;
		m_StartY = m_StartY < 0 ? 0 : m_StartY;
		m_EndX = m_EndX >= m_TileCountX ? m_TileCountX - 1 : m_EndX;
		m_EndY = m_EndY >= m_TileCountY ? m_TileCountY - 1 : m_EndY;

		for (int i = m_StartY; i <= m_EndY; i++)
		{
			for (int j = m_StartX; j <= m_EndX; j++)
			{
				m_vecTile[i * m_TileCountX + j]->Update(DeltaTime);
			}
		}
	}
}

void CTileMap::PostUpdate(float DeltaTime)
{
	CMapBase::PostUpdate(DeltaTime);

	if (!m_vecTile.empty())
	{
		if (m_StartX == -1 || m_StartY == -1 || m_EndX == -1 || m_EndY == -1)
		{
			return;
		}

		for (int i = m_StartY; i <= m_EndY; i++)
		{
			for (int j = m_StartX; j <= m_EndX; j++)
			{
				m_vecTile[i * m_TileCountX + j]->PostUpdate(DeltaTime);
			}
		}
	}
}

void CTileMap::PrevRender()
{
	CMapBase::PrevRender();

	if (!m_vecTile.empty())
	{
		if (m_StartX == -1 || m_StartY == -1 || m_EndX == -1 || m_EndY == -1)
		{
			return;
		}

		for (int i = m_StartY; i <= m_EndY; i++)
		{
			for (int j = m_StartX; j <= m_EndX; j++)
			{
				m_vecTile[i * m_TileCountX + j]->PrevRender();
			}
		}
	}
}

void CTileMap::Render(HDC hDC)
{
	CMapBase::Render(hDC);

	if (!m_vecTile.empty())
	{
		if (m_StartX == -1 || m_StartY == -1 || m_EndX == -1 || m_EndY == -1)
		{
			return;
		}

		for (int i = m_StartY; i <= m_EndY; i++)
		{
			for (int j = m_StartX; j <= m_EndX; j++)
			{
				m_vecTile[i * m_TileCountX + j]->Render(hDC);
			}
		}
	}
}

void CTileMap::Save(FILE* pFile)
{
	CMapBase::Save(pFile);

	fwrite(&m_TileCountX, sizeof(int), 1, pFile);
	fwrite(&m_TileCountY, sizeof(int), 1, pFile);
	fwrite(&m_TileSize, sizeof(Vector2), 1, pFile);
	fwrite(&m_StartX, sizeof(int), 1, pFile);
	fwrite(&m_StartY, sizeof(int), 1, pFile);
	fwrite(&m_EndX, sizeof(int), 1, pFile);
	fwrite(&m_EndY, sizeof(int), 1, pFile);

	if (m_TileTexture)
	{
		bool Tex = true;
		fwrite(&Tex, sizeof(bool), 1, pFile);

		m_TileTexture->Save(pFile);
	}

	else
	{
		bool Tex = false;
		fwrite(&Tex, sizeof(bool), 1, pFile);
	}

	int	TileCount = (int)m_vecTile.size();
	fwrite(&TileCount, sizeof(int), 1, pFile);

	for (int i = 0; i < TileCount; ++i)
	{
		m_vecTile[i]->Save(pFile);
	}
}

void CTileMap::Load(FILE* pFile)
{
	CMapBase::Load(pFile);

	fread(&m_TileCountX, sizeof(int), 1, pFile);
	fread(&m_TileCountY, sizeof(int), 1, pFile);
	fread(&m_TileSize, sizeof(Vector2), 1, pFile);
	fread(&m_StartX, sizeof(int), 1, pFile);
	fread(&m_StartY, sizeof(int), 1, pFile);
	fread(&m_EndX, sizeof(int), 1, pFile);
	fread(&m_EndY, sizeof(int), 1, pFile);

	bool	Tex = true;
	fread(&Tex, sizeof(bool), 1, pFile);

	if (Tex)
	{
		m_TileTexture = CTexture::LoadStatic(pFile, m_Scene);
	}

	int	TileCount = 0;
	fread(&TileCount, sizeof(int), 1, pFile);

	size_t	TileSize = m_vecTile.size();

	for (size_t i = 0; i < TileSize; ++i)
	{
		SAFE_DELETE(m_vecTile[i]);
	}

	m_vecTile.clear();

	for (int i = 0; i < TileCount; ++i)
	{
		CTile* Tile = new CTile;
		Tile->m_Scene = m_Scene;

		m_vecTile.push_back(Tile);

		m_vecTile[i]->Load(pFile);
	}


	m_Size = m_TileSize * Vector2((float)m_TileCountX, (float)m_TileCountY);

	CCamera* Camera = m_Scene->GetCamera();
	Camera->SetWorldResolution(m_Size);
}
