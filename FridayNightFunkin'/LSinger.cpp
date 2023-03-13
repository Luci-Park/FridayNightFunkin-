#include "LSinger.h"

namespace fnf
{
	Singer::Singer()
	{
	}
	Singer::~Singer()
	{
	}
	void Singer::Initialize()
	{
		GameObject::Initialize();
	}
	void Singer::Update()
	{
		GameObject::Update();
	}
	void Singer::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Singer::Release()
	{
		GameObject::Release();
	}
	void Singer::ChangeState(eState state)
	{

	}
}