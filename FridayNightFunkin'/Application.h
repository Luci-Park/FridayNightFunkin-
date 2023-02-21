#pragma once
#include "Engine.h"
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

		HWND GetHWnd() { return mHwnd; }

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

