#include "LSpriteRenderer.h"
#include "LResources.h"
#include "LTransform.h"
#include "LGameObject.h"
#include "LCamera.h"
#include "LImage.h"
namespace fnf
{
	SpriteRenderer::SpriteRenderer()
		: Component(eComponentType::SpriteRenderer)
		, mImage(nullptr)
		, mOffset(Vector2::Zero)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{ 
		Transform* tr = GetOwner()->mTransform;
		Vector2 scale = tr->GetScale();
		Vector2 pos = tr->GetPos();
		pos = Camera::CaluatePos(pos);
		pos += mOffset + mSprite.offset;
		TransparentBlt(hdc, pos.x, pos.y, mSprite.size.x * scale.x , mSprite.size.y * scale.y,
			mImage->GetHdc(), 0, 0, mSprite.size.x, mSprite.size.y, RGB(255, 0, 255));
	}
	void SpriteRenderer::Release()
	{
	}
	void SpriteRenderer::SetImage(Image* image, Sprite sp)
	{
		mImage = image;
		mSprite = sp;
	}
}