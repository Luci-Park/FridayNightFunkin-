#include "SceneManager.h"
namespace fnf
{
	std::vector<Scene*> SceneManager::mScenes = {};
	static Scene* mActiveScene;
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
		mActiveScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
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
	void SceneManager::LoadScene(eSceneType type)
	{
		mActiveScene->OnExit();
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}
}