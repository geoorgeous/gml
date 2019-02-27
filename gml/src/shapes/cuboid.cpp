#include "../../include/shapes/cuboid.hpp"

#include "../../include/shapes/intersections.hpp"
#include "../../include/shapes/line_3d.hpp"
#include "../../include/shapes/point_3d.hpp"
#include "../../include/shapes/sphere.hpp"

namespace gml
{
	float Cuboid::getWidth() const
	{
		return halfWidth * 2.0f;
	}

	float Cuboid::getHeight() const
	{
		return halfHeight * 2.0f;
	}

	float Cuboid::getDepth() const
	{
		return halfDepth * 2.0f;
	}

	float Cuboid::getSurfaceArea() const
	{
		return 2.0f * (getWidth() * getHeight() + getWidth() * getDepth() + getHeight() * getDepth());
	}

	float Cuboid::getVolume() const
	{
		return getWidth() * getHeight() * getDepth();
	}

	bool Cuboid::intersects(const Point3D& p) const
	{
		return intersection(*this, p);
	}

	bool Cuboid::intersects(const Line3D& l) const
	{
		return intersection(*this, l);
	}

	bool Cuboid::intersects(const Sphere& s) const
	{
		return intersection(*this, s);
	}

	bool Cuboid::intersects(const Cuboid& c) const
	{
		return intersection(*this, c);
	}

	bool Cuboid::operator==(const Cuboid& c) const
	{
		return center == c.center && halfExtents == c.halfExtents;
	}

	bool Cuboid::operator!=(const Cuboid& c) const
	{
		return !(*this == c);
	}
}