#pragma once

namespace gml
{
	struct Vector3f;
	struct Vector4i;

	struct Vector4f
	{
		float x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;

		static const Vector4f zero;
		static const Vector4f unit;

		float magSqr() const;
		float mag() const;
		float dot(const Vector4f& v) const;
		float dist(const Vector4f& v) const;
		Vector4f normal() const;
		Vector4f& normalise();
		Vector4f& limit(float magnitude);
		Vector3f xyz() const;

		float& operator[](int i);
		const float& operator[](int i) const;
		Vector4f& operator+=(const Vector4f& rhs);
		Vector4f& operator-=(const Vector4f& rhs);
		Vector4f& operator*=(const Vector4f& rhs);
		Vector4f& operator/=(const Vector4f& rhs);
		Vector4f& operator*=(float s);
		Vector4f& operator/=(float s);
		Vector4f operator-() const;

		explicit operator Vector4i() const;
	};

	inline Vector4f operator+(Vector4f lhs, const Vector4f& rhs)
	{
		return lhs += rhs;
	}

	inline Vector4f operator-(Vector4f lhs, const Vector4f& rhs)
	{
		return lhs -= rhs;
	}

	inline Vector4f operator*(Vector4f lhs, const Vector4f& rhs)
	{
		return lhs *= rhs;
	}

	inline Vector4f operator/(Vector4f lhs, const Vector4f& rhs)
	{
		return lhs /= rhs;
	}

	inline Vector4f operator*(Vector4f lhs, float s)
	{
		return lhs *= s;
	}

	inline Vector4f operator/(Vector4f lhs, float s)
	{
		return lhs /= s;
	}

	inline Vector4f operator*(float s, Vector4f rhs)
	{
		return rhs *= s;
	}

	inline Vector4f operator/(float s, Vector4f rhs)
	{
		return rhs /= s;
	}

	inline bool operator==(const Vector4f& lhs, const Vector4f& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
	}

	inline bool operator!=(const Vector4f& lhs, const Vector4f& rhs)
	{
		return !(lhs == rhs);
	}
}