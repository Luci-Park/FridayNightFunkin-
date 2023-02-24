#include "LTitleScene.h"
namespace fnf
{
	TitleScene::TitleScene()
		:Scene(L"Title", eSceneType::Title)
	{
	}
	TitleScene::~TitleScene()
	{
	}
    void TitleScene::Initialize()
    {
        Scene::Initialize();
    }
    void TitleScene::Update()
    {
        Scene::Update();
    }
    void TitleScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void TitleScene::Release()
    {
        Scene::Release();
    }
    void TitleScene::OnEnter()
    {
        Scene::Release();
    }
    void TitleScene::OnExit()
    {
        Scene::Release();
    }
}