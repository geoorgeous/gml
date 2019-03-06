#include "../../include/gml/shapes/sphere.hpp"

#include "../../include/gml/core.hpp"
#include "../../include/gml/shapes/intersections.hpp"
#include "../../include/gml/shapes/line_2d.hpp"
#include "../../include/gml/shapes/point_2d.hpp"
#include "../../include/gml/shapes/rect.hpp"

namespace gml
{
	Sphere Sphere::unit = Sphere{ Vector3::zero, 0.5f };

	float Sphere::getDiameter() const
	{
		return radius * 2.0f;
	}

	float Sphere::getSurfaceArea() const
	{
		return 4.0f * _PI * radius * radius;
	}

	float Sphere::getVolume() const
	{
		return (4.0f / 3.0f) * _PI * radius * radius * radius;
	}

	bool Sphere::intersects(const Point3D& p) const
	{
		return intersection(*this, p);
	}

	bool Sphere::intersects(const Line3D& l) const
	{
		return intersection(*this, l);
	}

	bool Sphere::intersects(const Sphere& s) const
	{
		return intersection(*this, s);
	}

	bool Sphere::intersects(const Cuboid& c) const
	{
		return intersection(*this, c);
	}

	bool Sphere::operator==(const Sphere& c) const
	{
		return center == c.center && radius == c.radius;
	}

	bool Sphere::operator!=(const Sphere& c) const
	{
		return !(*this == c);
	}
}