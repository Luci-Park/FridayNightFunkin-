#include "LTitleScene.h"
#include "LColorBlock.h"
namespace ci
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
        AddGameObject(new ColorBlock(RGB(0, 0, 0)), eLayerType::Background);
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
        Scene::OnEnter();
    }
    void TitleScene::OnExit()
    {
        Scene::OnExit();
    }
}