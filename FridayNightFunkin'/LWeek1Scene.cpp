#include "LWeek1Scene.h"
#include "LStageBg.h"
namespace ci
{
	Week1Scene::Week1Scene()
		:Scene(L"Week1", eSceneType::Week1)
	{
	}
	Week1Scene::~Week1Scene()
	{
	}
    void Week1Scene::Initialize()
    {
        AddGameObject(new StageBg(), eLayerType::Background);
        Scene::Initialize();
    }
    void Week1Scene::Update()
    {
        Scene::Update();
    }
    void Week1Scene::Render(HDC hdc)
    {
        Scene::Render(hdc);
    }
    void Week1Scene::Release()
    {
        Scene::Release();
    }
    void Week1Scene::OnEnter()
    {
        Scene::OnEnter();
    }
    void Week1Scene::OnExit()
    {
        Scene::OnExit();
    }
}