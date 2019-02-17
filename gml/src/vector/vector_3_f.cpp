#include <cmath>

#include "../../include/vector/vector_2_f.hpp"
#include "../../include/vector/vector_3_f.hpp"
#include "../../include/vector/vector_3_i.hpp"
#include "../../include/vector/vector_4_f.hpp"
#include "../../include/quaternion.hpp"

namespace gml
{
	const Vector3f Vector3f::zero{ 0.0f, 0.0f, 0.0f };
	const Vector3f Vector3f::unit{ 1.0f, 1.0f, 1.0f };
	const Vector3f Vector3f::posX{ 1.0f, 0.0f, 0.0f };
	const Vector3f Vector3f::negX{ -1.f, 0.0f, 0.0f };
	const Vector3f Vector3f::posY{ 0.0f, 1.0f, 0.0f };
	const Vector3f Vector3f::negY{ 0.0f, -1.f, 0.0f };
	const Vector3f Vector3f::posZ{ 0.0f, 0.0f, 1.0f };
	const Vector3f Vector3f::negZ{ 0.0f, 0.0f, -1.f };

	float Vector3f::magSqr() const
	{
		return x * x + y * y + z * z;
	}

	float Vector3f::mag() const
	{
		return sqrt(magSqr());
	}

	float Vector3f::dot(const Vector3f& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	float Vector3f::dist(const Vector3f& v) const
	{
		return sqrt(dot(*this - v));
	}

	Vector2f Vector3f::xy() const
	{
		return { x, y };
	}

	Vector3f Vector3f::cross(const Vector3f& v) const
	{
		return {
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x
		};
	}

	Vector3f Vector3f::normal() const
	{
		float m = mag();
		return{ x / m, y / m, z / m };
	}

	Vector3f& Vector3f::normalise()
	{
		return *this = normal();
	}

	Vector3f& Vector3f::limit(float magnitude)
	{
		float m = mag();
		x = x * magnitude / m;
		y = y * magnitude / m;
		z = z * magnitude / m;
		return *this;
	}

	float& Vector3f::operator[](int i)
	{
		return ((float*)this)[i];
	}

	const float& Vector3f::operator[](int i) const
	{
		return ((float*)this)[i];
	}

	Vector3f& Vector3f::operator+=(const Vector3f& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	Vector3f& Vector3f::operator-=(const Vector3f& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	Vector3f& Vector3f::operator*=(const Vector3f& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	Vector3f& Vector3f::operator/=(const Vector3f& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}

	Vector3f& Vector3f::operator*=(float s)
	{
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}

	Vector3f& Vector3f::operator/=(float s)
	{
		x /= s;
		y /= s;
		z /= s;
		return *this;
	}

	Vector3f& Vector3f::operator*=(const Quaternion& rhs)
	{
		return *this = *this * rhs;
	}

	Vector3f Vector3f::operator-() const
	{
		return *this * -1.0f;
	}

	Vector3f::operator Vector3i() const
	{
		return { (int)x, (int)y, (int)z };
	}

	Vector3f::operator Vector4f() const
	{
		return { x, y, z };
	}
}