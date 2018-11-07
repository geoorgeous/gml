#include <cmath>

#include "../../include/vector/vector_2_f.hpp"
#include "../../include/vector/vector_2_i.hpp"

namespace gml
{
	const Vector2f Vector2f::zero{ 0.0f, 0.0f };

	const Vector2f Vector2f::unit{ 1.0f, 1.0f };

	float Vector2f::magSqr() const
	{
		return x * x + y * y;
	}

	float Vector2f::mag() const
	{
		return sqrt(magSqr());
	}

	float Vector2f::dot(const Vector2f& v) const
	{
		return x * v.x + y * v.y;
	}

	float Vector2f::dist(const Vector2f& v) const
	{
		return sqrt(dot(*this - v));
	}

	Vector2f Vector2f::normal() const
	{
		float m = mag();
		return{ x / m, y / m };
	}

	Vector2f& Vector2f::normalise()
	{
		return *this = normal();
	}

	Vector2f& Vector2f::limit(float magnitude)
	{
		float m = mag();
		x = x * magnitude / m;
		y = y * magnitude / m;
		return *this;
	}

	float& Vector2f::operator[](int i)
	{
		return ((float*)this)[i];
	}

	const float& Vector2f::operator[](int i) const
	{
		return ((float*)this)[i];
	}

	Vector2f& Vector2f::operator+=(const Vector2f& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector2f& Vector2f::operator-=(const Vector2f& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vector2f& Vector2f::operator*=(const Vector2f& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	Vector2f& Vector2f::operator/=(const Vector2f& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		return *this;
	}

	Vector2f& Vector2f::operator*=(float s)
	{
		x *= s;
		y *= s;
		return *this;
	}

	Vector2f& Vector2f::operator/=(float s)
	{
		x /= s;
		y /= s;
		return *this;
	}

	Vector2f Vector2f::operator-() const
	{
		return *this * -1.0f;
	}

	Vector2f::operator Vector2i() const
	{
		return { (int)x, (int)y };
	}
}