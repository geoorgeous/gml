#include <cmath>

#include "../include/gml/core.hpp"
#include "../include/gml/vector/vector_3.hpp"
#include "../include/gml/quaternion.hpp"

namespace gml
{
	Quaternion Quaternion::identity = { 1, 0, 0, 0 };

	Vector3 Quaternion::xyz() const
	{
		return Vector3{ x, y, z };
	}

	Quaternion Quaternion::conjugate() const
	{
		return {
			w,
			-x,
			-y,
			-z
		};
	}

	Quaternion Quaternion::normal() const
	{
		float n = std::sqrt(w * w + x * x + y * y + z * z);
		return Quaternion{ w / n, x / n, y / n, z / n };
	}

	Quaternion& Quaternion::normalise()
	{
		return *this = this->normal();
	}

	Vector3 Quaternion::getEulerAngles() const
	{
		return Vector3(
			atan2(2.0f * (w * x + y* z), 1.0f - 2.0f * (x * x + y * y)),
			asin(-2.0f * (w * y - z * x)),
			atan2(2.0f * (w * z + x * y), 1.0f - 2.0f * (y * y + z * z)));
	}

	Quaternion& Quaternion::operator=(const Quaternion& rhs)
	{
		w = rhs.w;
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}

	Quaternion& Quaternion::operator+=(const Quaternion& rhs)
	{
		w += rhs.w;
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}

	Quaternion& Quaternion::operator-=(const Quaternion& rhs)
	{
		w -= rhs.w;
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}

	Quaternion& Quaternion::operator*=(const Quaternion& rhs)
	{
		return *this = *this * rhs;
	}

	Quaternion Quaternion::fromEulerAngles(const Vector3& eulerAngles)
	{
		float cy = cos(eulerAngles.z * 0.5f);
		float sy = sin(eulerAngles.z * 0.5f);
		float cp = cos(eulerAngles.y * 0.5f);
		float sp = sin(eulerAngles.y * 0.5f);
		float cr = cos(eulerAngles.x * 0.5f);
		float sr = sin(eulerAngles.x * 0.5f);

		return {
			cy * cp * cr + sy * sp * sr,
			cy * cp * sr - sy * sp * cr,
			sy * cp * sr + cy * sp * cr,
			sy * cp * cr - cy * sp * sr
		};
	}

	Quaternion axisAngle(float degrees, const Vector3& axis, bool normaliseAxis)
	{
		float halfDeg = degrees * 0.5f;
		float sinHalfAngle = sin(radians(halfDeg));
		Vector3 v = (normaliseAxis) ? axis.normal() : axis;

		return {
			cos(halfDeg),
			v.x * sinHalfAngle,
			v.y * sinHalfAngle,
			v.z * sinHalfAngle
		};
	}
}