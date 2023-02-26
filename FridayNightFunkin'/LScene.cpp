#include "LScene.h"
#include "LInput.h"
#include "LSceneManager.h"
namespace ci
{
	Scene::Scene(std::wstring sceneName, eSceneType type)
		:mSceneType(type)
	{
		SetName(sceneName);
		mLayers.reserve(5);
		mLayers.resize((UINT)eLayerType::SIZE);
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		for (Layer& layer : mLayers)
		{
			layer.Initialize();
		}
	}
	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
		if (Input::GetKeyState(eKeyCode::ENTER) == eKeyState::Down)
		{
			SceneManager::GetNextScene(mSceneType);
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}
	void Scene::Release()
	{
		for (Layer& layer : mLayers)
		{
			layer.Release();
		}
	}
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}
	void Scene::AddGameObject(GameObject* obj, eLayerType layer)
	{		
		mLayers[(UINT)layer].AddGameObject(obj);
	}
}
