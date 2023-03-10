#include "LSplashScene.h"
#include "LColorBlock.h"
#include "LBoyFriend.h"
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
        AddGameObject(new ColorBlock(RGB(0, 0, 0)), eLayerType::Background);
        AddGameObject(new BoyFriend(), eLayerType::Player1);
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
        Scene::OnEnter();
    }
    void SplashScene::OnExit()
    {
        Scene::OnEnter();
    }
}