#pragma once
#include "CommonInclude.h"
namespace ci
{
	class Time
	{
	public:
		static void Initiailize();
		static void Update();
		static void Render(HDC hdc);

		__forceinline static double DeltaTime() { return mDeltaTime; }
		__forceinline static float FPS() { return mfps; }

	private:
		static double mDeltaTime;
		static double mSecond;
		static LARGE_INTEGER mCpuFrequency;
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurFrequency;
		static float mfps;
	};
}

