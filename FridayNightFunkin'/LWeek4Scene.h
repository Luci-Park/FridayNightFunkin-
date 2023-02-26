#pragma once
#include"LScene.h"
namespace ci
{
	class Week4Scene : public Scene
	{
	public:
		Week4Scene();
		~Week4Scene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};
}
