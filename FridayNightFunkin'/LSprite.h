#pragma once
#include "LMath.h"
struct Sprite
{
	Vector2 leftTop;
	Vector2 size;
	Vector2 offset;

	Sprite()
		: leftTop(Vector2::Zero)
		, size(Vector2::Zero)
		, offset(Vector2::Zero)
	{

	}
	Sprite(Vector2 lefttop, Vector2 size, Vector2 offset)
		: leftTop(lefttop)
		, size(size)
		, offset(offset)
	{

	}
};