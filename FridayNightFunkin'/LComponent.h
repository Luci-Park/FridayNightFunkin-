#pragma once
#include "LEntity.h"
namespace fnf
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component(eComponentType type);
		virtual ~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		eComponentType GetType() { return mType; }
		GameObject* GetOwner() { return mOwner; }
		void SetOwner(GameObject* owner);
	private:
		const eComponentType mType;
		GameObject* mOwner;
	};
}

