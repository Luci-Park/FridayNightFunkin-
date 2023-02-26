#include "LStageBg.h"
#include "LResources.h"
#include "LApplication.h"
#include "LTransform.h"
extern ci::Application application;
namespace ci
{
	StageBg::StageBg()
		:mImage(NULL)
	{
	}
	StageBg::~StageBg()
	{
	}
	void StageBg::Initialize()
	{
		mImage = Resources::Load<Image>(eResourceKeys::StageBackground);
		imagePivot.x = -((int)mImage->GetWidth()) / 2;
		imagePivot.x = -((int)mImage->GetHeight()) / 2;
		transform->SetPos({ application.GetScreenWidth()/2, application.GetScreenHeight() / 2 });
		GameObject::Initialize();
	}
	void StageBg::Update()
	{
		GameObject::Update();
	}
	void StageBg::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		//Vector2 pos = transform->GetPos();
		//pos = imagePivot;
		//BitBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc()			, 0, 0, SRCCOPY);
		TransparentBlt(hdc, 0, 0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), RGB(255,0,255));
	}
	void StageBg::Release()
	{
		GameObject::Release();
	}
}