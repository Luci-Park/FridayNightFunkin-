#include "LPlayerOne.h"
namespace ci
{
	PlayerOne::PlayerOne()
		:mImage(NULL)
	{
	}
	PlayerOne::~PlayerOne()
	{
	}
	void PlayerOne::Initialize()
	{
		GameObject::Initialize();
	}
	void PlayerOne::Update()
	{
		GameObject::Update();
	}
	void PlayerOne::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void PlayerOne::Release()
	{
		GameObject::Release();
	}
}