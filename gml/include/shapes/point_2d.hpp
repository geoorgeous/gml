#pragma once

/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#include "../vector/vector_2.hpp"

namespace gml
{
	struct Line2D;
	struct Circle;
	struct Rect;

	struct Point2D
	{
		Vector2 position;

		bool intersects(const Point2D& p) const;
		bool intersects(const Line2D& l) const;
		bool intersects(const Circle& c) const;
		bool intersects(const Rect& r) const;

		bool operator==(const Point2D& p) const;
		bool operator!=(const Point2D& p) const;
	};
}