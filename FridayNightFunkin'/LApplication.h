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

		HWND GetHwnd() { return mHwnd; }
		HDC GetHdc() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		Vector2 GetCenter() { return Vector2((float)mWidth / 2, (float)mHeight / 2); }

	private:
		void clear();

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