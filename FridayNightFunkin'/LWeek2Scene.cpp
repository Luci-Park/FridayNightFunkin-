#include "LWeek2Scene.h"
namespace fnf
{

	Week2Scene::Week2Scene()
		:Scene(L"Week2", eSceneType::Week2)
	{
	}
	Week2Scene::~Week2Scene()
	{
	}
    void Week2Scene::Initialize()
    {
        Scene::Initialize();
    }
    void Week2Scene::Update()
    {
        Scene::Update();
    }
    void Week2Scene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void Week2Scene::Release()
    {
        Scene::Release();
    }
    void Week2Scene::OnEnter()
    {
        Scene::Release();
    }
    void Week2Scene::OnExit()
    {
        Scene::Release();
    }
}