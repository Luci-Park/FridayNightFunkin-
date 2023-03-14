#include "LSceneManager.h"
#include "LCollisionManager.h"
#include "LCamera.h"
#include "LTutorialScene.h"
#include "LSplashScene.h"
namespace fnf
{	
	//SceneManager scsene;
	//SceneManager* scsene = new SceneManager();
	std::vector<Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;
	int SceneManager::sceneNum = 0;
	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::Size);

		mScenes[(UINT)eSceneType::Tutorial] = new TutorialScene();
		mScenes[(UINT)eSceneType::Splash1] = new SplashScene();
		for ( Scene* scene : mScenes )
		{
			if (scene == nullptr)
				continue;

			scene->Initialize();
		}

		mActiveScene = mScenes[(UINT)eSceneType::Tutorial];
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}

	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			delete scene;
			scene = nullptr;
		}
	}

	void SceneManager::LoadScene(eSceneType type)
	{
		Camera::Clear();
		mActiveScene->OnExit();
		CollisionManager::Clear();
		mActiveScene = mScenes[(UINT)type];
		Camera::StartFadeIn();
		mActiveScene->OnEnter();		
	}
	void SceneManager::TempSceneChange()
	{
		if (sceneNum == 0)
			LoadScene(eSceneType::Splash1);
		else
			LoadScene(eSceneType::Tutorial);
		sceneNum = (sceneNum + 1) % 2;
	}
}
