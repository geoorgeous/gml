/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "vector/vector_3.hpp"

namespace gml
{
	struct Quaternion
	{
		static Quaternion identity;

		float w = 0.0f;
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		static Quaternion fromEulerAngles(const Vector3& eulerAngles);

		Vector3 xyz() const;
		Quaternion conjugate() const;
		Quaternion normal() const;
		Quaternion& normalise();
		Vector3 getEulerAngles() const;

		Quaternion& operator=(const Quaternion& rhs);
		Quaternion& operator+=(const Quaternion& rhs);
		Quaternion& operator-=(const Quaternion& rhs);
		Quaternion& operator*=(const Quaternion& rhs);
	};

	Quaternion axisAngle(float degrees, const Vector3& axis, bool normaliseAxis);

	inline Quaternion operator+(Quaternion lhs, const Quaternion& rhs)
	{
		return lhs += rhs;
	}

	inline Quaternion operator-(Quaternion lhs, const Quaternion& rhs)
	{
		return lhs -= rhs;
	}

	inline Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs)
	{
		return Quaternion{
			lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z,
			lhs.w * rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
			lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w
		};
	}

	inline Vector3 operator*(const Vector3& lhs, const Quaternion& rhs)
	{
		return
			2.0f * rhs.xyz().dot(lhs) * rhs.xyz()
			+ (rhs.w * rhs.w - rhs.xyz().dot(rhs.xyz())) * lhs
			+ 2.0f * rhs.w * rhs.xyz().cross(lhs);
	}

	inline bool operator==(const Quaternion& lhs, const Quaternion& rhs)
	{
		return !(lhs.w != rhs.w || lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z);
	}

	inline bool operator!=(const Quaternion& lhs, const Quaternion& rhs)
	{
		return !(lhs == rhs);
	}
}