#include "LBoyFriend.h"
#include "LAnimator.h"
namespace fnf
{
	BoyFriend::BoyFriend()
	{
		SetName(L"Boyfriend");
		mAnimator = AddComponent<Animator>();
	}
	BoyFriend::~BoyFriend()
	{
	}
	void BoyFriend::Initialize()
	{
		mTransform->SetPos(Vector2(10, 10));
		mAnimator->CreateAnimations(
			L"..\\FNFAssets\\Art\\24Bit\\Characters\\Boyfriend\\Idle",
			L"BoyFriendIdle", Vector2::Zero, 0.1f);
		mAnimator->Play(L"BoyFriendIdle", true);
		GameObject::Initialize();
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