#include "LImage.h"
#include "LApplication.h"
extern fnf::Application application;
namespace fnf
{
	Image::Image()
		:mBitmap(NULL)
		,mHdc(NULL)
		,mWidth(0)
		,mHeight(0)
	{
	}
	Image::~Image()
	{
	}
	HRESULT Image::Load(const std::wstring& path){
		mBitmap = (HBITMAP)LoadImageW(nullptr,
			path.c_str(), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		if (mBitmap == nullptr)
			return E_FAIL;
		BITMAP bitInfo = {};
		GetObject(mBitmap, sizeof(BITMAP), &bitInfo);
		mWidth = bitInfo.bmWidth;
		mHeight = bitInfo.bmHeight;

		HDC mainDC = application.GetHdc();
		mHdc = CreateCompatibleDC(mainDC);

		HBITMAP oldBitMap = (HBITMAP)SelectObject(mHdc, mBitmap);
		DeleteObject(oldBitMap);

		return S_OK;
	}
}