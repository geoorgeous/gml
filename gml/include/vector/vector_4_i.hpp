#pragma once

namespace gml
{
	struct Vector4f;

	struct Vector4i
	{
		int x = 0, y = 0, z = 0, w = 0;

		static const Vector4i zero;
		static const Vector4i unit;

		int magSqr() const;
		float mag() const;
		int dot(const Vector4i& v) const;
		float dist(const Vector4i& v) const;

		int& operator[](int i);
		const int& operator[](int i) const;
		Vector4i& operator+=(const Vector4i& rhs);
		Vector4i& operator-=(const Vector4i& rhs);
		Vector4i& operator*=(const Vector4i& rhs);
		Vector4i& operator/=(const Vector4i& rhs);
		Vector4i& operator*=(float s);
		Vector4i& operator/=(float s);
		Vector4i operator-() const;

		operator Vector4f() const;
	};

	inline Vector4i operator+(Vector4i lhs, const Vector4i& rhs)
	{
		return lhs += rhs;
	}

	inline Vector4i operator-(Vector4i lhs, const Vector4i& rhs)
	{
		return lhs -= rhs;
	}

	inline Vector4i operator*(Vector4i lhs, const Vector4i& rhs)
	{
		return lhs *= rhs;
	}

	inline Vector4i operator/(Vector4i lhs, const Vector4i& rhs)
	{
		return lhs /= rhs;
	}

	inline Vector4i operator*(Vector4i lhs, float s)
	{
		return lhs *= s;
	}

	inline Vector4i operator/(Vector4i lhs, float s)
	{
		return lhs /= s;
	}

	inline Vector4i operator*(float s, Vector4i rhs)
	{
		return rhs *= s;
	}

	inline Vector4i operator/(float s, Vector4i rhs)
	{
		return rhs /= s;
	}

	inline bool operator==(const Vector4i& lhs, const Vector4i& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w;
	}

	inline bool operator!=(const Vector4i& lhs, const Vector4i& rhs)
	{
		return !(lhs == rhs);
	}
}