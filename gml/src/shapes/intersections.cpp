#include <cmath>
#include <limits>

#include "../../include/gml/shapes/intersections.hpp"

#include "../../include/gml/shapes/circle.hpp"
#include "../../include/gml/shapes/cuboid.hpp"
#include "../../include/gml/shapes/line_2d.hpp"
#include "../../include/gml/shapes/line_3d.hpp"
#include "../../include/gml/shapes/point_2d.hpp"
#include "../../include/gml/shapes/point_3d.hpp"
#include "../../include/gml/shapes/rect.hpp"
#include "../../include/gml/shapes/sphere.hpp"
#include "../../include/gml/vector/vector_2.hpp"
#include "../../include/gml/vector/vector_3.hpp"

namespace gml
{
	bool intersection(const Point2D& a, const Point2D& b)
	{
		return a == b;
	}

	bool intersection(const Point2D& a, const Line2D& b)
	{
		Vector2 va = b.p1 - b.p2;
		Vector2 vb = a.position - b.p2;
		float area = va.x * vb.y - va.y * vb.x;
		if (std::abs(area) < std::numeric_limits<float>::epsilon())
			return true;
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
		return (((b.p1.x - a.p1.x)*(a.p2.y - a.p1.y) - (b.p1.y - a.p1.y)*(a.p2.x - a.p1.x))
			* ((b.p2.x - a.p1.x)*(a.p2.y - a.p1.y) - (b.p2.y - a.p1.y)*(a.p2.x - a.p1.x)) < 0)
			&&
			(((a.p1.x - b.p1.x)*(b.p2.y - b.p1.y) - (a.p1.y - b.p1.y)*(b.p2.x - b.p1.x))
				* ((a.p2.x - b.p1.x)*(b.p2.y - b.p1.y) - (a.p2.y - b.p1.y)*(b.p2.x - b.p1.x)) < 0);
		return false;
	}

	bool intersection(const Line2D& a, const Circle& b)
	{
		Vector2 d = a.p2 - a.p1;
		Vector2 f = a.p1 - b.center;
		float i = d.dot(d);
		float j = 2 * f.dot(d);
		float k = f.dot(f) - b.radius * b.radius;

		float discriminant = j * j - 4 * i * k;

		if (discriminant < 0)
			return false;

		discriminant = sqrt(discriminant);

		float t1 = (-j - discriminant) / (2 * i);
		float t2 = (-j + discriminant) / (2 * i);

		if (t1 >= 0 && t1 <= 1)
			return true;
		if (t2 >= 0 && t2 <= 1)
			return true;
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
		if (a.position.x > b.getRight() ||
			a.position.x < b.getLeft() ||
			a.position.y > b.getTop() ||
			a.position.y < b.getBottom() ||
			a.position.z > b.getFront() ||
			a.position.z < b.getBack())
			return false;
		return true;
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
		if (a.getLeft() > b.getRight() ||
			a.getRight() < b.getLeft() ||
			a.getBottom() > b.getTop() ||
			a.getTop() < b.getBottom() ||
			a.getBack() > b.getFront() ||
			a.getFront() < b.getBack())
			return false;
		return true;
	}
}