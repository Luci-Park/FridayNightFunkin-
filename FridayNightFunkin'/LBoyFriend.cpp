#include "LBoyfriend.h"
#include "LAnimator.h"
#include "LInput.h"
#include "LTime.h"
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
		if (Input::GetKeyDown(eKeyCode::Q))
		{
			BFWriteFile();
		}
		Move();
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
	void Boyfriend::Move()
	{
		Vector2 pos = mTransform->GetPos();
		if (Input::GetKey(eKeyCode::A))
			pos.x -= 100.0f * Time::DeltaTime();
		
		if (Input::GetKey(eKeyCode::D))
			pos.x += 100.0f * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::W))
			pos.y -= 100.0f * Time::DeltaTime();
		if (Input::GetKey(eKeyCode::S))
			pos.y += 100.0f * Time::DeltaTime();

		mTransform->SetPos(pos);
	}
	void Boyfriend::BFWriteFile()
	{
		HANDLE hFile = CreateFile(
			L"example.txt",          // file name
			GENERIC_WRITE,          // access mode
			0,                      // sharing mode (not used for file creation)
			NULL,                   // security attributes
			CREATE_ALWAYS,          // creation disposition (always create a new file)
			FILE_ATTRIBUTE_NORMAL,  // file attributes (no special attributes)
			NULL);                  // template file (not used for file creation)

		if (hFile == INVALID_HANDLE_VALUE)
		{
			// hande error
			return;
		}
		Vector2 pos = mTransform->GetPos();
		char buf[1024];
		sprintf_s(buf, sizeof(buf), "%d %d", (int)pos.x, (int)pos.y);
		DWORD bytesWritten;
		WriteFile(hFile, buf, strlen(buf), &bytesWritten, NULL);

		CloseHandle(hFile);
	}
}