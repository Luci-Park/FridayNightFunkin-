#include "Scene.h"
namespace fnf
{
	Scene::Scene()
	{
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
	void Scene::AddGameObject(GameObject* obj, eLayerType layer)
	{
		mLayers[(UINT)layer].AddGameObject(obj);
	}
}
