#pragma once
#include "LGameObject.h"
#include "LScene.h"
#include "LSceneManager.h"
#include "LTransform.h"

namespace fnf::object
{
	template <typename T>
	static inline T* Instantiate(Scene* sc, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = sc;
		scene->AddGameObject(gameObj, type);
		gameObj->Initialize();
		return gameObj;
	}

	template <typename T>
	static inline T* Instantiate(Scene* sc, Vector2 pos, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = sc;
		scene->AddGameObject(gameObj, type);
		gameObj->Initialize();
		gameObj->GameObject::GetComponent<Transform>()->SetPos(pos);
		return gameObj;
	}
	template <typename T>
	static inline T* Instantiate(eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->Initialize();
		return gameObj;
	}

	template <typename T>
	static inline T* Instantiate(Vector2 pos, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->Initialize();
		gameObj->GameObject::GetComponent<Transform>()->SetPos(pos);
		return gameObj;
	}


	static void Destory(GameObject* obj)
	{
		obj->SetState(GameObject::eState::Death);
	}
}