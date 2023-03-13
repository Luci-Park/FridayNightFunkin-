#include "LBoyfriend.h"
#include "LAnimator.h"
namespace fnf
{
	Boyfriend::Boyfriend()
	{

	}
	Boyfriend::~Boyfriend()
	{
	}
	void Boyfriend::Initialize()
	{
		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\FNFAssets\\Art\\24Bit\\Characters\\Boyfriend\\Idle", Vector2::Zero, 0.1f);
		
		mAnimator->Play(L"BoyfriendIdle", true);
		Singer::Initialize();
	}
	void Boyfriend::Update()
	{
		Singer::Update();
	}
	void Boyfriend::Render(HDC hdc)
	{
		Singer::Render(hdc);
	}
	void Boyfriend::Release()
	{
		Singer::Release();
	}
}