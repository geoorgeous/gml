/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "../vector/vector_2.hpp"

namespace gml
{
	struct Point2D;
	struct Line2D;
	struct Rect;

	/**
	 * \brief A simple circle struct.
	 * \detailed A plain-old-data struct mathematically representing a 2D circle.
	 */
	struct Circle 
	{
		static Circle unit;

		Vector2 center; /**< The center of the circle, defined as a 2D point in space by a vector. */
		float radius = 0.0f; /**< The radius of the circle. */
		float &x = center.x; /**< The position of the center of the circle along the x-axis. \note This member is a plain reference to the x component of center. */
		float &y = center.y; /**< The position of the center of the circle along the y-axis. \note This member is a plain reference to the y component of center. */

		float getDiameter() const;

		float getCircumference() const;

		bool intersects(const Point2D& p) const;
		bool intersects(const Line2D& l) const;
		bool intersects(const Circle& c) const;
		bool intersects(const Rect& r) const;

		bool operator==(const Circle& c) const;
		bool operator!=(const Circle& c) const;
	};
}