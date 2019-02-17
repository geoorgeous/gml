#pragma once

namespace gml
{
	struct Vector2f;
	struct Vector3i;
	struct Vector4f;
	struct Quaternion;

	struct Vector3f
	{
		float x = 0.0f, y = 0.0f, z = 0.0f;

		static const Vector3f zero;
		static const Vector3f unit;
		static const Vector3f posX;
		static const Vector3f negX;
		static const Vector3f posY;
		static const Vector3f negY;
		static const Vector3f posZ;
		static const Vector3f negZ;

		float magSqr() const;
		float mag() const;
		float dot(const Vector3f& v) const;
		float dist(const Vector3f& v) const;
		Vector3f cross(const Vector3f& v) const;
		Vector3f normal() const;
		Vector3f& normalise();
		Vector3f& limit(float magnitude);
		Vector2f xy() const;

		float& operator[](int i);
		const float& operator[](int i) const;
		Vector3f& operator+=(const Vector3f& rhs);
		Vector3f& operator-=(const Vector3f& rhs);
		Vector3f& operator*=(const Vector3f& rhs);
		Vector3f& operator/=(const Vector3f& rhs);
		Vector3f& operator*=(float s);
		Vector3f& operator/=(float s);
		Vector3f& operator*=(const Quaternion& rhs);
		Vector3f operator-() const;

		operator Vector3i() const;
		explicit operator Vector4f() const;
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