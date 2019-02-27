#include "../../include/shapes/rect.hpp"

#include "../../include/shapes/circle.hpp"
#include "../../include/shapes/intersections.hpp"
#include "../../include/shapes/line_2d.hpp"
#include "../../include/shapes/point_2d.hpp"

namespace gml
{
	float Rect::getWidth() const
	{
		return halfWidth * 2.0f;
	}

	float Rect::getHeight() const
	{
		return halfHeight * 2.0f;
	}

	float Rect::getLeft() const
	{
		return center.x - halfWidth;
	}

	float Rect::getRight() const
	{
		return center.x + halfWidth;
	}

	float Rect::getTop() const
	{
		return center.y - halfHeight;
	}

	float Rect::getBottom() const
	{
		return center.y + halfHeight;
	}

	Vector2 Rect::getTopLeft() const
	{
		return Vector2{ x - halfExtents.x, y - halfExtents.y };
	}

	Vector2 Rect::getTopRight() const
	{
		return Vector2{ x + halfExtents.x, y - halfExtents.y };
	}

	Vector2 Rect::getBottomLeft() const
	{
		return Vector2{ x - halfExtents.x, y + halfExtents.y };
	}

	Vector2 Rect::getBottomRight() const
	{
		return Vector2{ x + halfExtents.x, y + halfExtents.y };
	}

	float Rect::getPerimeter() const
	{
		return halfWidth * 4.0f + halfHeight * 4.0f;
	}

	bool Rect::intersects(const Point2D& p) const
	{
		return intersection(*this, p);
	}

	bool Rect::intersects(const Line2D& l) const
	{
		return intersection(*this, l);
	}

	bool Rect::intersects(const Circle& c) const
	{
		return intersection(*this, c);
	}

	bool Rect::intersects(const Rect& r) const
	{
		return intersection(*this, r);
	}

	bool Rect::operator==(const Rect& r) const
	{
		return center == r.center && halfExtents == r.halfExtents;
	}

	bool Rect::operator!=(const Rect& r) const
	{
		return !(*this == r);
	}
}