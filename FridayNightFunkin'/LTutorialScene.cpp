#include "LTutorialScene.h"
#include "LObject.h"
#include "LBoyFriend.h"
#include "LStageBG.h"
namespace fnf
{
	TutorialScene::TutorialScene()
	{
	}
	TutorialScene::~TutorialScene()
	{
	}
	void TutorialScene::Initialize()
	{
		bf = object::Instantiate<Boyfriend>(this, Vector2(828, 754), eLayerType::Player);
		object::Instantiate<StageBG>(this, eLayerType::BG);
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
	void TutorialScene::Destroy()
	{
		Scene::Destroy();
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