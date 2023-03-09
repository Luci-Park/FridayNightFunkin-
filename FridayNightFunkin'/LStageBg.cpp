#include "LStageBg.h"
#include "LResources.h"
#include "LApplication.h"
#include "LSpriteRenderer.h"
extern fnf::Application application;
namespace fnf
{
	StageBg::StageBg()
	{
		mSprite = AddComponent<SpriteRenderer>();
		mSprite->SetSprite(Resources::Load<Image>(eResourceKeys::StageBackground));
		mTransform->SetPos(application.GetScreenCenter());
	}
	StageBg::~StageBg()
	{
	}
	void StageBg::Initialize()
	{
		GameObject::Initialize();
	}
	void StageBg::Update()
	{
		GameObject::Update();
	}
	void StageBg::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void StageBg::Release()
	{
		GameObject::Release();
	}
}