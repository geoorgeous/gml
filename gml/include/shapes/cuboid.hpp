#pragma once

/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#include "../vector/vector_3.hpp"

namespace gml
{
	struct Point3D;
	struct Line3D;
	struct Sphere;

	struct Cuboid
	{
		Vector3 center;
		Vector3 halfExtents;
		float& x = center.x;
		float& y = center.y;
		float& z = center.z;
		float& halfWidth = halfExtents.x;
		float& halfHeight = halfExtents.y;
		float& halfDepth = halfExtents.z;

		float getWidth() const;
		float getHeight() const;
		float getDepth() const;

		float getSurfaceArea() const;

		float getVolume() const;

		bool intersects(const Point3D& p) const;
		bool intersects(const Line3D& l) const;
		bool intersects(const Sphere& s) const;
		bool intersects(const Cuboid& c) const;

		bool operator==(const Cuboid& c) const;
		bool operator!=(const Cuboid& c) const;
	};
}