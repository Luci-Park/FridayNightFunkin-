#pragma once
#include"LScene.h"
namespace ci
{
	class Week1Scene : public Scene
	{
	public:
		Week1Scene();
		~Week1Scene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};
}
