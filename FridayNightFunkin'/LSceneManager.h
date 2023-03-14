#pragma once
#include "LScene.h"



namespace fnf
{
	class SceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Destroy();
		static void Release();

		static void LoadScene(eSceneType type);
		static Scene* GetActiveScene() { return mActiveScene; }
		static void SetActiveScene(Scene* scene) { mActiveScene = scene; }
		
		static void TempSceneChange();
	private:
		static std::vector<Scene*> mScenes;
		static Scene* mActiveScene;
		static int sceneNum;
	};
}
