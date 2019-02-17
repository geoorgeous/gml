#pragma once

/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

/** 
 * \brief The main namespace for George's Maths Library. 
 */
namespace gml
{
	static const float _PI = 3.14159265359f; /**< GML PI constant. */
	static const float _PI_OVR_180 = 0.01745329251f; /**< GML PI/180 constant. */
	static const float _180_OVR_PI = 57.2957795131f; /**< GML 180/PI constant. */
	static const float _DEGS_IN_1RAD = _180_OVR_PI;
	static const float _RADS_IN_1DEG = _PI_OVR_180;

	inline float radians(float degrees)
	{
		return degrees * _PI_OVR_180;
	}

	inline float degrees(float radians)
	{
		return radians * _180_OVR_PI;
	}
}