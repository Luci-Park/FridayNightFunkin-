#include "LSplashScene.h"
#include "LColorBlock.h"
#include "LBoyFriend.h"
#include "LImage.h"
#include "LResources.h"
namespace fnf
{
    SplashScene::SplashScene()
        :Scene(L"Splash", eSceneType::Splash)
    {
        mImage = Resources::Load<Image>(L"Test", L"..\\FNFAssets\\Art\\24Bit\\Characters\\Boyfriend\\Idle\\tile001.bmp");
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
        BitBlt(hdc, 0,0, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
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