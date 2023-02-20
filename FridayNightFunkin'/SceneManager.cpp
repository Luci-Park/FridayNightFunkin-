#include "SceneManager.h"
namespace fnf
{
	std::vector<Scene*> SceneManager::mScenes = {};
	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::SIZE);

		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Initialize();
		}
	}

	void SceneManager::Update()
	{
		//read only
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Update();
		}
	}

	void SceneManager::Render(HDC hdc)
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Render(hdc);
		}
	}

	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Release();
		}
	}
}