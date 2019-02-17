#include "../../include/shapes/rect_f.hpp"

namespace gml
{
	float Rectf::getLeft() const
	{
		return center.x - halfWidth;
	}
	
	float Rectf::getRight() const
	{
		return center.x + halfWidth;
	}

	float Rectf::getTop() const
	{
		return center.y - halfHeight;
	}

	float Rectf::getBottom() const
	{
		return center.y + halfHeight;
	}

	float Rectf::getWidth() const
	{
		return halfWidth * 2.0f;
	}

	float Rectf::getHeight() const
	{
		return halfHeight * 2.0f;
	}

	bool Rectf::intersects(const Rectf& r) const
	{
		return !(getLeft() >= r.getRight()
			|| getRight() <= r.getLeft()
			|| getTop() >= r.getBottom()
			|| getBottom() <= r.getTop());
	}
}