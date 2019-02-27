/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

namespace gml
{
	struct Vector2;
	struct Vector3;

	struct Vector4
	{
		static const Vector4 zero;
		static const Vector4 unit;

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
		float w = 0.0f;

		Vector4() = default;
		Vector4(float x, float y, float z, float w);
		Vector4(const Vector2& vec2);
		Vector4(const Vector3& vec3);

		float magnitudeSq() const;
		float magnitude() const;
		float dot(const Vector4& v) const;
		Vector4 normal() const;
		Vector4& normalise();
		Vector4& limit(float newMagnitude);

		float& operator[](unsigned int idx);
		const float& operator[](unsigned int idx) const;
		Vector4& operator=(const Vector4& rhs);
		Vector4& operator+=(const Vector4& rhs);
		Vector4& operator-=(const Vector4& rhs);
		Vector4& operator*=(const Vector4& rhs);
		Vector4& operator/=(const Vector4& rhs);
		Vector4& operator*=(float s);
		Vector4& operator/=(float s);
		Vector4 operator-() const;
	};

	inline Vector4 operator+(Vector4 lhs, const Vector4& rhs)
	{
		return lhs += rhs;
	}

	inline Vector4 operator-(Vector4 lhs, const Vector4& rhs)
	{
		return lhs -= rhs;
	}

	inline Vector4 operator*(Vector4 lhs, const Vector4& rhs)
	{
		return lhs *= rhs;
	}

	inline Vector4 operator/(Vector4 lhs, const Vector4& rhs)
	{
		return lhs /= rhs;
	}

	inline Vector4 operator*(Vector4 lhs, float s)
	{
		return lhs *= s;
	}

	inline Vector4 operator/(Vector4 lhs, float s)
	{
		return lhs /= s;
	}

	inline Vector4 operator*(float s, Vector4 rhs)
	{
		return rhs *= s;
	}

	inline Vector4 operator/(float s, Vector4 rhs)
	{
		return rhs /= s;
	}

	inline bool operator==(const Vector4& lhs, const Vector4& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
	}

	inline bool operator!=(const Vector4& lhs, const Vector4& rhs)
	{
		return !(lhs == rhs);
	}
}