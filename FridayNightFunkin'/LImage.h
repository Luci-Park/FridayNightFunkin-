#pragma once
#include "LResource.h"
namespace fnf
{
	class Image : public Resource
	{
	public:
		Image();
		~Image();

		virtual HRESULT Load(const std::wstring& path) override;

		HDC GetHdc() { return mHdc; }
		HBITMAP GetBitmap() { return mBitmap; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

		static const std::wstring defaultPath;

	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
	};
}

