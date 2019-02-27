#pragma once

/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#include "../vector/vector_2.hpp"

namespace gml
{
	struct Circle;
	struct Point2D;
	struct Line2D;

	/**
	 * \brief A simple rectangle struct.
	 * \detailed A plain-old-data struct mathematically representing a 2D rectangle.
	 */
	struct Rect
	{
		Vector2 center;
		Vector2 halfExtents;
		float &x = center.x, &y = center.y;
		float &halfWidth = halfExtents.x, &halfHeight = halfExtents.y;

		float getWidth() const;
		float getHeight() const;

		float getLeft() const;
		float getRight() const;
		float getTop() const;
		float getBottom() const;

		Vector2 getTopLeft() const;
		Vector2 getTopRight() const;
		Vector2 getBottomLeft() const;
		Vector2 getBottomRight() const;

		float getPerimeter() const;

		bool intersects(const Point2D& p) const;
		bool intersects(const Line2D& l) const;
		bool intersects(const Circle& c) const;
		bool intersects(const Rect& r) const;

		bool operator==(const Rect& r) const;
		bool operator!=(const Rect& r) const;
	};
}