#include "../../include/shapes/circle.hpp"

#include "../../include/core.hpp"

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

	bool Circle::intersects(const Circle& c) const
	{
		return center.dist(c.center) < radius + c.radius;
	}
}