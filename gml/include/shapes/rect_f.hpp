#pragma once

/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#include "../vector/vector_2_f.hpp"

namespace gml
{
	struct Vector2f;

	/**
	 * \brief A simple rectangle struct.
	 * \detailed A plain-old-data struct mathematically representing a 2D rectangle.
	 */
	struct Rectf
	{
		Vector2f halfExtents{ 0.0f, 0.0f };
		Vector2f center{ 0.0f, 0.0f };
		float &halfWidth = halfExtents.x, &halfHeight = halfExtents.y;
		float &x = center.x, &y = center.y;

		float getLeft() const;
		
		float getRight() const;

		float getTop() const;

		float getBottom() const;

		float getWidth() const;

		float getHeight() const;

		bool intersects(const Rectf& r) const;
	};
}