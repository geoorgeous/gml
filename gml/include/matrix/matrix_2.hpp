#pragma once

#include "../vector/vector_2_f.hpp"

namespace gml
{
	struct Matrix3;
	struct Matrix4;

	struct Matrix2
	{
		float m[4] = {
			0.0f, 0.0f,
			0.0f, 0.0f 
		};

		static const Matrix2 zero;
		static const Matrix2 identity;

		Matrix2() = default;
		Matrix2(float a, float b,
			float c, float d);
		Matrix2(const Matrix3& mat3);
		Matrix2(const Matrix4& mat4);
		Matrix2 transpose() const;
		Matrix2 inverse() const;
		float determinant() const;

		float& operator[](int i);
		const float& operator[](int i) const;

		Matrix2& operator+=(const Matrix2& rhs);
		Matrix2& operator-=(const Matrix2& rhs);
		Matrix2& operator*=(float s);
		Matrix2& operator/=(float s);
		Matrix2 operator-() const;
	};

	inline Matrix2 operator+(Matrix2 lhs, const Matrix2& rhs)
	{
		return lhs += rhs;
	}

	inline Matrix2 operator-(Matrix2 lhs, const Matrix2& rhs)
	{
		return lhs -= rhs;
	}

	inline Matrix2 operator*(Matrix2 lhs, float s)
	{
		return lhs *= s;
	}

	inline Matrix2 operator*(float s, Matrix2 rhs)
	{
		return rhs *= s;
	}

	inline Matrix2 operator/(Matrix2 lhs, float s)
	{
		return lhs /= s;
	}

	inline Matrix2 operator*(const Matrix2& lhs, const Matrix2& rhs)
	{
		return {
			lhs[0] * rhs[0] + lhs[1] * rhs[2],
			lhs[0] * rhs[1] + lhs[1] * rhs[3],
			lhs[2] * rhs[0] + lhs[3] * rhs[2],
			lhs[2] * rhs[1] + lhs[0] * rhs[3]
		};
	}

	inline Matrix2 operator/(const Matrix2& lhs, const Matrix2& rhs)
	{
		return lhs * rhs.inverse();
	}

	inline Vector2f operator*(const Matrix2& lhs, const Vector2f& rhs)
	{
		return {
			lhs[0] * rhs.x + lhs[1] * rhs.y,
			lhs[2] * rhs.x + lhs[3] * rhs.y
		};
	}

	inline bool operator==(const Matrix2& lhs, const Matrix2& rhs)
	{
		return lhs[0] == rhs[0]
			&& lhs[1] == rhs[1]
			&& lhs[2] == rhs[2]
			&& lhs[3] == rhs[3];
	}

	inline bool operator!=(const Matrix2& lhs, const Matrix2& rhs)
	{
		return !(lhs == rhs);
	}
}