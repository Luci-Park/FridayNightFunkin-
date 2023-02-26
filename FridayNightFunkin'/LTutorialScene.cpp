#include "LTutorialScene.h"
#include "LStageBg.h"
namespace ci
{
	ci::TutorialScene::TutorialScene()
		:Scene(L"Tutorial", eSceneType::Tutorial)
	{
	}
	TutorialScene::~TutorialScene()
	{
	}
    void TutorialScene::Initialize()
    {
        AddGameObject(new StageBg(), eLayerType::Background);
        Scene::Initialize();
    }
    void TutorialScene::Update()
    {
        Scene::Update();
    }
    void TutorialScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void TutorialScene::Release()
    {
        Scene::Release();
    }
    void TutorialScene::OnEnter()
    {
        Scene::OnEnter();
    }
    void TutorialScene::OnExit()
    {
        Scene::OnExit();
    }
}