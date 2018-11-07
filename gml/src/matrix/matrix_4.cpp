#include <cmath>

#include "../../include/matrix/matrix_3.hpp"
#include "../../include/matrix/matrix_4.hpp"
#include "../../include/vector/vector_3_f.hpp"

namespace gml
{
	const Matrix4 Matrix4::zero{
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f
	};

	const Matrix4 Matrix4::identity{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	Matrix4 Matrix4::transpose() const
	{
		return {
			m[0], m[4], m[8], m[12],
			m[1], m[5], m[9], m[13],
			m[2], m[6], m[10], m[14],
			m[3], m[7], m[11], m[15]
		};
	}

	Matrix4 Matrix4::inverse() const
	{
		return (1.0f / determinant()) * Matrix4 {
			Matrix3{ m[5], m[6], m[7], m[9], m[10], m[11], m[13], m[14], m[15] }.determinant(),
			-Matrix3{ m[4], m[6], m[7], m[8], m[10], m[11], m[12], m[14], m[15] }.determinant(),
			Matrix3{ m[4], m[5], m[7], m[8], m[9], m[11], m[12], m[13], m[15] }.determinant(),
			-Matrix3{ m[4], m[5], m[6], m[8], m[9], m[10], m[12], m[13], m[14] }.determinant(),

			-Matrix3{ m[1], m[2], m[3], m[9], m[10], m[11], m[13], m[14], m[15] }.determinant(),
			Matrix3{ m[0], m[2], m[3], m[8], m[10], m[11], m[12], m[14], m[15] }.determinant(),
			-Matrix3{ m[0], m[1], m[3], m[8], m[9], m[11], m[12], m[13], m[15] }.determinant(),
			Matrix3{ m[0], m[1], m[2], m[8], m[9], m[10], m[12], m[13], m[14] }.determinant(),

			Matrix3{ m[1], m[2], m[3], m[5], m[6], m[7], m[13], m[14], m[15] }.determinant(),
			-Matrix3{ m[0], m[2], m[3], m[4], m[6], m[7], m[12], m[14], m[15] }.determinant(),
			Matrix3{ m[0], m[1], m[3], m[4], m[5], m[7], m[12], m[13], m[15] }.determinant(),
			-Matrix3{ m[0], m[1], m[2], m[4], m[5], m[6], m[12], m[13], m[14] }.determinant(),

			-Matrix3{ m[1], m[2], m[3], m[5], m[6], m[7], m[9], m[10], m[11] }.determinant(),
			Matrix3{ m[0], m[2], m[3], m[4], m[6], m[7], m[8], m[10], m[11] }.determinant(),
			-Matrix3{ m[0], m[1], m[3], m[4], m[5], m[7], m[8], m[9], m[11] }.determinant(),
			Matrix3{ m[0], m[1], m[2], m[4], m[5], m[6], m[8], m[9], m[10] }.determinant()
		}.transpose();
	}

	float Matrix4::determinant() const
	{
		float a = Matrix3{
			m[5], m[6], m[7],
			m[9], m[10], m[11],
			m[13], m[14], m[15]
		}.determinant() * m[0];

		float b = Matrix3{
			m[4], m[6], m[7],
			m[8], m[10], m[11],
			m[12], m[14], m[15]
		}.determinant() * m[1];

		float c = Matrix3{
			m[4], m[5], m[7],
			m[8], m[9], m[11],
			m[12], m[13], m[15]
		}.determinant() * m[2];

		float d = Matrix3{
			m[4], m[5], m[6],
			m[8], m[9], m[10],
			m[12], m[13], m[14]
		}.determinant() * m[3];

		return a - b + c - d;
	}

	float& Matrix4::operator[](int i)
	{
		return m[i];
	}

	const float& Matrix4::operator[](int i) const
	{
		return m[i];
	}

	Matrix4& Matrix4::operator+=(const Matrix4& rhs)
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
		m[9] += rhs[9];
		m[10] += rhs[10];
		m[11] += rhs[11];
		m[12] += rhs[12];
		m[13] += rhs[13];
		m[14] += rhs[14];
		m[15] += rhs[15];
		return *this;
	}

	Matrix4& Matrix4::operator-=(const Matrix4& rhs)
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
		m[9] -= rhs[9];
		m[10] -= rhs[10];
		m[11] -= rhs[11];
		m[12] -= rhs[12];
		m[13] -= rhs[13];
		m[14] -= rhs[14];
		m[15] -= rhs[15];
		return *this;
	}

	Matrix4& Matrix4::operator*=(float s)
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
		m[9] *= s;
		m[10] *= s;
		m[11] *= s;
		m[12] *= s;
		m[13] *= s;
		m[14] *= s;
		m[15] *= s;
		return *this;
	}

	Matrix4& Matrix4::operator/=(float s)
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
		m[9] /= s;
		m[10] /= s;
		m[11] /= s;
		m[12] /= s;
		m[13] /= s;
		m[14] /= s;
		m[15] /= s;
		return *this;
	}

	Matrix4 Matrix4::operator-() const
	{
		return *this * -1.0f;
	}

	Matrix4 transform_t(float tX, float tY, float tZ)
	{
		return {
			1.0f, 0.0f, 0.0f, tX,
			0.0f, 1.0f, 0.0f, tY,
			0.0f, 0.0f, 1.0f, tZ,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	}

	Matrix4 transform_t(const Vector3f& v)
	{
		return transform_t(v.x, v.y, v.z);
	}

	Matrix4 transform_s(float sX, float sY, float sZ)
	{
		return {
			sX, 0.0f, 0.0f, 0.0f,
			0.0f, sY, 0.0f, 0.0f,
			0.0f, 0.0f, sZ, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	}

	Matrix4 transform_s(const Vector3f& v)
	{
		return transform_t(v.x, v.y, v.z);
	}

	Matrix4 transform_rX(float radians)
	{
		return {
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, cosf(radians), -sinf(radians), 0.0f,
			0.0f, sinf(radians), cosf(radians), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	}

	Matrix4 transform_rY(float radians)
	{
		return {
			cosf(radians), 0.0f, sinf(radians), 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			-sinf(radians), 0.0f, cosf(radians), 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	}

	Matrix4 transform_rZ(float radians)
	{
		return {
			cosf(radians), -sinf(radians), 0.0f, 0.0f,
			sinf(radians), cosf(radians), 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	}
}