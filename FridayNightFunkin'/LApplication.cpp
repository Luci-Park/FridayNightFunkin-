#include "LApplication.h"
#include "LSceneManager.h"
#include "LTime.h"
#include "LInput.h"
#include "LCollisionManager.h"
#include "LCamera.h"
#include "LResources.h"

namespace fnf
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
	{
	}

	Application::~Application()
	{
		//SceneManager::Release();
		//Time::Release();
	}

	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);
		mWidth = 1280;
		mHeight = 720;
		//(160:9)

		RECT rect = { 0, 0, mWidth , mHeight };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		SetWindowPos(mHwnd
			, nullptr, 100, 50
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(hWnd, true);

		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		mBackHDC = CreateCompatibleDC(mHdc);
		
		HBITMAP defaultBitmap	
			= (HBITMAP)SelectObject(mBackHDC, mBackBuffer);
		DeleteObject(defaultBitmap);

		Time::Initiailize();
		Input::Initialize();
		SceneManager::Initialize();
		Camera::Initiailize();
	}

	void Application::Run()
	{
		Update();
		Render();
		SceneManager::Destroy();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		Camera::Update();

		SceneManager::Update();
		CollisionManager::Update();
	}

	void Application::Render()
	{
		clear();
		Time::Render(mBackHDC);
		Input::Render(mBackHDC);
		SceneManager::Render(mBackHDC);
		Camera::Render(mBackHDC);
		SetHalfTransparency(mBackHDC);
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}
	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}
	void Application::clear()
	{
		HBRUSH grayBrush = CreateSolidBrush(RGB(121, 121, 121));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHDC, grayBrush);
		Rectangle(mBackHDC, -1, -1, mWidth + 2, mHeight + 2);
		SelectObject(mBackHDC, oldBrush);
		DeleteObject(grayBrush);
	}
	void Application::SetHalfTransparency(HDC hdc)
	{
		HDC hdcBuffer = CreateCompatibleDC(hdc);
		HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdcBuffer, blackBrush);
		Rectangle(hdcBuffer, -1, -1, mWidth + 2, mHeight + 2); 

		BLENDFUNCTION blend = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
		AlphaBlend(hdc, 0, 0, mWidth, mHeight, hdcBuffer, 0, 0, mWidth, mHeight, blend);

		SelectObject(hdcBuffer, oldBrush);
		DeleteObject(blackBrush);
		DeleteDC(hdcBuffer);
	}
}
