#include "LColorBlock.h"
#include "LApplication.h"
extern fnf::Application application;
namespace fnf
{
	ColorBlock::ColorBlock(COLORREF color)
	{
		mHeight = application.GetScreenHeight() + 2;
		mWidth = application.GetScreenWidth() + 2;
		SetColor(color);
	}
	ColorBlock::ColorBlock(COLORREF color, UINT width, UINT height)
		:mHeight(height), mWidth(height)
	{
		SetColor(color);
	}
	ColorBlock::~ColorBlock()
	{
	}
	void ColorBlock::Initialize()
	{
		SetName(L"BlackBackground");
		GameObject::Initialize();
	}
	void ColorBlock::Update()
	{
		GameObject::Update();
	}
	void ColorBlock::Render(HDC hdc)
	{
		HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, mBrush);
		Rectangle(hdc, -1, -1, mWidth, mHeight);
		SelectObject(hdc, hOldBrush);
		GameObject::Render(hdc);
	}
	void ColorBlock::Release()
	{
		if (mBrush != nullptr)
			DeleteObject(mBrush);
		GameObject::Release();
	}
	void ColorBlock::SetColor(COLORREF color)
	{
		if (mBrush != nullptr)
			DeleteObject(mBrush);
		mRGB = color;
		mBrush = CreateSolidBrush(color);
	}
}
