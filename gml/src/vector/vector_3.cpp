#include <cmath>

#include "../../include/vector/vector_2.hpp"
#include "../../include/vector/vector_3.hpp"
#include "../../include/vector/vector_4.hpp"
#include "../../include/quaternion.hpp"

namespace gml
{
	const Vector3 Vector3::zero{ 0.0f, 0.0f, 0.0f };
	const Vector3 Vector3::unit{ 1.0f, 1.0f, 1.0f };
	const Vector3 Vector3::posX{ 1.0f, 0.0f, 0.0f };
	const Vector3 Vector3::negX{ -1.f, 0.0f, 0.0f };
	const Vector3 Vector3::posY{ 0.0f, 1.0f, 0.0f };
	const Vector3 Vector3::negY{ 0.0f, -1.f, 0.0f };
	const Vector3 Vector3::posZ{ 0.0f, 0.0f, 1.0f };
	const Vector3 Vector3::negZ{ 0.0f, 0.0f, -1.f };

	Vector3::Vector3(float x, float y, float z)
		: x(x), y(y), z(z)
	{ }

	Vector3::Vector3(const Vector2& vec2)
		: x(vec2.x), y(vec2.y)
	{ }

	Vector3::Vector3(const Vector4& vec4)
		: x(vec4.x), y(vec4.y), z(vec4.z)
	{ }

	float Vector3::magSqr() const
	{
		return x * x + y * y + z * z;
	}

	float Vector3::mag() const
	{
		return std::sqrt(magSqr());
	}

	float Vector3::dot(const Vector3& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	float Vector3::dist(const Vector3& v) const
	{
		return std::sqrt(dot(*this - v));
	}

	Vector3 Vector3::cross(const Vector3& v) const
	{
		return {
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x
		};
	}

	Vector3 Vector3::normal() const
	{
		float m = mag();
		return{ x / m, y / m, z / m };
	}

	Vector3& Vector3::normalise()
	{
		return *this = normal();
	}

	Vector3& Vector3::limit(float magnitude)
	{
		float m = mag();
		x = x * magnitude / m;
		y = y * magnitude / m;
		z = z * magnitude / m;
		return *this;
	}

	float& Vector3::operator[](int i)
	{
		return ((float*)this)[i];
	}

	const float& Vector3::operator[](int i) const
	{
		return ((float*)this)[i];
	}

	Vector3& Vector3::operator=(const Vector3& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}

	Vector3& Vector3::operator+=(const Vector3& rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	Vector3& Vector3::operator-=(const Vector3& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	Vector3& Vector3::operator*=(const Vector3& rhs)
	{
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
		return *this;
	}

	Vector3& Vector3::operator/=(const Vector3& rhs)
	{
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
		return *this;
	}

	Vector3& Vector3::operator*=(float s)
	{
		x *= s;
		y *= s;
		z *= s;
		return *this;
	}

	Vector3& Vector3::operator/=(float s)
	{
		x /= s;
		y /= s;
		z /= s;
		return *this;
	}

	Vector3& Vector3::operator*=(const Quaternion& rhs)
	{
		return *this = *this * rhs;
	}

	Vector3 Vector3::operator-() const
	{
		return *this * -1.0f;
	}
}