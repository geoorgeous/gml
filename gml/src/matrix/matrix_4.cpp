#include <cmath>

#include "../../include/core.hpp"
#include "../../include/matrix/matrix_2.hpp"
#include "../../include/matrix/matrix_3.hpp"
#include "../../include/matrix/matrix_4.hpp"
#include "../../include/quaternion.hpp"
#include "../../include/vector/vector_3.hpp"

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
		: columns{
			Vector4(a, b, c, d),
			Vector4(e, f, g, h),
			Vector4(i, j, k, l),
			Vector4(m, n, o, p)
	} { }

	Matrix4::Matrix4(const Vector4& col0, const Vector4& col1, const Vector4& col2, const Vector4& col3)
		: columns{ col0, col1, col2, col3 }
	{ }

	Matrix4::Matrix4(const Matrix2& mat2)
		: columns{
			Vector4(mat2[0][0], mat2[0][1], 0.0f, 0.0f),
			Vector4(mat2[1][0], mat2[1][1], 0.0f, 0.0f),
			Vector4(0.0f, 0.0f, 0.0f, 0.0f),
			Vector4(0.0f, 0.0f, 0.0f, 0.0f)
	} { }

	Matrix4::Matrix4(const Matrix3& mat3)
		: columns{
			Vector4(mat3[0][0], mat3[0][1], mat3[0][2], 0.0f),
			Vector4(mat3[1][0], mat3[1][1], mat3[1][2], 0.0f),
			Vector4(mat3[2][0], mat3[2][1], mat3[2][2], 0.0f),
			Vector4(0.0f, 0.0f, 0.0f, 0.0f)
	} { }

	Vector4 Matrix4::getRow(unsigned int idx) const
	{
		return Vector4{
			columns[0][idx],
			columns[1][idx],
			columns[2][idx],
			columns[3][idx]
		};
	}

	Matrix3 Matrix4::topLeft() const
	{
		return {
			Vector3(columns[0]),
			Vector3(columns[1]),
			Vector3(columns[2])
		};
	}

	Matrix3 Matrix4::topRight() const
	{
		return {
			Vector3(columns[1]),
			Vector3(columns[2]),
			Vector3(columns[3])
		};
	}

	Matrix3 Matrix4::bottomLeft() const
	{
		return {
			Vector3(columns[0][1], columns[0][2], columns[0][3]),
			Vector3(columns[1][1], columns[1][2], columns[1][3]),
			Vector3(columns[2][1], columns[2][2], columns[2][3])
		};
	}

	Matrix3 Matrix4::bottomRight() const
	{
		return {
			Vector3(columns[1][1], columns[1][2], columns[1][3]),
			Vector3(columns[2][1], columns[2][2], columns[2][3]),
			Vector3(columns[3][1], columns[3][2], columns[3][3])
		};
	}

	Matrix4 Matrix4::transpose() const
	{
		return { getRow(0), getRow(1), getRow(2), getRow(3) };
	}

	Matrix4 Matrix4::inverse() const
	{
		return (1.0f / determinant()) * Matrix4 {
			Matrix3 { 
				columns[1][1], columns[1][2], columns[1][3],
				columns[2][1], columns[2][2], columns[2][3],
				columns[3][1], columns[3][2], columns[3][3] }.determinant(),
			-Matrix3{
				columns[1][0], columns[1][2], columns[1][3],
				columns[2][0], columns[2][2], columns[2][3],
				columns[3][0], columns[3][2], columns[3][3] }.determinant(),
			Matrix3{
				columns[1][0], columns[1][1], columns[1][3],
				columns[2][0], columns[2][1], columns[2][3],
				columns[3][0], columns[3][1], columns[3][3] }.determinant(),
			-Matrix3{
				columns[1][0], columns[1][1], columns[1][2],
				columns[2][0], columns[2][1], columns[2][2],
				columns[3][0], columns[3][1], columns[3][2] }.determinant(),

			-Matrix3 {
				columns[0][1], columns[0][2], columns[0][3],
				columns[2][1], columns[2][2], columns[2][3],
				columns[3][1], columns[3][2], columns[3][3] }.determinant(),
			Matrix3{
				columns[0][0], columns[0][2], columns[0][3],
				columns[2][0], columns[2][2], columns[2][3],
				columns[3][0], columns[3][2], columns[3][3] }.determinant(),
			-Matrix3{
				columns[0][0], columns[0][1], columns[0][3],
				columns[2][0], columns[2][1], columns[2][3],
				columns[3][0], columns[3][1], columns[3][3] }.determinant(),
			Matrix3{
				columns[0][0], columns[0][1], columns[0][2],
				columns[2][0], columns[2][1], columns[2][2],
				columns[3][0], columns[3][1], columns[3][2] }.determinant(),

			Matrix3 {
				columns[0][1], columns[0][2], columns[0][3],
				columns[1][1], columns[1][2], columns[1][3],
				columns[3][1], columns[3][2], columns[3][3] }.determinant(),
			-Matrix3{
				columns[0][0], columns[0][2], columns[0][3],
				columns[1][0], columns[1][2], columns[1][3],
				columns[3][0], columns[3][2], columns[3][3] }.determinant(),
			Matrix3{
				columns[0][0], columns[0][1], columns[0][3],
				columns[1][0], columns[1][1], columns[1][3],
				columns[3][0], columns[3][1], columns[3][3] }.determinant(),
			-Matrix3{
				columns[0][0], columns[0][1], columns[0][2],
				columns[1][0], columns[1][1], columns[1][2],
				columns[3][0], columns[3][1], columns[3][2] }.determinant(),

			-Matrix3 {
				columns[0][1], columns[0][2], columns[0][3],
				columns[1][1], columns[1][2], columns[1][3],
				columns[2][1], columns[2][2], columns[2][3] }.determinant(),
			Matrix3{
				columns[0][0], columns[0][2], columns[0][3],
				columns[1][0], columns[1][2], columns[1][3],
				columns[2][0], columns[2][2], columns[2][3] }.determinant(),
			-Matrix3{
				columns[0][0], columns[0][1], columns[0][3],
				columns[1][0], columns[1][1], columns[1][3],
				columns[2][0], columns[2][1], columns[2][3] }.determinant(),
			Matrix3{
				columns[0][0], columns[0][1], columns[0][2],
				columns[1][0], columns[1][1], columns[1][2],
				columns[2][0], columns[2][1], columns[2][2] }.determinant()
		}.transpose();
	}

	float Matrix4::determinant() const
	{
		float d = 0.0f;
		int c, subi, subj, i, j;
		Matrix3 submat;
		for (c = 0; c < 4; c++)
		{
			subi = 0;
			for (i = 1; i < 4; i++)
			{
				subj = 0;
				for (j = 0; j < 4; j++)
				{
					if (j == c)
						continue;
					submat[subi][subj] = columns[i][j];
					subj++;
				}
				subi++;
			}
			d = d + (std::pow(-1, c) * columns[0][c] * submat.determinant());
		}
		return d;
	}

	Vector4& Matrix4::operator[](unsigned int idx)
	{
		return columns[idx];
	}

	const Vector4& Matrix4::operator[](unsigned int idx) const
	{
		return columns[idx];
	}

	Matrix4& Matrix4::operator+=(const Matrix4& rhs)
	{
		for (int idx = 0; idx < 4; idx++)
			columns[idx] += rhs.columns[idx];
		return *this;
	}

	Matrix4& Matrix4::operator-=(const Matrix4& rhs)
	{
		for (int idx = 0; idx < 4; idx++)
			columns[idx] -= rhs.columns[idx];
		return *this;
	}

	Matrix4& Matrix4::operator*=(float s)
	{
		for (int idx = 0; idx < 4; idx++)
			columns[idx] *= s;
		return *this;
	}

	Matrix4& Matrix4::operator/=(float s)
	{
		for (int idx = 0; idx < 4; idx++)
			columns[idx] /= s;
		return *this;
	}

	Matrix4 Matrix4::operator-() const
	{
		return *this * -1.0f;
	}

	Matrix4 transform_t(float tX, float tY, float tZ)
	{
		return {
			Vector4(1.0f, 0.0f, 0.0f, 0.0f),
			Vector4(0.0f, 1.0f, 0.0f, 0.0f),
			Vector4(0.0f, 0.0f, 1.0f, 0.0f),
			Vector4(tX, tY, tZ, 1.0f)
		};
	}

	Matrix4 transform_t(const Vector3& v)
	{
		return transform_t(v.x, v.y, v.z);
	}

	Matrix4 transform_s(float sX, float sY, float sZ)
	{
		return {
			Vector4(sX, 0.0f, 0.0f, 0.0f),
			Vector4(0.0f, sY, 0.0f, 0.0f),
			Vector4(0.0f, 0.0f, sZ, 0.0f),
			Vector4(0.0f, 0.0f, 0.0f, 1.0f)
		};
	}

	Matrix4 transform_s(const Vector3& v)
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
			Vector4(1.0f - 2.0f * (yy + zz), 2.0f * (xy - zw), 2.0f * (xz + yw), 0.0f),
			Vector4(2.0f * (xy + zw), 1.0f - 2.0f * (xx + zz), 2.0f * (yz - xw), 0.0f),
			Vector4(2.0f * (xz - yw), 2.0f * (yz + xw), 1.0f - 2.0f * (xx + yy), 0.0f),
			Vector4(0.0f, 0.0f, 0.0f, 1.0f)
		};
	}

	Matrix4 transform_rX(float radians)
	{
		return {
			Vector4(1.0f, 0.0f, 0.0f, 0.0f),
			Vector4(0.0f, cosf(radians), sinf(radians), 0.0f),
			Vector4(0.0f, -sinf(radians), cosf(radians), 0.0f),
			Vector4(0.0f, 0.0f, 0.0f, 1.0f)
		};
	}

	Matrix4 transform_rY(float radians)
	{
		return {
			Vector4(cosf(radians), 0.0f, -sinf(radians), 0.0f),
			Vector4(0.0f, 1.0f, 0.0f, 0.0f),
			Vector4(sinf(radians), 0.0f, cosf(radians), 0.0f),
			Vector4(0.0f, 0.0f, 0.0f, 1.0f)
		};
	}

	Matrix4 transform_rZ(float radians)
	{
		return {
			Vector4(cosf(radians), sinf(radians), 0.0f, 0.0f),
			Vector4(-sinf(radians), cosf(radians), 0.0f, 0.0f),
			Vector4(0.0f, 0.0f, 1.0f, 0.0f),
			Vector4(0.0f, 0.0f, 0.0f, 1.0f)
		};
	}

	Matrix4 perspective(float verticalFOV, float aspect, float zNear, float zFar)
	{
		const float zRange = zNear - zFar;
		const float f = 1.0f / tanf(verticalFOV / 2.0f);
		return Matrix4{
			Vector4(f / aspect, 0.0f, 0.0f, 0.0f),
			Vector4(0.0f, f, 0.0f, 0.0f),
			Vector4(0.0f, 0.0f, (zFar + zNear) / zRange, -1.0f),
			Vector4(0.0f, 0.0f, (2 * zFar * zNear) / zRange, 0.0f)
		};
	}

	Matrix4 view(const gml::Vector3& right, const gml::Vector3& up, const gml::Vector3& forward, const gml::Vector3& eye)
	{
		return Matrix4 {
			Vector4(right.x, right.y, right.z, 0.0f),
			Vector4(up.x, up.y, up.z, 0.0f),
			Vector4(-forward.x, -forward.y, -forward.z, 0.0f),
			Vector4(-eye.x, -eye.y, -eye.z, 1.0f)
		};
	}

	Matrix4 lookAt(const Vector3& eye, const Vector3& target, const Vector3& up)
	{
		gml::Vector3 f = (eye - target).normal();
		gml::Vector3 s = up.cross(f).normal();
		gml::Vector3 u = f.cross(s);

		return Matrix4{
			Vector4(s.x, u.x, f.x, 0.0f),
			Vector4(s.y, u.y, f.y, 0.0f),
			Vector4(s.z, u.z, f.z, 0.0f),
			Vector4(s.dot(eye), u.dot(eye), f.dot(eye), 1.0f)
		};
	}
}