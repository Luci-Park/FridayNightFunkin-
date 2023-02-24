#include "LSplashScene.h"
namespace fnf
{
    SplashScene::SplashScene()
        :Scene(L"Splash", eSceneType::Splash)
    {
    }
    SplashScene::~SplashScene()
    {
    }
    void SplashScene::Initialize()
    {
        Scene::Initialize();
    }
    void SplashScene::Update()
    {
        Scene::Update();
    }
    void SplashScene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void SplashScene::Release()
    {
        Scene::Release();
    }
    void SplashScene::OnEnter()
    {
        Scene::Release();
    }
    void SplashScene::OnExit()
    {
        Scene::Release();
    }
}