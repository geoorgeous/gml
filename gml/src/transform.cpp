#include <cmath>

#include "../include/transform.hpp"

#include "../include/core.hpp"

namespace gml
{
	Transform::Transform()
		: m_sca(Vector3f::unit), m_posChanged(false), m_scaChanged(false), m_rotChanged(false), m_mat(Matrix4::identity)
	{ }

	const Vector3f& Transform::getPosition() const
	{
		return m_pos;
	}

	const Vector3f& Transform::getScale() const
	{
		return m_sca;
	}

	const Vector3f& Transform::getRotation() const
	{
		return m_rot;
	}

	const Vector3f& Transform::setPosition(const Vector3f& newPosition)
	{
		m_posChanged = true;
		return m_pos = newPosition;
	}

	const Vector3f& Transform::setScale(const Vector3f& newScale)
	{
		m_scaChanged = true;
		return m_sca = newScale;
	}

	const Vector3f& Transform::setRotation(const Vector3f& newRotation)
	{
		m_rotChanged = true;
		return m_rot;
	}

	const Vector3f& Transform::setPosition(float x, float y, float z)
	{
		return setPosition({ x, y, z });
	}

	const Vector3f& Transform::setScale(float x, float y, float z)
	{
		return setScale({ x, y, z });
	}

	const Vector3f& Transform::setRotation(float x, float y, float z)
	{
		return setRotation({ x, y, z });
	}

	const Matrix4& Transform::getMatrix() const
	{
		if (m_posChanged || m_scaChanged || m_rotChanged)
		{
			m_mat =
				transform_t(m_pos) *
				transform_s(m_sca) *
				transform_rX(m_rot.z) * transform_rY(m_rot.y) * transform_rZ(m_rot.z);

			m_posChanged = m_posChanged = m_rotChanged = false;
		}
		return m_mat;
	}
}