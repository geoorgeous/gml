#pragma once

#include "../vector/vector_4_f.hpp"

namespace gml
{
	struct Matrix4
	{
		float m[16] = {
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f
		};

		static const Matrix4 zero;
		static const Matrix4 identity;

		Matrix4 transpose() const;
		Matrix4 inverse() const;
		float determinant() const;

		float& operator[](int i);
		const float& operator[](int i) const;

		Matrix4& operator+=(const Matrix4& rhs);
		Matrix4& operator-=(const Matrix4& rhs);
		Matrix4& operator*=(float s);
		Matrix4& operator/=(float s);
		Matrix4 operator-() const;
	};

	Matrix4 transform_t(float tX, float tY, float tZ);
	Matrix4 transform_t(const Vector3f& v);
	Matrix4 transform_s(float sX, float sY, float sZ);
	Matrix4 transform_s(const Vector3f& v);
	Matrix4 transform_rX(float radians);
	Matrix4 transform_rY(float radians);
	Matrix4 transform_rZ(float radians);

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
		return {
			lhs[0] * rhs[0] + lhs[1] * rhs[4] + lhs[2] * rhs[8] + lhs[3] * rhs[12],
			lhs[0] * rhs[1] + lhs[1] * rhs[5] + lhs[2] * rhs[9] + lhs[3] * rhs[13],
			lhs[0] * rhs[2] + lhs[1] * rhs[6] + lhs[2] * rhs[10] + lhs[3] * rhs[14],
			lhs[0] * rhs[3] + lhs[1] * rhs[7] + lhs[2] * rhs[11] + lhs[3] * rhs[15],

			lhs[4] * rhs[0] + lhs[5] * rhs[4] + lhs[6] * rhs[8] + lhs[7] * rhs[12],
			lhs[4] * rhs[1] + lhs[5] * rhs[5] + lhs[6] * rhs[9] + lhs[7] * rhs[13],
			lhs[4] * rhs[2] + lhs[5] * rhs[6] + lhs[6] * rhs[10] + lhs[7] * rhs[14],
			lhs[4] * rhs[3] + lhs[5] * rhs[7] + lhs[6] * rhs[11] + lhs[7] * rhs[15],

			lhs[8] * rhs[0] + lhs[9] * rhs[4] + lhs[10] * rhs[8] + lhs[11] * rhs[12],
			lhs[8] * rhs[1] + lhs[9] * rhs[5] + lhs[10] * rhs[9] + lhs[11] * rhs[13],
			lhs[8] * rhs[2] + lhs[9] * rhs[6] + lhs[10] * rhs[10] + lhs[11] * rhs[14],
			lhs[8] * rhs[3] + lhs[9] * rhs[7] + lhs[10] * rhs[11] + lhs[11] * rhs[15],

			lhs[12] * rhs[0] + lhs[13] * rhs[4] + lhs[14] * rhs[8] + lhs[15] * rhs[12],
			lhs[12] * rhs[1] + lhs[13] * rhs[5] + lhs[14] * rhs[9] + lhs[15] * rhs[13],
			lhs[12] * rhs[2] + lhs[13] * rhs[6] + lhs[14] * rhs[10] + lhs[15] * rhs[14],
			lhs[12] * rhs[3] + lhs[13] * rhs[7] + lhs[14] * rhs[11] + lhs[15] * rhs[15],
		};
	}

	inline Matrix4 operator/(const Matrix4& lhs, const Matrix4& rhs)
	{
		return lhs * rhs.inverse();
	}

	inline Vector4f operator*(const Matrix4& lhs, const Vector4f& rhs)
	{
		return {
			lhs[0] * rhs.x + lhs[1] * rhs.y + lhs[2] * rhs.z + lhs[3] * rhs.w,
			lhs[4] * rhs.x + lhs[5] * rhs.y + lhs[6] * rhs.z + lhs[7] * rhs.w,
			lhs[8] * rhs.x + lhs[9] * rhs.y + lhs[10] * rhs.z + lhs[11] * rhs.w,
			lhs[12] * rhs.x + lhs[13] * rhs.y + lhs[14] * rhs.z + lhs[15] * rhs.w
		};
	}

	inline bool operator==(const Matrix4& lhs, const Matrix4& rhs)
	{
		return lhs[0] == rhs[0]
			&& lhs[1] == rhs[1]
			&& lhs[2] == rhs[2]
			&& lhs[3] == rhs[3]
			&& lhs[4] == rhs[4]
			&& lhs[5] == rhs[5]
			&& lhs[6] == rhs[6]
			&& lhs[7] == rhs[7]
			&& lhs[8] == rhs[8]
			&& lhs[9] == rhs[9]
			&& lhs[10] == rhs[10]
			&& lhs[11] == rhs[11]
			&& lhs[12] == rhs[12]
			&& lhs[13] == rhs[13]
			&& lhs[14] == rhs[14]
			&& lhs[15] == rhs[15];
	}

	inline bool operator!=(const Matrix4& lhs, const Matrix4& rhs)
	{
		return !(lhs == rhs);
	}
}