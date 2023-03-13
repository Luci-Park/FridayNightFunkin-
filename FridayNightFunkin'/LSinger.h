#pragma once
#include "LGameObject.h"
namespace fnf
{
	class Singer : public GameObject
	{
	public:
		enum class eState
		{
			Idle,
			Up,
			Down,
			Left,
			Right
		};
		Singer();
		virtual ~Singer();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void ChangeState(eState state);
	protected:
		eState mCurrState;
	
	};
}

