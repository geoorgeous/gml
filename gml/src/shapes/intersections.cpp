#include "../../include/gml/shapes/intersections.hpp"

#include "../../include/gml/shapes/circle.hpp"
#include "../../include/gml/shapes/cuboid.hpp"
#include "../../include/gml/shapes/line_2d.hpp"
#include "../../include/gml/shapes/line_3d.hpp"
#include "../../include/gml/shapes/point_2d.hpp"
#include "../../include/gml/shapes/point_3d.hpp"
#include "../../include/gml/shapes/rect.hpp"
#include "../../include/gml/shapes/sphere.hpp"

namespace gml
{
	bool intersection(const Point2D& a, const Point2D& b)
	{
		return a == b;
	}

	bool intersection(const Point2D& a, const Line2D& b)
	{
		// todo: point-line (2D) intersection
		return false;
	}

	bool intersection(const Point2D& a, const Circle& b)
	{
		return b.center.distance(a.position) <= b.radius;
	}

	bool intersection(const Point2D& a, const Rect& b)
	{
		if (a.position.x < b.getLeft() ||
			a.position.x > b.getRight() ||
			a.position.y < b.getTop() ||
			a.position.y > b.getBottom())
			return false;
		return true;
	}

	bool intersection(const Line2D& a, const Point2D& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Line2D& a, const Line2D& b)
	{
		// todo: line-line (2D) intersection
		return false;
	}

	bool intersection(const Line2D& a, const Circle& b)
	{
		// todo: line-circle intersection
		return false;
	}

	bool intersection(const Line2D& a, const Rect& b)
	{
		// todo: line-rect intersection
		return false;
	}

	bool intersection(const Circle& a, const Point2D& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Circle& a, const Line2D& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Circle& a, const Circle& b)
	{
		return a.center.distance(b.center) <= a.radius + b.radius;
	}

	bool intersection(const Circle& a, const Rect& b)
	{
		// todo: circle-rect intersection
		return false;
	}

	bool intersection(const Rect& a, const Point2D& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Rect& a, const Line2D& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Rect& a, const Circle& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Rect& a, const Rect& b)
	{
		return !(a.getLeft() >= b.getRight()
			|| a.getRight() <= b.getLeft()
			|| a.getTop() >= b.getBottom()
			|| a.getBottom() <= b.getTop());
	}

	bool intersection(const Point3D& a, const Point3D& b)
	{
		return a == b;
	}

	bool intersection(const Point3D& a, const Line3D& b)
	{
		// todo: point-line (3D) intersection
		return false;
	}

	bool intersection(const Point3D& a, const Sphere& b)
	{
		return b.center.distance(a.position) <= b.radius;
	}

	bool intersection(const Point3D& a, const Cuboid& b)
	{
		// todo: point-cuboid intersection
		return false;
	}

	bool intersection(const Line3D& a, const Point3D& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Line3D& a, const Line3D& b)
	{
		// todo: line-line (3D) intersection
		return false;
	}

	bool intersection(const Line3D& a, const Sphere& b)
	{
		return false;
	}

	bool intersection(const Line3D& a, const Cuboid& b)
	{
		// todo: line-cuboid intersection
		return false;
	}

	bool intersection(const Sphere& a, const Point3D& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Sphere& a, const Line3D& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Sphere& a, const Sphere& b)
	{
		return a.center.distance(b.center) < a.radius + b.radius;
	}

	bool intersection(const Sphere& a, const Cuboid& b)
	{
		// todo: sphere-cuboid intersection
		return false;
	}

	bool intersection(const Cuboid& a, const Point3D& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Cuboid& a, const Line3D& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Cuboid& a, const Sphere& b)
	{
		return intersection(b, a);
	}

	bool intersection(const Cuboid& a, const Cuboid& b)
	{
		// todo: cuboid-cuboid intersection
		return false;
	}
}