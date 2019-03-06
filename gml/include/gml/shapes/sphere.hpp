/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "../vector/vector_3.hpp"

namespace gml
{
	struct Point3D;
	struct Line3D;
	struct Cuboid;

	struct Sphere
	{
		static Sphere unit;

		Vector3 center;
		float radius = 0.0f;
		float& x = center.x;
		float& y = center.y;
		float& z = center.z;

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