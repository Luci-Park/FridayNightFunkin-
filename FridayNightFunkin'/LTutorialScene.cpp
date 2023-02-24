#include "LTutorialScene.h"
namespace fnf
{
	fnf::TutorialScene::TutorialScene()
		:Scene(L"Tutorial", eSceneType::Tutorial)
	{
	}
	TutorialScene::~TutorialScene()
	{
	}
    void TutorialScene::Initialize()
    {
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
        Scene::Release();
    }
    void TutorialScene::OnExit()
    {
        Scene::Release();
    }
}