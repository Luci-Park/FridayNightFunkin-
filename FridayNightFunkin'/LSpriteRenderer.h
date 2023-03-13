#pragma once
#include "LComponent.h"
#include "LSprite.h"
namespace fnf
{
	class Image;
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetImage(Image* image, Sprite sp);
		void SetImage(const std::wstring& key, const std::wstring& path);
		void SetSprite(Sprite sprite) { mSprite = sprite; }
		void SetOffset(Vector2 offset) { mOffset = offset; }
	private:
		Image* mImage;
		Sprite mSprite;
		Vector2 mOffset;
	};
}

