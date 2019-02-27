#include "../../include/shapes/circle.hpp"

#include "../../include/core.hpp"
#include "../../include/shapes/intersections.hpp"
#include "../../include/shapes/line_2d.hpp"
#include "../../include/shapes/point_2d.hpp"
#include "../../include/shapes/rect.hpp"

namespace gml
{
	float Circle::getDiameter() const
	{
		return radius * 2.0f;
	}

	float Circle::getCircumference() const
	{
		return _PI * getDiameter();
	}

	bool Circle::intersects(const Point2D& p) const
	{
		return intersection(*this, p);
	}

	bool Circle::intersects(const Line2D& l) const
	{
		return intersection(*this, l);
	}

	bool Circle::intersects(const Circle& c) const
	{
		return intersection(*this, c);
	}

	bool Circle::intersects(const Rect& r) const
	{
		return intersection(*this, r);
	}

	bool Circle::operator==(const Circle& c) const
	{
		return center == c.center && radius == c.radius;
	}

	bool Circle::operator!=(const Circle& c) const
	{
		return !(*this == c);
	}
}