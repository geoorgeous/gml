/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "../vector/vector_4.hpp"

namespace gml
{
	struct Matrix2;
	struct Matrix3;
	struct Vector3;
	struct Quaternion;

	struct Matrix4
	{
		static const Matrix4 zero;
		static const Matrix4 identity;

		Vector4 columns[4];

		Matrix4() = default;
		Matrix4(float a, float b, float c, float d,
			float e, float f, float g, float h,
			float i, float j, float k, float l,
			float m, float n, float o, float p);
		Matrix4(const Vector4& col0, const Vector4& col1, const Vector4& col2, const Vector4& col3);
		Matrix4(const Matrix2& mat2);
		Matrix4(const Matrix3& mat3);
		Vector4 getRow(unsigned int idx) const;
		Matrix4 transpose() const;
		Matrix4 inverse() const;
		float determinant() const;

		Vector4& operator[](unsigned int idx);
		const Vector4& operator[](unsigned int idx) const;

		Matrix4& operator+=(const Matrix4& rhs);
		Matrix4& operator-=(const Matrix4& rhs);
		Matrix4& operator*=(float s);
		Matrix4& operator/=(float s);
		Matrix4 operator-() const;
	};

	inline Matrix4 operator+(Matrix4 lhs, const Matrix4& rhs)
	{
		return lhs += rhs;
	}

	inline Matrix4 operator-(Matrix4 lhs, const Matrix4& rhs)
	{
		return lhs -= rhs;
	}

	inline Matrix4 operator*(Matrix4 lhs, float s)
	{
		return lhs *= s;
	}

	inline Matrix4 operator*(float s, Matrix4 rhs)
	{
		return rhs *= s;
	}

	inline Matrix4 operator/(Matrix4 lhs, float s)
	{
		return lhs /= s;
	}

	inline Matrix4 operator*(const Matrix4& lhs, const Matrix4& rhs)
	{
		Matrix4 result;
		for (unsigned int col = 0; col < 4; col++)
			for (unsigned int row = 0; row < 4; row++)
				result[col][row] = lhs.getRow(row).dot(rhs.columns[col]);
		return result;
	}

	inline Matrix4 operator/(const Matrix4& lhs, const Matrix4& rhs)
	{
		return lhs * rhs.inverse();
	}

	inline Vector4 operator*(const Matrix4& lhs, const Vector4& rhs)
	{
		return {
			lhs.getRow(0).dot(rhs),
			lhs.getRow(1).dot(rhs),
			lhs.getRow(2).dot(rhs),
			lhs.getRow(3).dot(rhs)
		};
	}

	inline bool operator==(const Matrix4& lhs, const Matrix4& rhs)
	{
		for (unsigned int idx = 0; idx < 4; idx++)
			if (lhs[idx] != rhs[idx])
				return false;
		return true;
	}

	inline bool operator!=(const Matrix4& lhs, const Matrix4& rhs)
	{
		return !(lhs == rhs);
	}
}