#pragma once

/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

namespace gml
{
	struct Vector2i;
	struct Vector3f;
	
	/**
	 * \brief A mathematical 2D floating-point Vector.
	 * \details A plain-old-data struct representing a 2D Vector whose components are stored as floats.
	 */
	struct Vector2f
	{
		float x = 0.0f; /**< The x component of the Vector2f. \note This component can also be accessed using operator[](int).*/
		float y = 0.0f; /**< The y component of the Vector2f. \note This component can also be accessed using operator[](int).*/
		
		static const Vector2f zero; /**< A Vector2f with x and y members set to 0.0f. */
		static const Vector2f unit; /**< A Vector2f with x and y members set to 1.0f. The magnitude of this Vector2f will be 1.0f; hence a unit vector. */

		/**
		 * \brief Calculates and returns the magnitude of the vector multiplied by itself.
		 * \details Useful for when performance is paramount and the user wishes to avoid the use of the sqrt() function used in mag().
		 * \returns The magnitude of the vector squared.
		 */
		float magSqr() const;

		/**
		 * \brief Calculates and returns the magnitude of the vector.
		 * \details The vector's magnitude is also known as the vector's length or size.
		 * \returns The magnitude of the vector.
		 */
		float mag() const;

		/**
		 * \brief Calculates and returns the dot product of this vector and another.
		 * \param v The other vector used in calculating the dot product.
		 * \returns The dot product calculated from this vector and another.
		 */
		float dot(const Vector2f& v) const;

		/**
		 * \brief Calculates and returns the distance between this vector and another.
		 * \param v The other vector.
		 * \returns The distance between the two vectors in 2D space.
		 */
		float dist(const Vector2f& v) const;

		/**
		 * \brief Calculates and returns a unit vector with the same direction as this vector.
		 * \returns A unit vector with magnitude = 1.
		 */
		Vector2f normal() const;

		/**
		 * \brief Normalises the vector so it has magnitude = 1.
		 * \returns A reference to the vector.
		 */
		Vector2f& normalise();

		/**
		 * \brief Limits the vector's magnitude.
		 * \details This will make the vector keep its direction but extend/shrink its magnitude.
		 * \param magnitude The magnitude that the vector will be given.
		 */
		Vector2f& limit(float magnitude);

		/**
		 * \brief Accesses the vector's components using a given index.
		 * \warning This function performs no array-bounds checking. the passed index must be [0 .. 1].
	 	 * \returns A modifiable reference to the component found at position i.
		 */
		float& operator[](int i);

		/**
		 * \brief Accesses the vector's components using a given index.
		 * \warning This function performs no array-bounds checking. the passed index must be [0 .. 1].
		 * \returns A non-mutable reference to the component found at position i.
		 */
		const float& operator[](int i) const;

		/**
		 * \brief Adds another vector to the vector.
		 * \details Addition is performed component-wise.
		 * \param rhs Another vector which will be added to the vector.
		 * \returns A reference to the vector.
		 */
		Vector2f& operator+=(const Vector2f& rhs);

		/**
		 * \brief Subtracts another vector from the vector.
		 * \details Subtraction is performed component-wise.
		 * \param rhs Another vector which will be subtracted to the vector.
		 * \returns A reference to the vector.
		 */
		Vector2f& operator-=(const Vector2f& rhs);

		/**
		 * \brief Multiplies another vector with the vector.
		 * \details Multiplication is performed component-wise.
		 * \param rhs Another vector which will be multiplied with the vector.
		 * \returns A reference to the vector.
		 */
		Vector2f& operator*=(const Vector2f& rhs);

		/**
		 * \brief Divides another vector with the vector.
		 * \details Division is performed component-wise.
		 * \param rhs Another vector which will be divided with the vector.
		 * \returns A reference to the vector.
		 */
		Vector2f& operator/=(const Vector2f& rhs);

		/**
		 * \brief Multiplies the vector by a scalar value.
		 * \param s The value of which to multiply/scale the vector by.
		 * \returns A reference to the vector.
		 */
		Vector2f& operator*=(float s);

		/**
		 * \brief Divides the vector by a scalar value.
		 * \param s The value of which to divide/scale the vector by.
		 * \returns A reference to the vector.
		 */
		Vector2f& operator/=(float s);

