#include "LScene.h"
#include "LSceneManager.h"
#include "LInput.h"


namespace fnf
{
	Scene::Scene()
	{
		mLayers.reserve((UINT)eLayerType::Size);
		mLayers.resize((UINT)eLayerType::Size);
	}
	Scene::~Scene()
	{
		
	}
	void Scene::Initialize()
	{
		SceneManager::SetActiveScene(this);
		
	}
	void Scene::Update()
	{
		for (Layer& layer : mLayers)
		{
			layer.Update();
		}
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::TempSceneChange();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : mLayers)
		{
			layer.Render(hdc);
		}
	}

	void Scene::Destroy()
	{
		std::vector<GameObject*> deleteGameObjects = {};
		for (Layer& layer : mLayers)
		{
			std::vector<GameObject*>&  gameObjects
				= layer.GetGameObjects();

			for (std::vector<GameObject*>::iterator iter = gameObjects.begin()
				; iter != gameObjects.end() ; )
			{
				if ((*iter)->GetState() == GameObject::eState::Death)
				{
					deleteGameObjects.push_back((*iter));
					iter = gameObjects.erase(iter);
				}
				else
				{
					iter++;
				}
			}
		}

		for (GameObject* deathObj : deleteGameObjects)
		{
			delete deathObj;
			deathObj = nullptr;
		}
	}
	void Scene::Release()
	{

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
	std::vector<GameObject*>& Scene::GetGameObjects(eLayerType layer)
	{
		return mLayers[(UINT)layer].GetGameObjects();
	}
}
