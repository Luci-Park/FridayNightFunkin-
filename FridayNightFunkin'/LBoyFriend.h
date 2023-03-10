#pragma once
#include "LGameObject.h"
namespace fnf
{
	class Animator;
	class BoyFriend : public GameObject
	{
	public:
		BoyFriend();
		virtual ~BoyFriend();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;
	private:
		Animator* mAnimator;
	};
}

