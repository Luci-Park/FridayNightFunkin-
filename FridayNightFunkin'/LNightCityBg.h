#pragma once
#include "LGameObject.h"
#include "LImage.h"
namespace fnf
{
	class NightCityBg : public GameObject
	{
	public:

		NightCityBg();
		~NightCityBg();

		virtual void Initialize()override;
		virtual void Update()override;
		virtual void Render(HDC hdc)override;
		virtual void Release()override;
	private:
		Image* mImage;
		Vector2 imagePivot;
	};
}

