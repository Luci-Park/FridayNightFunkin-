#include "LStoryModeScene.h"
namespace fnf
{
	StoryModeScene::StoryModeScene()
		:Scene(L"StoryMode", eSceneType::StoryMode)
	{
	}
	StoryModeScene::~StoryModeScene()
	{
	}
    void StoryModeScene::Initialize()
    {
        Scene::Initialize();
    }
    void StoryModeScene::Update()
    {
        Scene::Update();
    }
    void StoryModeScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void StoryModeScene::Release()
    {
        Scene::Release();
    }
    void StoryModeScene::OnEnter()
    {
        Scene::Release();
    }
    void StoryModeScene::OnExit()
    {
        Scene::Release();
    }
}