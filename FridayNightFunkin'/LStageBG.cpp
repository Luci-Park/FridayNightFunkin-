#include "LStageBG.h"
#include "LSpriteRenderer.h"
#include "LApplication.h"
extern fnf::Application application;
namespace fnf
{
	StageBG::StageBG()
	{
	}
	StageBG::~StageBG()
	{
	}
	void StageBG::Initialize()
	{
		GetSprite();
		mTransform->SetPos(application.GetCenter());
		GameObject::Initialize();
	}
	void StageBG::Update()
	{
		GameObject::Update();
	}
	void StageBG::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void StageBG::Release()
	{
		GameObject::Release();
	}
	void StageBG::GetSprite()
	{
		mRenderer = AddComponent<SpriteRenderer>();
		mRenderer->SetImage(L"stageBg", L"..\\FNFAssets\\Art\\24Bit\\Characters\\Backgrounds\\Week1\\stage.bmp");
	}
}