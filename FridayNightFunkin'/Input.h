#pragma once
#include "Engine.h"
namespace fnf
{
	enum class eKeyCode
	{
		UP, DOWN, LEFT, RIGHT,
		ENTER,
		SIZE,
	};

	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode key;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		inline static eKeyState GetKeyState(eKeyCode keyCode)
		{
			return mKeys[(UINT)keyCode].state;
		};

	private:
		static std::vector<Key> mKeys;
	};
}

