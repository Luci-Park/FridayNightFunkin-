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
	{/*
		switch (mCurrState)
		{
		case eState::Idle:
			OnIdle();
			break;
		case eState::Up:
			OnUp();
			break;
		case eState::Down:
			OnDown();
			break;
		case eState::Left:
			OnLeft();
			break;
		case eState::Right:
			OnRight();
			break;
		}*/
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