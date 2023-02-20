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

		Vector2 mPos;

		//Scene mScene[256];
	};
}

