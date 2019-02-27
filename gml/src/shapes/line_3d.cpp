#include "../../include/shapes/line_3d.hpp"

#include "../../include/shapes/cuboid.hpp"
#include "../../include/shapes/intersections.hpp"
#include "../../include/shapes/point_3d.hpp"
#include "../../include/shapes/sphere.hpp"

namespace gml
{
	float Line3D::getLength() const
	{
		return p1.dist(p2);
	}

	bool Line3D::intersects(const Point3D& p) const
	{
		return intersection(*this, p);
	}

	bool Line3D::intersects(const Line3D& l) const
	{
		return intersection(*this, l);
	}

	bool Line3D::intersects(const Sphere& s) const
	{
		return intersection(*this, s);
	}

	bool Line3D::intersects(const Cuboid& c) const
	{
		return intersection(*this, c);
	}

	bool Line3D::operator==(const Line3D& l) const
	{
		return p1 == l.p1 && p2 == l.p2 ||
			p1 == l.p2 && p2 == l.p1;
	}

	bool Line3D::operator!=(const Line3D& l) const
	{
		return !(*this == l);
	}
}