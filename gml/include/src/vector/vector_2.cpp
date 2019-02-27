#include <cmath>

#include "../../include/gml/vector/vector_2.hpp"
#include "../../include/gml/vector/vector_3.hpp"
#include "../../include/gml/vector/vector_4.hpp"

namespace gml
{
	const Vector2 Vector2::zero{ 0.0f, 0.0f };

	const Vector2 Vector2::unit{ 1.0f, 1.0f };

	const Vector2 Vector2::posX{ 1.0f, 0.0f };

	const Vector2 Vector2::negX{ -1.f, 0.0f };

	const Vector2 Vector2::posY{ 0.0f, 1.0f };

	const Vector2 Vector2::negY{ 0.0f, -1.f };

	Vector2::Vector2(float x, float y)
		: x(x), y(y)
	{ }

	Vector2::Vector2(const Vector3& vec3)
		: x(vec3.x), y(vec3.y)
	{ }

	Vector2::Vector2(const Vector4& vec4)
		: x(vec4.x), y(vec4.y)
	{ }

	float Vector2::magnitudeSq() const
	{
		return x * x + y * y;
	}

	float Vector2::magnitude() const
	{
		return std::sqrt(magnitudeSq());
	}

	float Vector2::dot(const Vector2& v) const
	{
		return x * v.x + y * v.y;
	}

	float Vector2::distance(const Vector2& v) const
	{
		return std::sqrt(dot(*this - v));
	}

	float Vector2::angle(const Vector2& v) const
	{
		return std::atan2(x * v.y - y * v.x, dot(v));
	}

	Vector2 Vector2::normal() const
	{
		float m = magnitude();
		return{ x / m, y / m };
	}

	Vector2& Vector2::normalise()
	{
		return *this = normal();
	}

	Vector2& Vector2::limit(float newMagnitude)
	{
		float m = magnitude();
		x = x * newMagnitude / m;
		y = y * newMagnitude / m;
		return *this;
	}

	float& Vector2::operator[](unsigned int idx)
	{
		return ((float*)this)[idx];
	}

	const float& Vector2::operator[](unsigned int idx) const
	{
		return ((float*)this)[idx];
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