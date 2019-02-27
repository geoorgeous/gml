#pragma once

namespace gml
{
	struct Vector2;
	struct Vector4;
	struct Quaternion;

	struct Vector3
	{
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		static const Vector3 zero;
		static const Vector3 unit;
		static const Vector3 posX;
		static const Vector3 negX;
		static const Vector3 posY;
		static const Vector3 negY;
		static const Vector3 posZ;
		static const Vector3 negZ;

		Vector3() = default;
		Vector3(float x, float y, float z);
		Vector3(const Vector2& vec2);
		Vector3(const Vector4& vec4);

		float magSqr() const;
		float mag() const;
		float dot(const Vector3& v) const;
		float dist(const Vector3& v) const;
		Vector3 cross(const Vector3& v) const;
		Vector3 normal() const;
		Vector3& normalise();
		Vector3& limit(float magnitude);

		float& operator[](int i);
		const float& operator[](int i) const;
		Vector3& operator=(const Vector3& rhs);
		Vector3& operator+=(const Vector3& rhs);
		Vector3& operator-=(const Vector3& rhs);
		Vector3& operator*=(const Vector3& rhs);
		Vector3& operator/=(const Vector3& rhs);
		Vector3& operator*=(float s);
		Vector3& operator/=(float s);
		Vector3& operator*=(const Quaternion& rhs);
		Vector3 operator-() const;
	};

	inline Vector3 operator+(Vector3 lhs, const Vector3& rhs)
	{
		return lhs += rhs;
	}

	inline Vector3 operator-(Vector3 lhs, const Vector3& rhs)
	{
		return lhs -= rhs;
	}

	inline Vector3 operator*(Vector3 lhs, const Vector3& rhs)
	{
		return lhs *= rhs;
	}

	inline Vector3 operator/(Vector3 lhs, const Vector3& rhs)
	{
		return lhs /= rhs;
	}

	inline Vector3 operator*(Vector3 lhs, float s)
	{
		return lhs *= s;
	}

	inline Vector3 operator/(Vector3 lhs, float s)
	{
		return lhs /= s;
	}

	inline Vector3 operator*(float s, Vector3 rhs)
	{
		return rhs *= s;
	}

	inline Vector3 operator/(float s, Vector3 rhs)
	{
		return rhs /= s;
	}

	inline bool operator==(const Vector3& lhs, const Vector3& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
	}

	inline bool operator!=(const Vector3& lhs, const Vector3& rhs)
	{
		return !(lhs == rhs);
	}
}