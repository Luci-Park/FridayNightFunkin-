#pragma once
#include "Entity.h"
#include "Layer.h"
namespace fnf
{
	class Scene : public Entity
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* obj, eLayerType layer);

	private:
		std::vector<Layer> mLayers;
	};
}

