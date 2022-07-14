#pragma once

#include "../Ref.h"

struct TextureInfo
{
    // 이미지파일을 불러와서 HBITMAP을 만들고 이 HBITMAP을 화면에 출력할 메모리DC를 만들어서 출력하게 한다.
    HDC hDC;
    HBITMAP hBmp;
    HBITMAP hPrev;
    BITMAP BmpInfo;

    bool ColorKeyEnable;
    unsigned int ColorKey;

    TCHAR FileName[MAX_PATH];

    TextureInfo() : hDC(0), hBmp(0), hPrev(0), BmpInfo{}, ColorKeyEnable(false), ColorKey(0), FileName{}
    {

    }

    ~TextureInfo()
    {
        // 원래의 HGDIOBJ로 되돌려준다.
        SelectObject(hDC, hPrev);

        // HBITMAP과 HDC를 제거한다.
        DeleteObject(hBmp);

        DeleteDC(hDC);
    }
};

class CTexture :
    public CRef
{
public:
    CTexture();
    ~CTexture();

private:
    ETexture_Type m_TextureType;
    std::vector<TextureInfo*> m_vecTextureInfo;

public:
    ETexture_Type GetTextureType() const
    {
        return m_TextureType;
    }

    unsigned int GetWidth(int idx = 0) const
    {
        return (unsigned int)m_vecTextureInfo[idx]->BmpInfo.bmWidth;
    }

    unsigned int GetHeight(int idx = 0) const
    {
        return (unsigned int)m_vecTextureInfo[idx]->BmpInfo.bmHeight;
    }

    void SetColorKey(const unsigned char r, const unsigned char g, const unsigned char b, int index = 0)
    {
        m_vecTextureInfo[index]->ColorKeyEnable = true;
        m_vecTextureInfo[index]->ColorKey = RGB(r, g, b);
    }

    void SetColorKey(unsigned int ColorKey, int index = 0)
    {
        m_vecTextureInfo[index]->ColorKeyEnable = true;
        m_vecTextureInfo[index]->ColorKey = ColorKey;
    }

public:
    bool LoadTexture(const std::string& Name, const TCHAR* FileName, const std::string& PathName = TEXTURE_PATH);
    bool LoadTextureFullPath(const std::string& Name, const TCHAR* FullPath);
    bool LoadTexture(const std::string& Name, const std::vector<std::wstring>& vecFilName, const std::string& PathName = TEXTURE_PATH);
    void Render(HDC hDC, const Vector2& WindowPos, const Vector2& ImgPos, const Vector2& Size, int Index = 0);

public:
    void Save(FILE* pFile);
    void Load(FILE* pFile);

    static CTexture* LoadStatic(FILE* pFile, class CScene* Scene);
};

