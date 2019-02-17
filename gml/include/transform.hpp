#pragma once

#include "matrix.hpp"
#include "quaternion.hpp"

namespace gml
{
	struct Vector3f;

	class Transform
	{
	public:
		Transform();

		const Vector3f& getPosition() const;
		const Vector3f& getScale() const;
		const Vector3f& getRotation() const;

		const Vector3f& setPosition(const Vector3f& newPosition);
		const Vector3f& setScale(const Vector3f& newScale);
		const Vector3f& setRotation(const Vector3f& newRotation);
		const Vector3f& setPosition(float x, float y, float z);
		const Vector3f& setScale(float x, float y, float z);
		const Vector3f& setRotation(float x, float y, float z);

		const Matrix4& getMatrix() const;

	private:
		Vector3f m_pos;
		Vector3f m_sca;
		Vector3f m_rot;
		mutable Matrix4 m_mat;
		mutable bool m_posChanged;
		mutable bool m_scaChanged;
		mutable bool m_rotChanged;
	};
	
	inline bool operator==(const Transform& lhs, const Transform& rhs)
	{
		return lhs.getPosition() == rhs.getPosition() && lhs.getScale() == rhs.getScale() && lhs.getRotation() == rhs.getRotation();
	}

	inline bool operator!=(const Transform& lhs, const Transform& rhs)
	{
		return !(lhs == rhs);
	}
}