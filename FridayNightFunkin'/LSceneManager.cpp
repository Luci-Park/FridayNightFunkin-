#include "LSceneManager.h"
namespace fnf
{
	std::vector<Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;
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
		if(mActiveScene != nullptr)
			mActiveScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		if (mActiveScene != nullptr)
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
		if (mActiveScene != nullptr)
			mActiveScene->OnExit();
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}
}