#include "LGameObject.h"
namespace fnf
{
	GameObject::GameObject()
	{
		mComponents.resize((UINT)eComponentType::SIZE);
		transform = AddComponent<Transform>();
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			comp->Update();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render(hdc);
		}
	}

	void GameObject::Release()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Release();
			delete comp;
			comp = nullptr;
		}
	}
}