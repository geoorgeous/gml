#pragma once

#include "../vector/vector_2_f.hpp"

namespace gml
{
	struct Circle
	{
		float radius = 0.0f;
		Vector2f center{ 0.0f, 0.0f };
		float &x = center.x, &y = center.y;
	};
}