#pragma once
#include"LScene.h"
namespace ci
{
	class Week3Scene : public Scene
	{
	public:
		Week3Scene();
		~Week3Scene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};
}
