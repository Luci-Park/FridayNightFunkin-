#pragma once
#include "LSingers.h"
#include "LImage.h"
namespace ci
{
	class PlayerOne : public Singer
	{
	public:
		PlayerOne();
		~PlayerOne();
		
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;
		
	private:
		Image* mImage;
	};
}