		/**
		 * \brief Gets a negated version of the vector.
		 * \returns A new vector which is the inverse of the vector.
		 */
		Vector2f operator-() const;

		/**
		 * \brief Converts the vector to a Vector2i.
		 * \details A new integer vector is created by casting the vector's floating-point components to integers.
		 * \returns A new Vector2i.
		 */
		operator Vector2i() const;

		explicit operator Vector3f() const;
	};

	/**
	 * \brief Calculates the addition of two vectors.
	 * \details Addition is performed component-wise.
	 * \param lhs The vector from the left-hand-side of the addition operand.
	 * \param rhs The vector from the right-hand-side of the addition operand.
	 * \returns A new vector which is the addition of the two given vectors.
	 */
	inline Vector2f operator+(Vector2f lhs, const Vector2f& rhs)
	{
		return lhs += rhs;
	}

	/**
	 * \brief Calculates the subtraction of two vectors.
	 * \details Subtraction is performed component-wise.
	 * \param lhs The vector from the left-hand-side of the subtraction operand.
	 * \param rhs The vector from the right-hand-side of the subtraction operand.
	 * \returns A new vector which is the subtraction of the two given vectors.
	 */
	inline Vector2f operator-(Vector2f lhs, const Vector2f& rhs)
	{
		return lhs -= rhs;
	}

	/**
	 * \brief Calculates the multiplication of two vectors.
	 * \details Multiplication is performed component-wise.
	 * \param lhs The vector from the left-hand-side of the multiplication operand.
	 * \param rhs The vector from the right-hand-side of the multiplication operand.
	 * \returns A new vector which is the product of the two given vectors.
	 */
	inline Vector2f operator*(Vector2f lhs, const Vector2f& rhs)
	{
		return lhs *= rhs;
	}

	/**
	 * \brief Calculates the quotient of two vectors.
	 * \details Division is performed component-wise.
	 * \param lhs The vector from the left-hand-side of the division operand.
	 * \param rhs The vector from the right-hand-side of the division operand.
	 * \returns A new vector which is the quotient of the two given vectors.
	 */
	inline Vector2f operator/(Vector2f lhs, const Vector2f& rhs)
	{
		return lhs /= rhs;
	}

	/**
	 * \brief Multiplies/scales a vector by a value.
	 * \param lhs The vector to be multiplied/scaled.
	 * \param s The value to multiply/scale the vector by.
	 * \returns The result of the multiplication of the vector and the scalar value.
	 */
	inline Vector2f operator*(Vector2f lhs, float s)
	{
		return lhs *= s;
	}

	/**
	 * \brief Divides/scales a vector by a value.
	 * \param lhs The vector to be divided/scaled.
	 * \param s The value to divide/scale the vector by.
	 * \returns The result of the division of the vector and the scalar value.
	 */
	inline Vector2f operator/(Vector2f lhs, float s)
	{
		return lhs /= s;
	}

	/**
	 * \brief Multiplies/scales a vector by a value.
	 * \param s The value to multiply/scale the vector by.
	 * \param rhs The vector to be multiplied/scaled.
	 * \returns The result of the multiplication of the vector and the scalar value.
	 */
	inline Vector2f operator*(float s, Vector2f rhs)
	{
		return rhs *= s;
	}

	/**
	 * \brief Divides/scales a vector by a value.
	 * \param s The value to divide/scale the vector by.
	 * \param rhs The vector to be divided/scaled.
	 * \returns The result of the division of the vector and the scalar value.
	 */
	inline Vector2f operator/(float s, Vector2f rhs)
	{
		return rhs /= s;
	}

	/**
	 * \brief Compares two vectors.
	 * \details Comparisons are performed per-component.
	 * \param lhs The Vector2f to be compared to the second.
	 * \param lhs The Vector2f to be compared to the first.
	 * \returns True if the vectors are found to be equal.
	 */
	inline bool operator==(const Vector2f& lhs, const Vector2f& rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}

	/**
	 * \brief Compares two vectors.
	 * \details Comparisons are performed per-component.
	 * \param lhs The Vector2f to be compared to the second.
	 * \param lhs The Vector2f to be compared to the first.
	 * \returns True if the vectors are not found to be equal.
	 */
	inline bool operator!=(const Vector2f& lhs, const Vector2f& rhs)
	{
		return !(lhs == rhs);
	}
}