#pragma once
#include "LComponent.h"
namespace fnf
{
	class Image;
	class Transform;
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		virtual void Initialize() override;
		virtual void Update()override;
		virtual void Render(HDC hdc)override;
		virtual void Release()override;

		void SetSprite(Image* image) { mImage = image; }
		void SetOffset(Vector2 offset) { mOffset = offset;}
		void SetScale(Vector2 scale) { mScale = scale; }
	private:
		Image* mImage;
		Vector2 mOffset;
		Vector2 mScale;
	};
}

