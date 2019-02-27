#pragma once

/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#include "../vector/vector_2.hpp"

namespace gml
{
	struct Point2D;
	struct Circle;
	struct Rect;

	struct Line2D
	{
		Vector2 p1;
		Vector2 p2;

		float getLength() const;

		bool intersects(const Point2D& c) const;
		bool intersects(const Line2D& c) const;
		bool intersects(const Circle& c) const;
		bool intersects(const Rect& c) const;

		bool operator==(const Line2D& l) const;
		bool operator!=(const Line2D& l) const;
	};
}