#pragma once
#include"LScene.h"
namespace fnf
{
	class OptionsScene : public Scene
	{
	public:
		OptionsScene();
		~OptionsScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};
}