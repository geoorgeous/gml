#pragma once

#include "../../include/vector/vector_4.hpp"

namespace gml
{
	struct Matrix2;
	struct Matrix3;
	struct Vector3;
	struct Quaternion;

	struct Matrix4
	{
		Vector4 columns[4] = {
			Vector4::zero,
			Vector4::zero,
			Vector4::zero,
			Vector4::zero
		};

		static const Matrix4 zero;
		static const Matrix4 identity;

		Matrix4() = default;
		Matrix4(float a, float b, float c, float d,
			float e, float f, float g, float h,
			float i, float j, float k, float l,
			float m, float n, float o, float p);
		Matrix4(const Vector4& col0, const Vector4& col1, const Vector4& col2, const Vector4& col3);
		Matrix4(const Matrix2& mat2);
		Matrix4(const Matrix3& mat3);
		Vector4 getRow(unsigned int idx) const;
		Matrix3 topLeft() const;
		Matrix3 topRight() const;
		Matrix3 bottomLeft() const;
		Matrix3 bottomRight() const;
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

	Matrix4 transform_t(float tX, float tY, float tZ);
	Matrix4 transform_t(const Vector3& v);
	Matrix4 transform_s(float sX, float sY, float sZ);
	Matrix4 transform_s(const Vector3& v);
	Matrix4 transform_r(const Quaternion& q);
	Matrix4 transform_rX(float radians);
	Matrix4 transform_rY(float radians);
	Matrix4 transform_rZ(float radians);

	Matrix4 perspective(float verticalFOV, float aspect, float zNear, float zFar);
	Matrix4 view(const Vector3& right, const Vector3& up, const Vector3& forward, const Vector3& eye);
	Matrix4 lookAt(const Vector3& eye, const Vector3& target, const Vector3& up);

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
		for (int col = 0; col < 4; col++)
			for (int row = 0; row < 4; row++)
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
		for (int idx = 0; idx < 4; idx++)
			if (lhs[idx] != rhs[idx])
				return false;
		return true;
	}

	inline bool operator!=(const Matrix4& lhs, const Matrix4& rhs)
	{
		return !(lhs == rhs);
	}
}