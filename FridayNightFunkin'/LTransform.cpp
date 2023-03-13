#include "LTransform.h"


namespace fnf
{
	Transform::Transform()
		:Component(eComponentType::Transform)
		, mPos(Vector2::Zero)
		, mScale(Vector2::One)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
	void Transform::Release()
	{
	}
}