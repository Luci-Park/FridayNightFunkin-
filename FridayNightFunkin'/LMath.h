#pragma once
#include <math.h>
#define PI 3.141592

struct Vector2
{
    static Vector2 Up;
    static Vector2 Right;

    static Vector2 One;
    static Vector2 Zero;

    float x;
    float y;

    Vector2()
        :x(0),
        y(0)
    {

    }
    Vector2(float x, float y)
        :x(x),
        y(y)
    {

    }
    Vector2(int x, int y)
        :x((float)x),
        y((float)y)
    {

    }
    // Addition operator overload
    Vector2 operator+(const Vector2& other) const
    {
        return Vector2{ x + other.x, y + other.y };
    }

    // Subtraction operator overload
    Vector2 operator-(const Vector2& other) const
    {
        return Vector2{ x - other.x, y - other.y };
    }

    // Multiplication operator overload (scalar multiplication)
    Vector2 operator*(const int scalar) const
    {
        return Vector2{ x * scalar, y * scalar };
    }

    // Division operator overload (scalar division)
    Vector2 operator/(const int scalar) const
    {
        return Vector2{ x / scalar, y / scalar };
    }

    // Equality operator overload
    bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }

    // Inequality operator overload
    bool operator!=(const Vector2& other) const
    {
        return !(*this == other);
    }

    // Compound addition operator overload
    Vector2& operator+=(const Vector2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    // Compound subtraction operator overload
    Vector2& operator-=(const Vector2& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    // Prefix increment operator overload
    Vector2& operator++()
    {
        ++x;
        ++y;
        return *this;
    }

    // Postfix increment operator overload
    Vector2 operator++(int)
    {
        Vector2 temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix decrement operator overload
    Vector2& operator--()
    {
        --x;
        --y;
        return *this;
    }

    // Postfix decrement operator overload
    Vector2 operator--(int)
    {
        Vector2 temp = *this;
        --(*this);
        return temp;
    }

    // Negation operator overload
    Vector2 operator-() const
    {
        return Vector2{ -x, -y };
    }

	float Length()
	{
		return sqrtf(x * x + y * y);
	}

	Vector2& Normalize()
	{
		float length = Length();
		x /= length;
		y /= length;

		return *this;
	}
};

namespace fnf::math
{
	//float x = dir.x * cosf(PI / 5.0f) - dir.y * sinf(PI / 5.0f);
	//float y = dir.x * sinf(PI / 5.0f) + dir.y * cosf(PI / 5.0f);

	inline static Vector2 Rotate(Vector2 vector, float degree)
	{
		float radian = (degree / 180.0f) * PI;
		vector.Normalize();

		float x = vector.x * cosf(radian) - vector.y * sinf(radian);
		float y = vector.x * sinf(radian) + vector.y * cosf(radian);
		//atan
		//atan();
		return Vector2(x, y);
	}


}

