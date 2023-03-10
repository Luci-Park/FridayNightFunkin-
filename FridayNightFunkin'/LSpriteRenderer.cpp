#include "LSpriteRenderer.h"
#include "LGameObject.h"
#include "LImage.h"
namespace fnf
{
	SpriteRenderer::SpriteRenderer()
		:Component(eComponentType::SpriteRenderer),
		mImage(nullptr),
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
		drawPos.x -= size.x * scale.x* 0.5;
		drawPos.y -= size.y * scale.y * 0.5;

		TransparentBlt(hdc, 0, 0,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetHdc(), drawPos.x, drawPos.y,
			mImage->GetWidth() * scale.x,
			mImage->GetHeight() * scale.y,
			RGB(255, 0, 255));
	}
	void SpriteRenderer::Release()
	{
		if (mImage != nullptr)
		{
			delete mImage;
			mImage = nullptr;
		}
	}
}