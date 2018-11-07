#include <cmath>

#include "../../include/vector/vector_4_f.hpp"
#include "../../include/vector/vector_4_i.hpp"

namespace gml
{
	const Vector4i Vector4i::zero{ 0, 0, 0, 0 };

	const Vector4i Vector4i::unit{ 1, 1, 1, 1 };

	int Vector4i::magSqr() const
	{
		return x * x + y * y + z * z + w * w;
	}

	float Vector4i::mag() const
	{
		return sqrt((float)magSqr());
	}

	int Vector4i::dot(const Vector4i& v) const
	{
		return x * v.x + y * v.y + z * v.z + w * v.w;
	}

	float Vector4i::dist(const Vector4i& v) const
	{
		return sqrt((float)dot(*this - v));
	}

	int& Vector4i::operator[](int i)
	{
		return ((int*)this)[i];
	}

	const int& Vector4i::operator[](int i) const
	{
		return ((int*)this)[i];
	}

	Vector4i& Vector4i::operator+=(const Vector4i& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}

	Vector4i& Vector4i::operator-=(const Vector4i& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	}

	Vector4i& Vector4i::operator*=(const Vector4i& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		w *= rhs.w;
		return *this;
	}

	Vector4i& Vector4i::operator/=(const Vector4i& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		w /= rhs.w;
		return *this;
	}

	Vector4i& Vector4i::operator*=(float s)
	{
		x = (int)((float)x * s);
		y = (int)((float)y * s);
		z = (int)((float)z * s);
		w = (int)((float)w * s);
		return *this;
	}

	Vector4i& Vector4i::operator/=(float s)
	{
		x = (int)((float)x / s);
		y = (int)((float)y / s);
		z = (int)((float)z / s);
		w = (int)((float)w / s);
		return *this;
	}

	Vector4i Vector4i::operator-() const
	{
		return *this * -1.0f;
	}

	Vector4i::operator Vector4f() const
	{
		return { (float)x, (float)y, (float)z, (float)w };
	}
}