#include "yaMonster.h"
#include "LTime.h"
#include "LSceneManager.h"
#include "LInput.h"
#include "LResources.h"
#include "LTransform.h"
#include "LAnimator.h"
#include "LCollider.h"
#include "yaBaseBullet.h"
#include "LScene.h"


namespace fnf
{
	Monster::Monster()
	{
	}
	Monster::~Monster()
	{
	}
	void Monster::Initialize()
	{
		//Goopy Le Grande\Phase 1\Jump
		//Transform* tr = GetComponent<Transform>();
		//tr->SetPos(Vector2(700.0f, 400.0f));
		//tr->SetScale(Vector2(1.5f, 1.5f));

		mAnimator = AddComponent<Animator>();
		mAnimator->CreateAnimations(L"..\\Resources\\Goopy Le Grande\\Phase 1\\Jump", Vector2::Zero, 0.1f);

		mAnimator->Play(L"Phase 1Jump", true);

		Collider* collider = AddComponent<Collider>();
		collider->SetCenter(Vector2(-60.0f, -80.0f));

		GameObject::Initialize();
	}
	void Monster::Update()
	{
		GameObject::Update();
	}
	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Monster::Release()
	{
		GameObject::Release();
	}
}