#include "LNightCityBg.h"
#include "LResources.h"
namespace ci
{
	NightCityBg::NightCityBg()
		:mImage(NULL)
	{
	}
	NightCityBg::~NightCityBg()
	{
	}
	void NightCityBg::Initialize()
	{
		mImage = Resources::Load<Image>(eResourceKeys::NightCityBackground);
		GameObject::Initialize();
	}
	void NightCityBg::Update()
	{
		GameObject::Update();
	}
	void NightCityBg::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void NightCityBg::Release()
	{
		GameObject::Release();
	}
}
