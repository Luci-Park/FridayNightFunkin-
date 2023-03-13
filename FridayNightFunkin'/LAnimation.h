#pragma once
#include "LEntity.h"
#include "LSprite.h"
namespace fnf
{
	class Image;
	class Animator;
	class Animation : public Entity
	{
	public:
		struct Frame
		{
			Sprite sp;
			float duration;

			Frame()
				: sp()
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		void Initialize();
		void Update();
		void Render(HDC hdc);
		void Create(Image* sheet, Vector2 leftTop, UINT coulmn, UINT row, UINT spriteLength, Vector2 offset, float duration);
		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(Animator* animator) { mAnimator = animator; }
		void SetAnimationName(const std::wstring& name) { mAnimationName = name; }
		std::wstring& GetAnimationName() { return mAnimationName; }

	private:
		Animator* mAnimator;
		Image* mSheetImage;
		std::vector<Frame> mSpriteSheet;
		std::wstring mAnimationName;
		float mTime;
		bool mbComplete;
		int mSpriteIndex;
	};
}
