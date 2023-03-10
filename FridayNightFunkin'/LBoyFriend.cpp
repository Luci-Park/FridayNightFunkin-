#include "LBoyFriend.h"
#include "LAnimator.h"
namespace fnf
{
	BoyFriend::BoyFriend()
	{
		mAnimator = AddComponent<Animator>();
	}
	BoyFriend::~BoyFriend()
	{
	}
	void BoyFriend::Initialize()
	{
		GameObject::Initialize();
		mAnimator->CreateAnimations(L"Characters\\Boyfriend\\Idle", Vector2::Zero, 0.1f);
		mAnimator->
	}
	void BoyFriend::Update()
	{
		GameObject::Update();
	}
	void BoyFriend::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void BoyFriend::Release()
	{
		GameObject::Release();
	}
	
}