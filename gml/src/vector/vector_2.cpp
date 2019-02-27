#include <cmath>

#include "../../include/vector/vector_2.hpp"
#include "../../include/vector/vector_3.hpp"
#include "../../include/vector/vector_4.hpp"

namespace gml
{
	const Vector2 Vector2::zero{ 0.0f, 0.0f };

	const Vector2 Vector2::unit{ 1.0f, 1.0f };

	Vector2::Vector2(float x, float y)
		: x(x), y(y)
	{ }

	Vector2::Vector2(const Vector3& vec3)
		: x(vec3.x), y(vec3.y)
	{ }

	Vector2::Vector2(const Vector4& vec4)
		: x(vec4.x), y(vec4.y)
	{ }

	float Vector2::magSqr() const
	{
		return x * x + y * y;
	}

	float Vector2::mag() const
	{
		return std::sqrt(magSqr());
	}

	float Vector2::dot(const Vector2& v) const
	{
		return x * v.x + y * v.y;
	}

	float Vector2::dist(const Vector2& v) const
	{
		return std::sqrt(dot(*this - v));
	}

	Vector2 Vector2::normal() const
	{
		float m = mag();
		return{ x / m, y / m };
	}

	Vector2& Vector2::normalise()
	{
		return *this = normal();
	}

	Vector2& Vector2::limit(float magnitude)
	{
		float m = mag();
		x = x * magnitude / m;
		y = y * magnitude / m;
		return *this;
	}

	float& Vector2::operator[](int i)
	{
		return ((float*)this)[i];
	}

	const float& Vector2::operator[](int i) const
	{
		return ((float*)this)[i];
	}

	Vector2& Vector2::operator=(const Vector2& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	Vector2& Vector2::operator+=(const Vector2& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector2& Vector2::operator-=(const Vector2& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vector2& Vector2::operator*=(const Vector2& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	Vector2& Vector2::operator/=(const Vector2& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		return *this;
	}

	Vector2& Vector2::operator*=(float s)
	{
		x *= s;
		y *= s;
		return *this;
	}

	Vector2& Vector2::operator/=(float s)
	{
		x /= s;
		y /= s;
		return *this;
	}

	Vector2 Vector2::operator-() const
	{
		return *this * -1.0f;
	}
}