#include <cmath>

#include "../include/core.hpp"
#include "../include/vector/vector_3_f.hpp"
#include "../include/quaternion.hpp"

namespace gml
{
	Quaternion Quaternion::conjugate() const
	{
		return {
			w,
			-x,
			-y,
			-z
		};
	}

	Quaternion& Quaternion::operator=(const Quaternion& rhs)
	{
		w = rhs.w;
		xyz = rhs.xyz;
		return *this;
	}

	Quaternion& Quaternion::operator+=(const Quaternion& rhs)
	{
		w += rhs.w;
		xyz += rhs.xyz;
		return *this;
	}

	Quaternion& Quaternion::operator-=(const Quaternion& rhs)
	{
		w -= rhs.w;
		xyz -= rhs.xyz;
		return *this;
	}

	Quaternion axisAngle(float degrees, const Vector3f& axis, bool normaliseAxis)
	{
		float halfDeg = degrees * 0.5f;
		float sinHalfDeg = sin(halfDeg);
		Vector3f v = (normaliseAxis) ? axis.normal() : axis;

		return {
			cos(halfDeg),
			v.x * sinHalfDeg,
			v.y * sinHalfDeg,
			v.z * sinHalfDeg
		};
	}
}