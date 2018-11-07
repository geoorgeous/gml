#include <cmath>

#include "../../include/vector/vector_4_f.hpp"
#include "../../include/vector/vector_4_i.hpp"

namespace gml
{
	const Vector4f Vector4f::zero{ 0.0f, 0.0f, 0.0f, 0.0f };

	const Vector4f Vector4f::unit{ 1.0f, 1.0f, 1.0f, 1.0f };

	float Vector4f::magSqr() const
	{
		return x * x + y * y + z * z + w * w;
	}

	float Vector4f::mag() const
	{
		return sqrt(magSqr());
	}

	float Vector4f::dot(const Vector4f& v) const
	{
		return x * v.x + y * v.y + z * v.z + w * v.w;
	}

	float Vector4f::dist(const Vector4f& v) const
	{
		return sqrt(dot(*this - v));
	}

	Vector4f Vector4f::normal() const
	{
		float m = mag();
		return{ x / m, y / m, z / m, w / m };
	}

	Vector4f& Vector4f::normalise()
	{
		return *this = normal();
	}

	Vector4f& Vector4f::limit(float magnitude)
	{
		float m = mag();
		x = x * magnitude / m;
		y = y * magnitude / m;
		z = z * magnitude / m;
		w = w * magnitude / m;
		return *this;
	}

	float& Vector4f::operator[](int i)
	{
		return ((float*)this)[i];
	}

	const float& Vector4f::operator[](int i) const
	{
		return ((float*)this)[i];
	}

	Vector4f& Vector4f::operator+=(const Vector4f& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	}

	Vector4f& Vector4f::operator-=(const Vector4f& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	}

	Vector4f& Vector4f::operator*=(const Vector4f& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		w *= rhs.w;
		return *this;
	}

	Vector4f& Vector4f::operator/=(const Vector4f& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		w /= rhs.w;
		return *this;
	}

	Vector4f& Vector4f::operator*=(float s)
	{
		x *= s;
		y *= s;
		z *= s;
		w *= s;
		return *this;
	}

	Vector4f& Vector4f::operator/=(float s)
	{
		x /= s;
		y /= s;
		z /= s;
		w /= s;
		return *this;
	}

	Vector4f Vector4f::operator-() const
	{
		return *this * -1.0f;
	}

	Vector4f::operator Vector4i() const
	{
		return { (int)x, (int)y, (int)z, (int)w };
	}
}