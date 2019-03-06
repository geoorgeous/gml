/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "../vector/vector_3.hpp"

namespace gml
{
	struct Line3D;
	struct Sphere;
	struct Cuboid;

	struct Point3D
	{
		Vector3 position;

		bool intersects(const Point3D& p) const;
		bool intersects(const Line3D& l) const;
		bool intersects(const Sphere& s) const;
		bool intersects(const Cuboid& c) const;

		bool operator==(const Point3D& p) const;
		bool operator!=(const Point3D& p) const;
	};
}