#pragma once
#include "LuciEngine.h"

namespace fnf
{
	class GameObject;
	class Camera
	{
	public:
		static void Initiailize();
		static void Update();
		static void Render(HDC hdc);
		static void Clear();

		static void SetTarget(GameObject* target) { mTarget = target; }
		static Vector2 CaluatePos(Vector2 pos) { return pos - mDistance; }

		static void StartFadeIn();

	private:
		static void FadeIn(HDC hdc);

	private:
		static Vector2 mResolution;
		static Vector2 mLookPosition;
		static Vector2 mDistance;
		static GameObject* mTarget;
		
		static enum eFadeState {FadingIn, FadingOut, Idle};
		static eFadeState meFadeState;
	};
}
