#pragma once
#include "LResource.h"
#include "LSprite.h"
namespace fnf
{
	class Image : public Resource
	{
	public:
		static Image* Create(const std::wstring& name, UINT widht, UINT height);
		
		Image();
		~Image();

		virtual HRESULT Load(const std::wstring& path) override;

		HDC GetHdc() { return mHdc; }
		HBITMAP GetBitmap() { return mBitmap; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		Sprite GetFullImageSprite();
	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
	};
}
