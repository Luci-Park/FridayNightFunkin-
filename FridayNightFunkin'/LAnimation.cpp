#include "LAnimation.h"
#include "LTime.h"
#include "LImage.h"
#include "LAnimator.h"
#include "LTransform.h"
#include "LGameObject.h"
#include "LCamera.h"

namespace fnf
{
    Animation::Animation()
        : mAnimator(nullptr)
        , mSheetImage(nullptr)
        , mTime(0.0f)
        , mbComplete(false)
        , mSpriteIndex(0)
        , mAnimationName(L"")
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

        mTime += Time::DeltaTime();
        if (mSpriteSheet[mSpriteIndex].duration < mTime)
        {
            mTime = 0.0f;

            if (mSpriteSheet.size() <= mSpriteIndex + 1)
            {
                mbComplete = true;
            }
            else
            {
                mSpriteIndex++;
            }
        }
    }

    void Animation::Render(HDC hdc)
    {
        Transform* tr 
            = mAnimator->GetOwner()->GetComponent<Transform>();
        Vector2 scale = tr->GetScale();

        Vector2 pos = tr->GetPos();
        pos = Camera::CaluatePos(pos);
        pos += mSpriteSheet[mSpriteIndex].sp.offset;
        pos.x -= mSpriteSheet[mSpriteIndex].sp.size.x / 2.0f;
        pos.y -= mSpriteSheet[mSpriteIndex].sp.size.y;

        TransparentBlt(hdc, pos.x, pos.y
            , mSpriteSheet[mSpriteIndex].sp.size.x * scale.x
            , mSpriteSheet[mSpriteIndex].sp.size.y * scale.y
            , mSheetImage->GetHdc()
            , mSpriteSheet[mSpriteIndex].sp.leftTop.x, mSpriteSheet[mSpriteIndex].sp.leftTop.y
            , mSpriteSheet[mSpriteIndex].sp.size.x, mSpriteSheet[mSpriteIndex].sp.size.y,
            RGB(255, 0, 255));
    }

    void Animation::Create(Image* sheet, Vector2 leftTop
        , UINT coulmn, UINT row, UINT spriteLength
        , Vector2 offset, float duration)
    {
        mSheetImage = sheet;

        //UINT coulmn = mSheetImage->GetWidth() / size.x;
        Vector2 size = Vector2::One;
        size.x = mSheetImage->GetWidth() / (float)coulmn;
        size.y = mSheetImage->GetHeight() / (float)row;

        for (size_t i = 0; i < spriteLength; i++)
        {
            Frame spriteInfo;

            spriteInfo.sp.leftTop.x = leftTop.x + (size.x * i);
            spriteInfo.sp.leftTop.y = leftTop.y;
            spriteInfo.sp.size = size;
            spriteInfo.sp.offset = offset;
            spriteInfo.duration = duration;

            mSpriteSheet.push_back(spriteInfo);
        }
    }

    void Animation::Reset()
    {
        mSpriteIndex = 0;
        mTime = 0.0f;
        mbComplete = false;
    }

}
