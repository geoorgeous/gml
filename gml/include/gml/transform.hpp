/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "matrices.hpp"
#include "quaternion.hpp"
#include "vectors.hpp"

namespace gml
{
	struct Vector3;

	class Transform
	{
	public:
		Transform();

		const Vector3& getPosition() const;
		const Vector3& getScale() const;
		const Vector3& getRotation() const;

		const Vector3& setPosition(const Vector3& newPosition);
		const Vector3& setScale(const Vector3& newScale);
		const Vector3& setRotation(const Vector3& newRotation);
		const Vector3& setPosition(float x, float y, float z);
		const Vector3& setScale(float x, float y, float z);
		const Vector3& setRotation(float x, float y, float z);

		const Matrix4& getMatrix() const;

		Transform& operator+=(const Transform& rhs);
		Transform& operator-=(const Transform& rhs);

	private:
		Vector3 m_pos;
		Vector3 m_sca;
		Vector3 m_rot;
		mutable Matrix4 m_mat;
		mutable bool m_posChanged;
		mutable bool m_scaChanged;
		mutable bool m_rotChanged;
	};

	inline Transform operator+(Transform lhs, const Transform& rhs)
	{
		lhs.setPosition(lhs.getPosition() + rhs.getPosition());
		lhs.setScale(lhs.getScale() + rhs.getScale());
		lhs.setRotation(lhs.getRotation() + rhs.getRotation());
		return lhs;
	}

	inline Transform operator-(Transform lhs, const Transform& rhs)
	{
		lhs.setPosition(lhs.getPosition() - rhs.getPosition());
		lhs.setScale(lhs.getScale() - rhs.getScale());
		lhs.setRotation(lhs.getRotation() - rhs.getRotation());
		return lhs;
	}
	
	inline bool operator==(const Transform& lhs, const Transform& rhs)
	{
		return lhs.getPosition() == rhs.getPosition() && lhs.getScale() == rhs.getScale() && lhs.getRotation() == rhs.getRotation();
	}

	inline bool operator!=(const Transform& lhs, const Transform& rhs)
	{
		return !(lhs == rhs);
	}
}