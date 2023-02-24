#include "LLimousineBg.h"
#include "LResources.h"
namespace fnf
{
	LimusineBg::LimusineBg()
		:mImage(NULL)
	{
	}
	LimusineBg::~LimusineBg()
	{
	}
	void LimusineBg::Initialize()
	{
		mImage = Resources::Load<Image>(eResourceKeys::LimousineBackground);
		GameObject::Initialize();
	}
	void LimusineBg::Update()
	{
		GameObject::Update();
	}
	void LimusineBg::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void LimusineBg::Release()
	{
		GameObject::Release();
	}
}

