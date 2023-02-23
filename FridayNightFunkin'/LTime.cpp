#include "LTime.h"
#include "LApplication.h"

//다른 cpp의 전역변수를 가져오는 변수: extern
extern fnf::Application application;
namespace fnf
{
	double Time::mDeltaTime = 0.01f;
	double Time::mSecond = 0.0f;
	LARGE_INTEGER Time::mCpuFrequency = {};
	LARGE_INTEGER Time::mPrevFrequency = {};
	LARGE_INTEGER Time::mCurFrequency = {};
	void Time::Initiailize()
	{
		//시스템이 시작된 이후 지난 시간을 밀리세컨드 단위로 알려줌. 
		QueryPerformanceFrequency(&mCpuFrequency);
		//현재 CPU 틱
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&mCurFrequency);
		double differenceFrequency = mCurFrequency.QuadPart - mPrevFrequency.QuadPart;
		mDeltaTime = differenceFrequency / mCpuFrequency.QuadPart;
		mPrevFrequency.QuadPart = mCurFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		//FPS 계산
		mSecond += mDeltaTime;
		if (mSecond > 1.0f)
		{
			HWND hWnd = application.GetHWnd();
			wchar_t szFloat[50] = {};
			float FPS = 1.0f / (float)mDeltaTime;
			swprintf_s(szFloat, 50, L"FPS : %d", (UINT)FPS);
			SetWindowText(hWnd, szFloat);

			mSecond = 0.0f;
		}
	}
}
