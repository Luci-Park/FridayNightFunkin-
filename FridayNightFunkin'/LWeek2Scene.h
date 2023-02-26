#pragma once
#include"LScene.h"
namespace ci
{
	class Week2Scene : public Scene
	{
	public:
		Week2Scene();
		~Week2Scene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
	};
}
