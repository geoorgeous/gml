#include "../../include/matrix/matrix_2.hpp"
#include "../../include/matrix/matrix_3.hpp"
#include "../../include/matrix/matrix_4.hpp"

namespace gml
{
	const Matrix3 Matrix3::zero {
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f
	};

	const Matrix3 Matrix3::identity{
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};

	Matrix3::Matrix3(float a, float b, float c,
		float d, float e, float f,
		float g, float h, float i)
		: m{ a, b, c,
			d, e, f,
			g, h, i }
	{ }

	Matrix3::Matrix3(const Matrix2& mat2)
		: m{ mat2[0], mat2[1], 0.0f,
		mat2[2], mat2[3], 0.0f,
		0.0f, 0.0f, 0.0f }
	{ }

	Matrix3::Matrix3(const Matrix4& mat4)
	{
		*this = mat4.topLeft();
	}

	Matrix2 Matrix3::topLeft() const
	{
		return {
			m[0], m[1],
			m[3], m[4]
		};
	}

	Matrix2 Matrix3::topRight() const
	{
		return {
			m[1], m[2],
			m[4], m[5]
		};
	}

	Matrix2 Matrix3::bottomLeft() const
	{
		return {
			m[3], m[4],
			m[6], m[7]
		};
	}

	Matrix2 Matrix3::bottomRight() const
	{
		return {
			m[4], m[5],
			m[7], m[8]
		};
	}

	Matrix3 Matrix3::transpose() const
	{
		return {
			m[0], m[3], m[6],
			m[1], m[4], m[7],
			m[2], m[5], m[8]
		};
	}

	Matrix3 Matrix3::inverse() const
	{
		return (1.0f / determinant()) * Matrix3{
			m[4] * m[8] - m[5] * m[7],
			-(m[3] * m[8] - m[5] * m[6]),
			m[3] * m[7] - m[4] * m[6],

			-(m[1] * m[8] - m[2] * m[7]),
			m[0] * m[8] - m[2] * m[6],
			-(m[0] * m[7] - m[1] * m[6]),

			m[1] * m[5] - m[2] * m[4],
			-(m[0] * m[5] - m[2] * m[3]),
			m[0] * m[4] - m[1] * m[3]
		}.transpose();
	}

	float Matrix3::determinant() const
	{
		return (m[0] * (m[4] * m[8] - m[5] * m[7])) - (m[1] * (m[3]* m[8] - m[5] * m[6])) + (m[2] * (m[3] * m[7] - m[4] * m[6]));
	}

	float& Matrix3::operator[](int i)
	{
		return m[i];
	}

	const float& Matrix3::operator[](int i) const
	{
		return m[i];
	}

	Matrix3& Matrix3::operator+=(const Matrix3& rhs)
	{
		m[0] += rhs[0];
		m[1] += rhs[1];
		m[2] += rhs[2];
		m[3] += rhs[3];
		m[4] += rhs[4];
		m[5] += rhs[5];
		m[6] += rhs[6];
		m[7] += rhs[7];
		m[8] += rhs[8];
		return *this;
	}

	Matrix3& Matrix3::operator-=(const Matrix3& rhs)
	{
		m[0] -= rhs[0];
		m[1] -= rhs[1];
		m[2] -= rhs[2];
		m[3] -= rhs[3];
		m[4] -= rhs[4];
		m[5] -= rhs[5];
		m[6] -= rhs[6];
		m[7] -= rhs[7];
		m[8] -= rhs[8];
		return *this;
	}

	Matrix3& Matrix3::operator*=(float s)
	{
		m[0] *= s;
		m[1] *= s;
		m[2] *= s;
		m[3] *= s;
		m[4] *= s;
		m[5] *= s;
		m[6] *= s;
		m[7] *= s;
		m[8] *= s;
		return *this;
	}

	Matrix3& Matrix3::operator/=(float s)
	{
		m[0] /= s;
		m[1] /= s;
		m[2] /= s;
		m[3] /= s;
		m[4] /= s;
		m[5] /= s;
		m[6] /= s;
		m[7] /= s;
		m[8] /= s;
		return *this;
	}

	Matrix3 Matrix3::operator-() const
	{
		return *this * -1.0f;
	}
}