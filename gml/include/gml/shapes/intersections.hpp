/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

namespace gml
{
	struct Point2D;
	struct Line2D;
	struct Circle;
	struct Rect;
	struct Point3D;
	struct Line3D;
	struct Sphere;
	struct Cuboid;

	bool intersection(const Point2D& a, const Point2D& b);
	bool intersection(const Point2D& a, const Line2D& b);
	bool intersection(const Point2D& a, const Circle& b);
	bool intersection(const Point2D& a, const Rect& b);
	bool intersection(const Line2D& a, const Point2D& b);
	bool intersection(const Line2D& a, const Line2D& b);
	bool intersection(const Line2D& a, const Circle& b);
	bool intersection(const Line2D& a, const Rect& b);
	bool intersection(const Circle& a, const Point2D& b);
	bool intersection(const Circle& a, const Line2D& b);
	bool intersection(const Circle& a, const Circle& b);
	bool intersection(const Circle& a, const Rect& b);
	bool intersection(const Rect& a, const Point2D& b);
	bool intersection(const Rect& a, const Line2D& b);
	bool intersection(const Rect& a, const Circle& b);
	bool intersection(const Rect& a, const Rect& b);

	bool intersection(const Point3D& a, const Point3D& b);
	bool intersection(const Point3D& a, const Line3D& b);
	bool intersection(const Point3D& a, const Sphere& b);
	bool intersection(const Point3D& a, const Cuboid& b);
	bool intersection(const Line3D& a, const Point3D& b);
	bool intersection(const Line3D& a, const Line3D& b);
	bool intersection(const Line3D& a, const Sphere& b);
	bool intersection(const Line3D& a, const Cuboid& b);
	bool intersection(const Sphere& a, const Point3D& b);
	bool intersection(const Sphere& a, const Line3D& b);
	bool intersection(const Sphere& a, const Sphere& b);
	bool intersection(const Sphere& a, const Cuboid& b);
	bool intersection(const Cuboid& a, const Point3D& b);
	bool intersection(const Cuboid& a, const Line3D& b);
	bool intersection(const Cuboid& a, const Sphere& b);
	bool intersection(const Cuboid& a, const Cuboid& b);
}