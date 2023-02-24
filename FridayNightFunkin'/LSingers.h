#pragma once
#include "LGameObject.h"
namespace fnf
{
	class Singer : public GameObject
	{
	public:
		Singer();
		~Singer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
		Image* mImage;
	};
}
