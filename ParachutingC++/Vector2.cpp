#include "Vector2.h"
#include <cmath>
#include <iostream>

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2::Vector2(const Vector2& other) : x(other.x), y(other.y) {}


Vector2& Vector2::operator=(const Vector2& other)
{
	if (this == &other) return *this;
	x = other.x;
	y = other.y;

}

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(float scalar) const
{
	return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(float scalar) const
{
	return Vector2(x / scalar, y / scalar);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2& Vector2::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}

Vector2& Vector2::operator/=(float scalar)
{
	x /= scalar;
	y /= scalar;
	return *this;
}


float Vector2::magnitude() const
{
	return std::sqrt(x * x + y * y);
}

Vector2 Vector2::normalized() const
{
	float mag = magnitude();
	return (mag == 0) ? Vector2(0,0) : Vector2(x / mag, y / mag);
}

