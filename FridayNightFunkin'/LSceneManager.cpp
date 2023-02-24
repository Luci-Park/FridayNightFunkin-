#include "LSceneManager.h"
#include "LSceneHeaders.h"
namespace fnf
{
	std::vector<Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;
	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::SIZE);
		SetScenes();
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;
			scene->Initialize();
		}
		mActiveScene = mScenes[(UINT)eSceneType::Splash];
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
			delete scene;
			scene = nullptr;
		}
	}
	void SceneManager::LoadScene(eSceneType type)
	{
		if (mActiveScene != nullptr)
			mActiveScene->OnExit();
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}
	void SceneManager::GetNextScene(eSceneType type)
	{
		eSceneType nextType = (eSceneType)(((UINT)type + 1) % (UINT)eSceneType::SIZE);
		LoadScene(nextType);
	}
	void SceneManager::SetScenes()
	{
		mScenes[(UINT)eSceneType::Splash] = new SplashScene();
		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Options] = new OptionsScene();
		mScenes[(UINT)eSceneType::StoryMode] = new StoryModeScene();
		mScenes[(UINT)eSceneType::Tutorial] = new TutorialScene();
		mScenes[(UINT)eSceneType::Week1] = new Week1Scene();
		mScenes[(UINT)eSceneType::Week2] = new Week2Scene();
		mScenes[(UINT)eSceneType::Week3] = new Week3Scene();
		mScenes[(UINT)eSceneType::Week4] = new Week4Scene();
	}
}