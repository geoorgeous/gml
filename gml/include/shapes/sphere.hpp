#pragma once

/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

namespace gml
{
	struct Point3D;
	struct Line3D;
	struct Cuboid;

	struct Sphere
	{
		Vector3 center;
		float& x = center.x;
		float& y = center.y;
		float& z = center.z;
		float radius = 0.0f;

		float getDiameter() const;

		float getSurfaceArea() const;

		float getVolume() const;

		bool intersects(const Point3D& p) const;
		bool intersects(const Line3D& l) const;
		bool intersects(const Sphere& s) const;
		bool intersects(const Cuboid& c) const;

		bool operator==(const Sphere& s) const;
		bool operator!=(const Sphere& s) const;
	};
}