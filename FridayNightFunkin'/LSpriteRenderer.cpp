#include "LSpriteRenderer.h"
#include "LResources.h"
#include "LTransform.h"
#include "LGameObject.h"
#include "LCamera.h"
#include "LImage.h"
namespace fnf
{
	SpriteRenderer::SpriteRenderer()
		:Component(eComponentType::SpriteRenderer)
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
		pos += mOffset;
		pos.x -= mImage->GetWidth() / 2;
		pos.y -= mImage->GetHeight() / 2;
		TransparentBlt(hdc, pos.x, pos.y, mImage->GetWidth() * scale.x, mImage->GetHeight() * scale.y,
			mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(255, 0, 255));
	}
	void SpriteRenderer::Release()
	{
	}
	void SpriteRenderer::SetImage(const std::wstring& name, const std::wstring& path, Vector2 leftTop)
	{
		mImage = Resources::Load<Image>(name, path);
		mLeftTop = leftTop;
	}
}