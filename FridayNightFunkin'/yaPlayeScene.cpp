#include "yaPlayeScene.h"
#include "yaCuphead.h"
#include "LInput.h"
#include "LSceneManager.h"
#include "yaMonster.h"
#include "LCollisionManager.h"
#include "LTransform.h"
#include "LCamera.h"
#include "LObject.h"
#include "LBoyFriend.h"

namespace fnf
{
	PlayeScene::PlayeScene()
	{
	}

	PlayeScene::~PlayeScene()
	{
	}

	void PlayeScene::Initialize()
	{
		Scene::Initialize();

		object::Instantiate<Cuphead>(Vector2(400.0f, 400.0f), eLayerType::Player);
		object::Instantiate<Boyfriend>(Vector2(400.0f, 400.0f), eLayerType::Player);
		object::Instantiate<Monster>(Vector2(500.0f, 500.0f), eLayerType::Monster);
		object::Instantiate<Monster>(Vector2(500.0f, 500.0f), eLayerType::Monster);
	}

	void PlayeScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}

		Scene::Update();
	}

	void PlayeScene::Render(HDC hdc)
	{
		//Super::Tick();
		Scene::Render(hdc);
	}

	void PlayeScene::Release()
	{
		Scene::Release();
	}
	void PlayeScene::OnEnter()
	{
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::Monster, true);
	}
	void PlayeScene::OnExit()
	{
		//mCuphead->SetPos(Vector2{ 0.0f, 0.0f });
	}
}
