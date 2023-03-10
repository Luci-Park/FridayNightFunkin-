#include "LAnimation.h"
#include "LTime.h"
#include "LTransform.h"
#include "LImage.h"
#include "LAnimator.h"
#include "LGameObject.h"
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
		Transform* tr
			= mAnimator->GetOwner()->GetComponent<Transform>();
		Vector2 scale = tr->GetScale();
		Vector2 pos = tr->GetPos();
		pos += mFrames[mFrameNum].offset;
		pos.x -= mFrames[mFrameNum].size.x / 2.0f;
		pos.y -= mFrames[mFrameNum].size.y;

		TransparentBlt(hdc, pos.x, pos.y
			, mFrames[mFrameNum].size.x * scale.x
			, mFrames[mFrameNum].size.y * scale.y
			, mSpriteSheet->GetHdc()
			, mFrames[mFrameNum].leftTop.x, mFrames[mFrameNum].leftTop.y
			, mFrames[mFrameNum].size.x, mFrames[mFrameNum].size.y,
			RGB(255, 0, 255));
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