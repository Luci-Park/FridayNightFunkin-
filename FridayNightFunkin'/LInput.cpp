#include "LInput.h"

namespace fnf
{
	int ASCII[(UINT)eKeyCode::SIZE] =
	{ 
		VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, VK_RETURN
	};
	std::vector<Input::Key>Input::mKeys;

	void Input::Initialize()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::SIZE; i++)
		{
			Key keyInfo;
			keyInfo.key = (eKeyCode)i;
			keyInfo.state = eKeyState::None;
			keyInfo.bPressed = false;

			mKeys.push_back(keyInfo);
		}
	}

	void Input::Update()
	{
		for (UINT i = 0; i < (UINT)eKeyCode::SIZE; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::Pressed;
				else
					mKeys[i].state = eKeyState::Down;
				mKeys[i].bPressed = true;
			}
			else
			{
				if (mKeys[i].bPressed)
					mKeys[i].state = eKeyState::Up;
				else
					mKeys[i].state = eKeyState::None;
				mKeys[i].bPressed = false;
			}
		}
	}
	void Input::Render(HDC hdc)
	{

	}
}
