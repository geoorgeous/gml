/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "../vector/vector_3.hpp"

namespace gml
{
	struct Point3D;
	struct Sphere;
	struct Cuboid;

	struct Line3D
	{
		Vector3 p1;
		Vector3 p2;

		float getLength() const;

		bool intersects(const Point3D& p) const;
		bool intersects(const Line3D& l) const;
		bool intersects(const Sphere& s) const;
		bool intersects(const Cuboid& c) const;

		bool operator==(const Line3D& l) const;
		bool operator!=(const Line3D& l) const;
	};
}