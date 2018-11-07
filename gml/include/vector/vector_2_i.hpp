#pragma once

namespace gml
{
	struct Vector2f;

	struct Vector2i
	{
		int x = 0, y = 0;

		static const Vector2i zero;
		static const Vector2i unit;

		int magSqr() const;
		float mag() const;
		int dot(const Vector2i& v) const;
		float dist(const Vector2i& v) const;

		int& operator[](int i);
		const int& operator[](int i) const;
		Vector2i& operator+=(const Vector2i& rhs);
		Vector2i& operator-=(const Vector2i& rhs);
		Vector2i& operator*=(const Vector2i& rhs);
		Vector2i& operator/=(const Vector2i& rhs);
		Vector2i& operator*=(float s);
		Vector2i& operator/=(float s);
		Vector2i operator-() const;

		operator Vector2f() const;
	};

	inline Vector2i operator+(Vector2i lhs, const Vector2i& rhs)
	{
		return lhs += rhs;
	}

	inline Vector2i operator-(Vector2i lhs, const Vector2i& rhs)
	{
		return lhs -= rhs;
	}

	inline Vector2i operator*(Vector2i lhs, const Vector2i& rhs)
	{
		return lhs *= rhs;
	}

	inline Vector2i operator/(Vector2i lhs, const Vector2i& rhs)
	{
		return lhs /= rhs;
	}

	inline Vector2i operator*(Vector2i lhs, float s)
	{
		return lhs *= s;
	}

	inline Vector2i operator/(Vector2i lhs, float s)
	{
		return lhs /= s;
	}

	inline Vector2i operator*(float s, Vector2i rhs)
	{
		return rhs *= s;
	}

	inline Vector2i operator/(float s, Vector2i rhs)
	{
		return rhs /= s;
	}

	inline bool operator==(const Vector2i& lhs, const Vector2i& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	inline bool operator!=(const Vector2i& lhs, const Vector2i& rhs)
	{
		return !(lhs == rhs);
	}
}