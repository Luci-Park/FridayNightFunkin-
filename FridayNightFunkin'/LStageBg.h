#pragma once
#include "LGameObject.h"
#include "LImage.h"
namespace fnf
{
	class SpriteRenderer;
	class StageBg : public GameObject
	{
	public:

		StageBg();
		~StageBg();

		virtual void Initialize()override;
		virtual void Update()override;
		virtual void Render(HDC hdc)override;
		virtual void Release()override;
	private:
		SpriteRenderer* mSprite;
	};
}

