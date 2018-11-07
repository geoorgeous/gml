#pragma once

namespace gml
{
	struct Vector2i;

	struct Vector2f
	{
		float x = 0.0f, y = 0.0f;

		static const Vector2f zero;
		static const Vector2f unit;

		float magSqr() const;
		float mag() const;
		float dot(const Vector2f& v) const;
		float dist(const Vector2f& v) const;
		Vector2f normal() const;
		Vector2f& normalise();
		Vector2f& limit(float magnitude);

		float& operator[](int i);
		const float& operator[](int i) const;
		Vector2f& operator+=(const Vector2f& rhs);
		Vector2f& operator-=(const Vector2f& rhs);
		Vector2f& operator*=(const Vector2f& rhs);
		Vector2f& operator/=(const Vector2f& rhs);
		Vector2f& operator*=(float s);
		Vector2f& operator/=(float s);
		Vector2f operator-() const;

		explicit operator Vector2i() const;
	};

	inline Vector2f operator+(Vector2f lhs, const Vector2f& rhs)
	{
		return lhs += rhs;
	}

	inline Vector2f operator-(Vector2f lhs, const Vector2f& rhs)
	{
		return lhs -= rhs;
	}

	inline Vector2f operator*(Vector2f lhs, const Vector2f& rhs)
	{
		return lhs *= rhs;
	}

	inline Vector2f operator/(Vector2f lhs, const Vector2f& rhs)
	{
		return lhs /= rhs;
	}

	inline Vector2f operator*(Vector2f lhs, float s)
	{
		return lhs *= s;
	}

	inline Vector2f operator/(Vector2f lhs, float s)
	{
		return lhs /= s;
	}

	inline Vector2f operator*(float s, Vector2f rhs)
	{
		return rhs *= s;
	}

	inline Vector2f operator/(float s, Vector2f rhs)
	{
		return rhs /= s;
	}

	inline bool operator==(const Vector2f& lhs, const Vector2f& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	inline bool operator!=(const Vector2f& lhs, const Vector2f& rhs)
	{
		return !(lhs == rhs);
	}
}