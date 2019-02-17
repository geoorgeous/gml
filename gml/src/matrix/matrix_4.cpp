#include <cmath>

#include "../../include/core.hpp"
#include "../../include/matrix/matrix_2.hpp"
#include "../../include/matrix/matrix_3.hpp"
#include "../../include/matrix/matrix_4.hpp"
#include "../../include/quaternion.hpp"
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


	Matrix4::Matrix4(float a, float b, float c, float d,
		float e, float f, float g, float h,
		float i, float j, float k, float l,
		float m, float n, float o, float p)
		: m{ a, b, c, d,
			e, f, g, h,
			i, j, k, l,
			m, n, o, p }
	{ }

	Matrix4::Matrix4(const Matrix2& mat2)
		: m{ mat2[0], mat2[1], 0.0f, 0.0f,
		mat2[2], mat2[3], 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f }
	{ }

	Matrix4::Matrix4(const Matrix3& mat3)
		: m{ mat3[0], mat3[1], mat3[2], 0.0f,
		mat3[3], mat3[4], mat3[5], 0.0f,
		mat3[6], mat3[7], mat3[8], 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f }
	{ }

	Matrix3 Matrix4::topLeft() const
	{
		return {
			m[0], m[1], m[2],
			m[4], m[5], m[6],
			m[8], m[9], m[10]
		};
	}

	Matrix3 Matrix4::topRight() const
	{
		return {
			m[1], m[2], m[3],
			m[5], m[6], m[7],
			m[9], m[10], m[11]
		};
	}

	Matrix3 Matrix4::bottomLeft() const
	{
		return {
			m[4], m[5], m[6],
			m[8], m[9], m[10],
			m[12], m[13], m[14]
		};
	}

	Matrix3 Matrix4::bottomRight() const
	{
		return {
			m[5], m[6], m[7],
			m[9], m[10], m[11],
			m[13], m[14], m[15]
		};
	}

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

	Matrix4 transform_r(const Quaternion& q)
	{
		float xx = q.x * q.x;
		float xy = q.x * q.y;
		float xz = q.x * q.z;
		float xw = q.x * q.w;

		float yy = q.y * q.y;
		float yz = q.y * q.z;
		float yw = q.y * q.w;

		float zz = q.z * q.z;
		float zw = q.z * q.w;

		return {
			1 - 2 * (yy + zz),
			2 * (xy + zw),
			2 * (xz - yw),
			0,

			2 * (xy - zw),
			1 - 2 * (xx + zz),
			2 * (yz + xw),
			0,

			2 * (xz + yw),
			2 * (yz - xw),
			1 - 2 * (xx + yy),
			0,
			
			0, 0, 0, 1
		};
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

	Matrix4 perspective(float vFOV, float aspect, float zNear, float zFar)
	{
		const float zRange = zNear - zFar;
		const float f = 1.0f / tanf(vFOV / 2.0f);
		return Matrix4{
			f / aspect, 0, 0, 0,
			0, f, 0, 0,
			0, 0, (zFar + zNear) / zRange, (2 * zFar * zNear) / zRange,
			0, 0, -1, 0
		};
	}

	Matrix4 view(const gml::Vector3f& right, const gml::Vector3f& up, const gml::Vector3f& forward, const gml::Vector3f& eye)
	{
		return Matrix4 {
			right.x, up.x, forward.x, -eye.x,
			right.y, up.y, forward.y, -eye.y,
			right.z, up.z, forward.z, -eye.z,
			0.0f, 0.0f, 0.0f, 1.0f
		};
	}

	Matrix4 lookAt(const Vector3f& eye, const Vector3f& target, const Vector3f& up)
	{
		gml::Vector3f f = (target - eye).normal();
		gml::Vector3f s = f.cross(up).normal();
		gml::Vector3f u = s.cross(f);

		return Matrix4 {
			s.x, s.y, s.z, -s.dot(eye),
			u.x, u.y, u.z, -u.dot(eye),
			-f.x, -f.y, -f.z, f.dot(eye),
			0, 0, 0, 1
		};
	}
}