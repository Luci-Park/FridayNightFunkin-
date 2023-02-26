#pragma once
#include"LScene.h"
namespace ci
{
	class SplashScene : public Scene
	{
	public:
		SplashScene();
		~SplashScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};
}
