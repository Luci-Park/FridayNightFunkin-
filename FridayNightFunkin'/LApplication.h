#pragma once
#include "LuciEngine.h"
namespace ci
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

		HWND GetHWnd() { return mHwnd; }
		HDC GetHdc() { return mHdc; }
		UINT GetScreenWidth() { return mWidth; }
		UINT GetScreenHeight() { return mHeight; }

	private:
		HWND mHwnd;
		HDC mHdc;

		HBITMAP mBackBuffer;
		HDC mBackHDC;

		UINT mWidth;
		UINT mHeight;

		Vector2 mPos;

	};
}

