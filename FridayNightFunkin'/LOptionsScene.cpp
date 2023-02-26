#include "LOptionsScene.h"
namespace ci
{
    OptionsScene::OptionsScene()
        :Scene(L"Options", eSceneType::Options)
    {
    }
    OptionsScene::~OptionsScene()
    {
    }
    void OptionsScene::Initialize()
    {
        Scene::Initialize();
    }
    void OptionsScene::Update()
    {
        Scene::Update();
    }
    void OptionsScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void OptionsScene::Release()
    {
        Scene::Release();
    }
    void OptionsScene::OnEnter()
    {
        Scene::OnEnter();
    }
    void OptionsScene::OnExit()
    {
        Scene::OnExit();
    }
}