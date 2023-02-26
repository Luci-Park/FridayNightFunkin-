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
		mWidth = 1280;
		mHeight = 720;

		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

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
		std::wstring title = SceneManager::GetActiveScene()->GetName();
		std::wstring fps = std::to_wstring((UINT)Time::FPS());
		title += L" - FPS : " + fps;
		SetWindowText(mHwnd, title.c_str());
	}

	void Application::Render()
	{
		Rectangle(mBackHDC, -1, -1, mWidth + 2, mHeight + 2);
		Time::Render(mHdc);
		Input::Render(mHdc);
		SceneManager::Render(mHdc);
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}
	void Application::Release()
	{
		SceneManager::Release();
	}
}