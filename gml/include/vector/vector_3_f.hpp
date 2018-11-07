#pragma once

namespace gml
{
	struct Vector3i;

	struct Vector3f
	{
		float x = 0.0f, y = 0.0f, z = 0.0f;

		static const Vector3f zero;
		static const Vector3f unit;

		float magSqr() const;
		float mag() const;
		float dot(const Vector3f& v) const;
		float dist(const Vector3f& v) const;
		Vector3f cross(const Vector3f& v) const;
		Vector3f normal() const;
		Vector3f& normalise();
		Vector3f& limit(float magnitude);

		float& operator[](int i);
		const float& operator[](int i) const;
		Vector3f& operator+=(const Vector3f& rhs);
		Vector3f& operator-=(const Vector3f& rhs);
		Vector3f& operator*=(const Vector3f& rhs);
		Vector3f& operator/=(const Vector3f& rhs);
		Vector3f& operator*=(float s);
		Vector3f& operator/=(float s);
		Vector3f operator-() const;

		explicit operator Vector3i() const;
	};

	inline Vector3f operator+(Vector3f lhs, const Vector3f& rhs)
	{
		return lhs += rhs;
	}

	inline Vector3f operator-(Vector3f lhs, const Vector3f& rhs)
	{
		return lhs -= rhs;
	}

	inline Vector3f operator*(Vector3f lhs, const Vector3f& rhs)
	{
		return lhs *= rhs;
	}

	inline Vector3f operator/(Vector3f lhs, const Vector3f& rhs)
	{
		return lhs /= rhs;
	}

	inline Vector3f operator*(Vector3f lhs, float s)
	{
		return lhs *= s;
	}

	inline Vector3f operator/(Vector3f lhs, float s)
	{
		return lhs /= s;
	}

	inline Vector3f operator*(float s, Vector3f rhs)
	{
		return rhs *= s;
	}

	inline Vector3f operator/(float s, Vector3f rhs)
	{
		return rhs /= s;
	}

	inline bool operator==(const Vector3f& lhs, const Vector3f& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

	inline bool operator!=(const Vector3f& lhs, const Vector3f& rhs)
	{
		return !(lhs == rhs);
	}
}