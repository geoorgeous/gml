#pragma once

namespace gml
{
	static const float _PI = 3.14159265359f;
	static const float _PI_OVR_180 = 0.01745329251f;
	static const float _180_OVR_PI = 57.2957795131f;

	inline float radians(float degrees)
	{
		return degrees * _180_OVR_PI;
	}

	inline float degrees(float radians)
	{
		return radians * _PI_OVR_180;
	}
}