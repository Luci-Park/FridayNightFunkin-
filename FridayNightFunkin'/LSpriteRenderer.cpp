#include "LSpriteRenderer.h"
#include "LGameObject.h"
#include "LImage.h"
namespace fnf
{
	SpriteRenderer::SpriteRenderer()
		:Component(eComponentType::SpriteRenderer),
		mImage(nullptr),
		mScale(Vector2::One),
		mOffset(Vector2::Zero)
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
		if (mImage == nullptr) return;
		Transform* tr = GetOwner()->GetTransform();
		Vector2 scale = tr->GetScale();

		Vector2 drawPos = tr->GetPos() + mOffset;
		Vector2 size = Vector2((int)mImage->GetWidth(), (int)mImage->GetHeight());
		size.x *= mScale.x;
		size.y *= mScale.y;
		drawPos.x -= size.x * 0.5;
		drawPos.y -= size.y * mScale.y * 0.5;

		TransparentBlt(hdc, 0, 0,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetHdc(), drawPos.x, drawPos.y,
			mImage->GetWidth() * mScale.x,
			mImage->GetHeight() * mScale.y,
			RGB(255, 0, 255));
	}
	void SpriteRenderer::Release()
	{
	}
}