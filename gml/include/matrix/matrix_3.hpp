/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "../vector/vector_3.hpp"

namespace gml
{
	struct Matrix2;
	struct Matrix4;

	struct Matrix3
	{
		static const Matrix3 zero;
		static const Matrix3 identity;

		Vector3 columns[3];

		Matrix3() = default;
		Matrix3(float a, float b, float c,
			float d, float e, float f,
			float g, float h, float i);
		Matrix3(const Vector3& col0, const Vector3& col1, const Vector3& col2);
		Matrix3(const Matrix2& mat2);
		Matrix3(const Matrix4& mat4);
		Vector3 getRow(unsigned int idx) const;
		Matrix3 transpose() const;
		Matrix3 inverse() const;
		float determinant() const;

		Vector3& operator[](unsigned int idx);
		const Vector3& operator[](unsigned int idx) const;

		Matrix3& operator+=(const Matrix3& rhs);
		Matrix3& operator-=(const Matrix3& rhs);
		Matrix3& operator*=(float s);
		Matrix3& operator/=(float s);
		Matrix3 operator-() const;
	};

	inline Matrix3 operator+(Matrix3 lhs, const Matrix3& rhs)
	{
		return lhs += rhs;
	}

	inline Matrix3 operator-(Matrix3 lhs, const Matrix3& rhs)
	{
		return lhs -= rhs;
	}

	inline Matrix3 operator*(Matrix3 lhs, float s)
	{
		return lhs *= s;
	}

	inline Matrix3 operator*(float s, Matrix3 rhs)
	{
		return rhs *= s;
	}

	inline Matrix3 operator/(Matrix3 lhs, float s)
	{
		return lhs /= s;
	}

	inline Matrix3 operator*(const Matrix3& lhs, const Matrix3& rhs)
	{
		Matrix3 result;
		for (unsigned int col = 0; col < 3; col++)
			for (unsigned int row = 0; row < 3; row++)
				result[col][row] = lhs.getRow(row).dot(rhs.columns[col]);
		return result;
	}

	inline Matrix3 operator/(const Matrix3& lhs, const Matrix3& rhs)
	{
		return lhs * rhs.inverse();
	}

	inline Vector3 operator*(const Matrix3& lhs, const Vector3& rhs)
	{
		return {
			lhs.getRow(0).dot(rhs),
			lhs.getRow(1).dot(rhs),
			lhs.getRow(2).dot(rhs)
		};
	}

	inline bool operator==(const Matrix3& lhs, const Matrix3& rhs)
	{
		for (unsigned int idx = 0; idx < 3; idx++)
			if (lhs[idx] != rhs[idx])
				return false;
		return true;
	}

	inline bool operator!=(const Matrix3& lhs, const Matrix3& rhs)
	{
		return !(lhs == rhs);
	}
}