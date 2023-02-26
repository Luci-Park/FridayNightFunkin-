#pragma once
#include "LGameObject.h"
#include "LImage.h"
namespace ci
{
	class HauntedBg : public GameObject
	{
	public:

		HauntedBg();
		~HauntedBg();

		virtual void Initialize()override;
		virtual void Update()override;
		virtual void Render(HDC hdc)override;
		virtual void Release()override;
	private:
		Image* mImage;
		Vector2 imagePivot;
	};
}

