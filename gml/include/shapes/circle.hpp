#pragma once

/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#include "../vector/vector_2_f.hpp"

namespace gml
{
	/**
	 * \brief A simple circle struct.
	 * \detailed A plain-old-data struct mathematically representing a 2D circle.
	 */
	struct Circle
	{
		float radius = 0.0f; /**< The radius of the circle. */
		Vector2f center{ 0.0f, 0.0f }; /**< The center of the circle, defined as a 2D point in space by a vector. */
		float &x = center.x; /**< The position of the center of the circle along the x-axis. \note This member is a plain reference to the x component of center. */
		float &y = center.y; /**< The position of the center of the circle along the y-axis. \note This member is a plain reference to the y component of center. */

		float getDiameter() const;

		float getCircumference() const;

		bool intersects(const Circle& c) const;
	};
}