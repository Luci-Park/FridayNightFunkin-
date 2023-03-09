#pragma once
#include "LComponent.h"
namespace fnf
{
	class Image;
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		virtual void Initialize() override;
		virtual void Update()override;
		virtual void Render(HDC hdc)override;
		virtual void Release()override;

	private:
			Image* mImage;
	};
}

