#pragma once
#include "Entity.h"
namespace fnf
{
	class Component : public Entity
	{
	public:
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:

	};
}

