#include "LApplication.h"
#include "LSceneManager.h"
#include "LTime.h"
#include "LInput.h"
namespace fnf
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);
		mWidth = 1600;
		mHeight = 900;
		//비트맵 해상도 설정을 위해 윈도우 크기 계산
		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		//윈도우 크기 변경 및 출력 설정
		SetWindowPos(mHwnd, nullptr,
			100, 50,
			rect.right - rect.left,
			rect.bottom - rect.top,
			0);
		ShowWindow(hWnd, true);

		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		mBackHDC = CreateCompatibleDC(mHdc);

		//기존 비트맵을 받고 새로 생성한 걸로 변경.
		HBITMAP defaultBitmap = (HBITMAP)SelectObject(mBackHDC, mBackBuffer);
		DeleteObject(defaultBitmap);

		Time::Initiailize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		SceneManager::Update();
		SetTitle();
	}

	void Application::Render()
	{
		ClearScreen();

		Time::Render(mBackHDC);
		Input::Render(mBackHDC);
		SceneManager::Render(mBackHDC);
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}
	void Application::Release()
	{
		SceneManager::Release();
	}
	Vector2 Application::GetScreenCenter()
	{
		Vector2 center;
		center.y = mHeight / 2;
		center.x = mWidth / 2;
		return center;
	}
	void Application::SetTitle()
	{
		std::wstring title = SceneManager::GetActiveScene()->GetName();
		std::wstring fps = std::to_wstring((UINT)Time::FPS());
		title += L" - FPS : " + fps;
		SetWindowText(mHwnd, title.c_str());
	}
	void Application::ClearScreen()
	{
		HBRUSH bgBrush = CreateSolidBrush(RGB(255, 255, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHDC, bgBrush);
		Rectangle(mBackHDC, -1, -1, mWidth + 2, mHeight + 2);
		SelectObject(mBackHDC, oldBrush);
		DeleteObject(bgBrush);
	}
}