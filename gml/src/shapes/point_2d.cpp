#include "../../include/shapes/point_2d.hpp"

#include "../../include/shapes/circle.hpp"
#include "../../include/shapes/intersections.hpp"
#include "../../include/shapes/line_2d.hpp"
#include "../../include/shapes/rect.hpp"

namespace gml
{
	bool Point2D::intersects(const Point2D& p) const
	{
		return intersection(*this, p);
	}

	bool Point2D::intersects(const Line2D& l) const
	{
		return intersection(*this, l);
	}

	bool Point2D::intersects(const Circle& c) const
	{
		return intersection(*this, c);
	}

	bool Point2D::intersects(const Rect& r) const
	{
		return intersection(*this, r);
	}

	bool Point2D::operator==(const Point2D& p) const
	{
		return position == p.position;
	}

	bool Point2D::operator!=(const Point2D& p) const
	{
		return !(*this == p);
	}
}