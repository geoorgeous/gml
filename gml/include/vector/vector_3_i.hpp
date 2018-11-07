#pragma once

namespace gml
{
	struct Vector3f;

	struct Vector3i
	{
		int x = 0, y = 0, z = 0;

		static const Vector3i zero;
		static const Vector3i unit;

		int magSqr() const;
		float mag() const;
		int dot(const Vector3i& v) const;
		float dist(const Vector3i& v) const;

		int& operator[](int i);
		const int& operator[](int i) const;
		Vector3i& operator+=(const Vector3i& rhs);
		Vector3i& operator-=(const Vector3i& rhs);
		Vector3i& operator*=(const Vector3i& rhs);
		Vector3i& operator/=(const Vector3i& rhs);
		Vector3i& operator*=(float s);
		Vector3i& operator/=(float s);
		Vector3i operator-() const;

		operator Vector3f() const;
	};

	inline Vector3i operator+(Vector3i lhs, const Vector3i& rhs)
	{
		return lhs += rhs;
	}

	inline Vector3i operator-(Vector3i lhs, const Vector3i& rhs)
	{
		return lhs -= rhs;
	}

	inline Vector3i operator*(Vector3i lhs, const Vector3i& rhs)
	{
		return lhs *= rhs;
	}

	inline Vector3i operator/(Vector3i lhs, const Vector3i& rhs)
	{
		return lhs /= rhs;
	}

	inline Vector3i operator*(Vector3i lhs, float s)
	{
		return lhs *= s;
	}

	inline Vector3i operator/(Vector3i lhs, float s)
	{
		return lhs /= s;
	}

	inline Vector3i operator*(float s, Vector3i rhs)
	{
		return rhs *= s;
	}

	inline Vector3i operator/(float s, Vector3i rhs)
	{
		return rhs /= s;
	}

	inline bool operator==(const Vector3i& lhs, const Vector3i& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

	inline bool operator!=(const Vector3i& lhs, const Vector3i& rhs)
	{
		return !(lhs == rhs);
	}
}