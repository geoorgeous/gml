#pragma once

#include "../vector/vector_3_f.hpp"

namespace gml
{
	struct Matrix3
	{
		float m[9] = {
			0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 0.0f
		};

		static const Matrix3 zero;
		static const Matrix3 identity;

		Matrix3 transpose() const;
		Matrix3 inverse() const;
		float determinant() const;

		float& operator[](int i);
		const float& operator[](int i) const;

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
		return {
			lhs[0] * rhs[0] + lhs[1] * rhs[3] + lhs[2] * rhs[6],
			lhs[0] * rhs[1] + lhs[1] * rhs[4] + lhs[2] * rhs[7],
			lhs[0] * rhs[2] + lhs[1] * rhs[5] + lhs[2] * rhs[8],

			lhs[3] * rhs[0] + lhs[4] * rhs[3] + lhs[5] * rhs[6],
			lhs[3] * rhs[1] + lhs[4] * rhs[4] + lhs[5] * rhs[7],
			lhs[3] * rhs[2] + lhs[4] * rhs[5] + lhs[5] * rhs[8],

			lhs[6] * rhs[0] + lhs[7] * rhs[3] + lhs[8] * rhs[6],
			lhs[6] * rhs[1] + lhs[7] * rhs[4] + lhs[8] * rhs[7],
			lhs[6] * rhs[2] + lhs[7] * rhs[5] + lhs[8] * rhs[8]
		};
	}

	inline Matrix3 operator/(const Matrix3& lhs, const Matrix3& rhs)
	{
		return lhs * rhs.inverse();
	}

	inline Vector3f operator*(const Matrix3& lhs, const Vector3f& rhs)
	{
		return {
			lhs[0] * rhs.x + lhs[1] * rhs.y + lhs[2] * rhs.z,
			lhs[3] * rhs.x + lhs[4] * rhs.y + lhs[5] * rhs.z,
			lhs[6] * rhs.x + lhs[7] * rhs.y + lhs[8] * rhs.z
		};
	}

	inline bool operator==(const Matrix3& lhs, const Matrix3& rhs)
	{
		return lhs[0] == rhs[0]
			&& lhs[1] == rhs[1]
			&& lhs[2] == rhs[2]
			&& lhs[3] == rhs[3]
			&& lhs[4] == rhs[4]
			&& lhs[5] == rhs[5]
			&& lhs[6] == rhs[6]
			&& lhs[7] == rhs[7]
			&& lhs[8] == rhs[8];
	}

	inline bool operator!=(const Matrix3& lhs, const Matrix3& rhs)
	{
		return !(lhs == rhs);
	}
}