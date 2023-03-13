#include "yaTitleScene.h"
#include "LInput.h"
#include "LSceneManager.h"
#include "yaCuphead.h"
#include "yaMonster.h"
#include "LCollisionManager.h"
#include "LTransform.h"
#include "LCamera.h"
#include "LObject.h"

namespace fnf
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<Cuphead>(eLayerType::Player);
		object::Instantiate<Monster>(eLayerType::Monster);
	}
	void TitleScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Play);
		}

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
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	}
	void TitleScene::OnExit()
	{
	}
}
