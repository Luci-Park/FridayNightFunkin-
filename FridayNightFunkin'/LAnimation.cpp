#include "LAnimation.h"
#include "LTime.h"
#include "LTransform.h"
#include "LImage.h"
namespace fnf
{
	Animation::Animation()
		: mAnimator(nullptr)
		, mSpriteSheet(nullptr)
		, mTimer(0.0f)
	    , mbComplete(false)
		, mFrameNum(0)
	{
	}
	Animation::~Animation()
	{
	}
	void Animation::Initialize()
	{
	}
	void Animation::Update()
	{
		if (mbComplete == true)
			return;
		mTimer += Time::DeltaTime();
		if (mFrames[mFrameNum].duration < mTimer)
		{
			mTimer = 0.0f;
			if (mFrames.size() <= mFrameNum + 1)
				mbComplete = true;
			else
				mFrameNum++;
		}
	}
	void Animation::Render(HDC hdc)
	{
	}
	void Animation::Create(Image* sheet, Vector2 leftTop, UINT column, UINT row, UINT spriteLength, Vector2 offset, float duration)
	{
		mSpriteSheet = sheet;
		Vector2 size = Vector2::One;
		size.x = mSpriteSheet->GetWidth() / (float)column;
		size.y = mSpriteSheet->GetHeight() / (float)row;
		
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite spriteInfo;
			spriteInfo.leftTop.x = leftTop.x + (size.x * i);
			spriteInfo.leftTop.y = leftTop.y;
			spriteInfo.size = size;
			spriteInfo.offset = offset;
			spriteInfo.duration = duration;
			mFrames.push_back(spriteInfo);
		}
	}
	void Animation::Reset()
	{
		mFrameNum = 0;
		mTimer = 0.0f;
		mbComplete = false;
	}
}