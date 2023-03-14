#include "LCamera.h"
#include "LApplication.h"
#include "LGameObject.h"
#include "LTransform.h"
#include "LInput.h"
#include "LTime.h"

extern fnf::Application application;
namespace fnf
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;
	Camera::eFadeState Camera::meFadeState = Camera::eFadeState::Idle;

	void Camera::Initiailize()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);
	}

	void Camera::Update()
	{

		if (Input::GetKey(eKeyCode::LEFT))
			mLookPosition.x -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::RIGHT))
			mLookPosition.x += 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::UP))
			mLookPosition.y -= 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::DOWN))
			mLookPosition.y += 100.0f * Time::DeltaTime();


		if (mTarget != nullptr)
		{
			mLookPosition
				= mTarget->GetComponent<Transform>()->GetPos();
		}
		else
		{
			Clear();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	void Camera::Render(HDC hdc)
	{
		if (meFadeState == FadingIn)
			FadeIn(hdc);
	}
	void Camera::Clear()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);
		mDistance = Vector2::Zero;
	}
	void Camera::StartFadeIn()
	{
		if (meFadeState == Idle)
			meFadeState = FadingIn;
	}
	void Camera::FadeIn(HDC hdc)
	{
		static int alpha = 255;
		static bool isFading = true;
		if (isFading == false)
		{
			alpha = 255;
			isFading = true;
		} 
		int width = application.GetWidth();
		int height = application.GetHeight();

		HDC hdcBuffer = CreateCompatibleDC(hdc);
		HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdcBuffer, blackBrush);
		Rectangle(hdcBuffer, -1, -1, width + 2, height + 2);
		BitBlt(hdcBuffer, 0, 0, width, height, hdc, 0, 0, SRCCOPY);

		if (isFading)
		{
			alpha -= static_cast<int>(Time::DeltaTime() * 255);
			if (alpha < 0)
			{
				alpha = 0;
				isFading = false;
				meFadeState = Idle;
			}
		}

		BLENDFUNCTION blend = { AC_SRC_OVER, 0, alpha, AC_SRC_ALPHA };
		AlphaBlend(hdc, 0, 0, width, height, hdcBuffer, 0, 0, width, height, blend);

		SelectObject(hdcBuffer, oldBrush);
		DeleteObject(blackBrush);
		DeleteDC(hdcBuffer);
	}
}
