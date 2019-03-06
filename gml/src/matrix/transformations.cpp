#include "../../include/gml/matrix/transformations.hpp"

#include "../../include/gml/quaternion.hpp"
#include "../../include/gml/vectors.hpp"

namespace gml
{
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
		return Matrix4{
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