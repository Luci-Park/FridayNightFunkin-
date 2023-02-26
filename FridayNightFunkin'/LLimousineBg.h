#pragma once
#include "LGameObject.h"
#include "LImage.h"
namespace ci
{
	class LimusineBg : public GameObject
	{
	public:

		LimusineBg();
		~LimusineBg();

		virtual void Initialize()override;
		virtual void Update()override;
		virtual void Render(HDC hdc)override;
		virtual void Release()override;
	private:
		Image* mImage;
		Vector2 imagePivot;
	};
}

