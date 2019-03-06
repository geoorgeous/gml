/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "matrix_4.hpp"

namespace gml
{
	struct Quaternion;
	struct Vector3;

	Matrix4 transform_t(float tX, float tY, float tZ);
	Matrix4 transform_t(const Vector3& v);
	Matrix4 transform_s(float sX, float sY, float sZ);
	Matrix4 transform_s(const Vector3& v);
	Matrix4 transform_r(const Quaternion& q);
	Matrix4 transform_rX(float radians);
	Matrix4 transform_rY(float radians);
	Matrix4 transform_rZ(float radians);

	Matrix4 perspective(float verticalFOV, float aspect, float zNear, float zFar);
	Matrix4 view(const Vector3& right, const Vector3& up, const Vector3& forward, const Vector3& eye);
	Matrix4 lookAt(const Vector3& eye, const Vector3& target, const Vector3& up);
}