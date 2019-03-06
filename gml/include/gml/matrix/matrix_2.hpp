/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "../vector/vector_2.hpp"

namespace gml
{
	struct Matrix3;
	struct Matrix4;

	struct Matrix2
	{
		static const Matrix2 zero;
		static const Matrix2 identity;

		Vector2 columns[2];

		Matrix2() = default;
		Matrix2(float a, float b,
			float c, float d);
		Matrix2(const Vector2& col0, const Vector2& col1);
		Matrix2(const Matrix3& mat3);
		Matrix2(const Matrix4& mat4);
		Vector2 getRow(unsigned int idx) const;
		Matrix2 transpose() const;
		Matrix2 inverse() const;
		float determinant() const;

		Vector2& operator[](unsigned int idx);
		const Vector2& operator[](unsigned int idx) const;

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
		Matrix2 result;
		for (unsigned int col = 0; col < 2; col++)
			for (unsigned int row = 0; row < 2; row++)
				result[col][row] = lhs.getRow(row).dot(rhs.columns[col]);
		return result;
	}

	inline Matrix2 operator/(const Matrix2& lhs, const Matrix2& rhs)
	{
		return lhs * rhs.inverse();
	}

	inline Vector2 operator*(const Matrix2& lhs, const Vector2& rhs)
	{
		return {
			lhs.getRow(0).dot(rhs),
			lhs.getRow(1).dot(rhs)
		};
	}

	inline bool operator==(const Matrix2& lhs, const Matrix2& rhs)
	{
		for (unsigned int idx = 0; idx < 2; idx++)
			if (lhs[idx] != rhs[idx])
				return false;
		return true;
	}

	inline bool operator!=(const Matrix2& lhs, const Matrix2& rhs)
	{
		return !(lhs == rhs);
	}
}