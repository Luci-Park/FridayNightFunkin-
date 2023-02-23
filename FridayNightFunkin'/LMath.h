#pragma once
#pragma once
struct Vector2
{
	float x;
	float y;

	Vector2()
		:x(0.0f),
		y(0.0f)
	{

	}
	Vector2(int x, int y)
		:x(x),
		y(y)
	{

	}
	Vector2(float x, float y)
		:x(x),
		y(y)
	{

	}
	Vector2(Vector2& other)
	{
		x = other.x;
		y = other.x;
	}

	void operator+(Vector2 other)
	{
		x += other.x;
		y += other.y;
	}
	void operator-(Vector2 other)
	{
		x -= other.x;
		y -= other.y;
	}
	void operator=(Vector2 other) {
		x = other.x;
		y = other.y;
	}
};
