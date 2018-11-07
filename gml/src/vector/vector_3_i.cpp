#include <cmath>

#include "../../include/vector/vector_3_f.hpp"
#include "../../include/vector/vector_3_i.hpp"

namespace gml
{
	const Vector3i Vector3i::zero{ 0, 0, 0 };

	const Vector3i Vector3i::unit{ 1, 1, 1 };

	int Vector3i::magSqr() const
	{
		return x * x + y * y + z * z;
	}

	float Vector3i::mag() const
	{
		return sqrt((float)magSqr());
	}

	int Vector3i::dot(const Vector3i& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	float Vector3i::dist(const Vector3i& v) const
	{
		return sqrt((float)dot(*this - v));
	}

	int& Vector3i::operator[](int i)
	{
		return ((int*)this)[i];
	}

	const int& Vector3i::operator[](int i) const
	{
		return ((int*)this)[i];
	}

	Vector3i& Vector3i::operator+=(const Vector3i& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	Vector3i& Vector3i::operator-=(const Vector3i& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	Vector3i& Vector3i::operator*=(const Vector3i& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	Vector3i& Vector3i::operator/=(const Vector3i& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}

	Vector3i& Vector3i::operator*=(float s)
	{
		x = (int)((float)x * s);
		y = (int)((float)y * s);
		z = (int)((float)z * s);
		return *this;
	}

	Vector3i& Vector3i::operator/=(float s)
	{
		x = (int)((float)x / s);
		y = (int)((float)y / s);
		z = (int)((float)z / s);
		return *this;
	}

	Vector3i Vector3i::operator-() const
	{
		return *this * -1.0f;
	}

	Vector3i::operator Vector3f() const
	{
		return { (float)x, (float)y, (float)z };
	}
}