#include <cmath>

#include "../../include/vector/vector_2_f.hpp"
#include "../../include/vector/vector_2_i.hpp"
#include "../../include/vector/vector_3_i.hpp"

namespace gml
{
	const Vector2i Vector2i::zero{ 0, 0 };

	const Vector2i Vector2i::unit{ 1, 1 };

	int Vector2i::magSqr() const
	{
		return x * x + y * y;
	}

	float Vector2i::mag() const
	{
		return sqrt((float)magSqr());
	}

	int Vector2i::dot(const Vector2i& v) const
	{
		return x * v.x + y * v.y;
	}

	float Vector2i::dist(const Vector2i& v) const
	{
		return sqrt((float)dot(*this - v));
	}

	int& Vector2i::operator[](int i)
	{
		return ((int*)this)[i];
	}

	const int& Vector2i::operator[](int i) const
	{
		return ((int*)this)[i];
	}

	Vector2i& Vector2i::operator+=(const Vector2i& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector2i& Vector2i::operator-=(const Vector2i& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vector2i& Vector2i::operator*=(const Vector2i& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		return *this;
	}

	Vector2i& Vector2i::operator/=(const Vector2i& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		return *this;
	}

	Vector2i& Vector2i::operator*=(float s)
	{
		x = (int)((float)x * s);
		y = (int)((float)y * s);
		return *this;
	}

	Vector2i& Vector2i::operator/=(float s)
	{
		x = (int)((float)x / s);
		y = (int)((float)y / s);
		return *this;
	}

	Vector2i Vector2i::operator-() const
	{
		return *this * -1.0f;
	}

	Vector2i::operator Vector2f() const
	{
		return { (float)x, (float)y };
	}

	Vector2i::operator Vector3i() const
	{
		return { x, y };
	}
}