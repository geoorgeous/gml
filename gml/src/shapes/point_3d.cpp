#include "../../include/shapes/point_3d.hpp"

#include "../../include/shapes/cuboid.hpp"
#include "../../include/shapes/intersections.hpp"
#include "../../include/shapes/line_3d.hpp"
#include "../../include/shapes/sphere.hpp"

namespace gml
{
	bool Point3D::intersects(const Point3D& p) const
	{
		return intersection(*this, p);
	}

	bool Point3D::intersects(const Line3D& l) const
	{
		return intersection(*this, l);
	}

	bool Point3D::intersects(const Sphere& s) const
	{
		return intersection(*this, s);
	}

	bool Point3D::intersects(const Cuboid& c) const
	{
		return intersection(*this, c);
	}

	bool Point3D::operator==(const Point3D& p) const
	{
		return position == p.position;
	}

	bool Point3D::operator!=(const Point3D& p) const
	{
		return !(*this == p);
	}
}