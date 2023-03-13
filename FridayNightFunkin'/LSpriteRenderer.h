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
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void SetImage(const std::wstring& name, const std::wstring& path, Vector2 leftTop);
		void SetScale(Vector2 scale) { mScale = scale; }
		void SetOffset(Vector2 offset) { mOffset = offset; }
	private:
		Image* mImage;
		Vector2 mLeftTop;
		Vector2 mScale;
		Vector2 mOffset;

	};
}

