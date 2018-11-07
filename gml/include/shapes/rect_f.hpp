#pragma once

#include "../vector/vector_2_f.hpp"

namespace gml
{
	struct Vector2f;

	struct Rectf
	{
		Vector2f halfExtents{ 0.0f, 0.0f };
		Vector2f center{ 0.0f, 0.0f };
		float &halfWidth = halfExtents.x, &halfHeight = halfExtents.y;
		float &x = center.x, &y = center.y;
	};
}