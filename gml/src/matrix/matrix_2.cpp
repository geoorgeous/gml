#include "../../include/matrix/matrix_2.hpp"
#include "../../include/matrix/matrix_3.hpp"
#include "../../include/matrix/matrix_4.hpp"

namespace gml
{
	const Matrix2 Matrix2::zero{
		0.0f, 0.0f,
		0.0f, 0.0f
	};

	const Matrix2 Matrix2::identity{
		1.0f, 0.0f,
		0.0f, 1.0f
	};

	Matrix2::Matrix2(float a, float b,
		float c, float d)
		: m{ a, b,
			c, d }
	{ }

	Matrix2::Matrix2(const Matrix3& mat3)
		: m{ mat3[0], mat3[1],
		mat3[3], mat3[4] }
	{ }

	Matrix2::Matrix2(const Matrix4& mat4)
		: m{ mat4[0], mat4[1],
		mat4[4], mat4[5] }
	{ }

	Matrix2 Matrix2::transpose() const
	{
		return {
			m[0], m[2],
			m[1], m[3]
		};
	}

	Matrix2 Matrix2::inverse() const
	{
		return (1.0f / determinant()) * Matrix2 { 
			m[3], -m[1], 
			-m[2], m[0] 
		};
	}

	float Matrix2::determinant() const
	{
		return m[0] * m[3] - m[1] * m[2];
	}

	float& Matrix2::operator[](int i)
	{
		return m[i];
	}

	const float& Matrix2::operator[](int i) const
	{
		return m[i];
	}

	Matrix2& Matrix2::operator+=(const Matrix2& rhs)
	{
		m[0] += rhs[0];
		m[1] += rhs[1];
		m[2] += rhs[2];
		m[3] += rhs[3];
		return *this;
	}

	Matrix2& Matrix2::operator-=(const Matrix2& rhs)
	{
		m[0] -= rhs[0];
		m[1] -= rhs[1];
		m[2] -= rhs[2];
		m[3] -= rhs[3];
		return *this;
	}

	Matrix2& Matrix2::operator*=(float s)
	{
		m[0] *= s;
		m[1] *= s;
		m[2] *= s;
		m[3] *= s;
		return *this;
	}

	Matrix2& Matrix2::operator/=(float s)
	{
		m[0] /= s;
		m[1] /= s;
		m[2] /= s;
		m[3] /= s;
		return *this;
	}

	Matrix2 Matrix2::operator-() const
	{
		return *this * -1.0f;
	}
}