#pragma once
#include "LGameObject.h"
#include "LImage.h"
namespace fnf
{
	class LStageBg : public GameObject
	{
	public:

		LStageBg();
		~LStageBg();

		virtual void Initialize()override;
		virtual void Update()override;
		virtual void Render(HDC hdc)override;
		virtual void Release()override;
	private:
		Image* mImage;
	};
}

