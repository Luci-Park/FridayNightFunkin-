#pragma once
#include "LEntity.h"
#include "LLayer.h"
namespace fnf
{
	class Scene : public Entity
	{
	public:
		Scene(std::wstring sceneName, eSceneType type);
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* obj, eLayerType layer);
		std::wstring GetSceneName() { return mSceneName; }

	protected:
		eSceneType mSceneType;
		std::wstring mSceneName;
		std::vector<Layer> mLayers;
	};
}

