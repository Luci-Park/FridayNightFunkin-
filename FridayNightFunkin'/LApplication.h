#pragma once
#include "LuciEngine.h"
namespace fnf
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hWnd);
		void Run();
		void Update();
		void Render();
		void Release();
		void SetBgColor(COLORREF color) { mBackgroundColor = color; }
		
		Vector2 GetScreenCenter();

		HWND GetHWnd() { return mHwnd; }
		HDC GetHdc() { return mHdc; }
		UINT GetScreenWidth() { return mWidth; }
		UINT GetScreenHeight() { return mHeight; }

	private:
		void SetTitle();
		void ClearScreen();
	private:
		HWND mHwnd;
		HDC mHdc;

		HBITMAP mBackBuffer;
		HDC mBackHDC;

		UINT mWidth;
		UINT mHeight;

		Vector2 mPos;
		COLORREF mBackgroundColor;
	};
}

