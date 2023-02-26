#include "LHauntedBg.h"
#include "LResources.h"
namespace ci
{
	HauntedBg::HauntedBg()
		:mImage(NULL)
	{
	}
	HauntedBg::~HauntedBg()
	{
	}
	void HauntedBg::Initialize()
	{
		mImage = Resources::Load<Image>(eResourceKeys::HauntedBackground);
		GameObject::Initialize();
	}
	void HauntedBg::Update()
	{
		GameObject::Update();
	}
	void HauntedBg::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void HauntedBg::Release()
	{
		GameObject::Release();
	}
}
