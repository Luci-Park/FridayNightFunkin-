#pragma once
#include "LEntity.h"
#include "LComponent.h"
#include "LTransform.h"
namespace fnf
{
	class GameObject : public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		template<typename T>
		T* AddComponent()
		{
			T* check = GetComponent<T>();
			if (check != nullptr)
				return check;
			T* comp = new T();
			UINT compType = (UINT)comp->GetType();
			mComponents[compType] = comp;
			comp->SetOwner(this);

			return comp;
		}

		template<typename T>
		T* GetComponent()
		{
			for (Component* comp : mComponents)
			{
				if (dynamic_cast<T*>(comp))
					return dynamic_cast<T*>(comp);
			}
			return nullptr;
		}
		
		Transform* GetTransform() { return mTransform; }
	protected:
		Transform* mTransform;

	private:
		std::vector<Component*> mComponents;
	};
}

