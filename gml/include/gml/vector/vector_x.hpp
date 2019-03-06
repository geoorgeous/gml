/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include <cmath>

namespace gml
{
	/**
	 * \brief A struct template for Vectors.
	 * \warning Type T must support various operator overloads in order to create a Vector with it, otherwise your program will not compile. This Vector template was written only with the built in types in mind.
	 */
	template<typename T, unsigned int Size>
	struct Vector
	{
		T components[Size] = { 0 }; /**> An array of elements of type with a length of Size. The components of the Vector. */

		/**
		 * \brief Calculates and returns the magnitude of the vector multiplied by itself.
		 * \details Useful for when performance is paramount and the user wishes to avoid the use of the sqrt() function used in magnitude().
		 * \returns The magnitude of the vector squared.
		 */
		float magnitudeSq() const
		{
			float magSq = 0.0f;
			for (unsigned int idx = 0; idx < Size; idx++)
				magSq += components[idx] * components[idx];
			return magSq;
		}

		/**
		 * \brief Calculates and returns the magnitude of the vector.
		 * \details The vector's magnitude is also known as the vector's length or size.
		 * \returns The magnitude of the vector.
		 */
		float magnitude() const
		{
			return std::sqrt(magnitudeSq());
		}

		/**
		 * \brief Calculates and returns the dot product of this vector and another.
		 * \param v The other vector used in calculating the dot product.
		 * \returns The dot product calculated from this vector and another.
		 */
		float dot(const Vector<T, Size>& v) const
		{
			float dot = 0.0f;
			for (unsigned int idx = 0; idx < Size; idx++)
				dot += components[idx] * v.components[idx];
			return dot;
		}

		/**
		 * \brief Calculates and returns a unit vector with the same direction as this vector, i.e: this vector's normal.
		 * \returns A unit vector with a magnitude of 1.
		 */
		Vector<T, Size> normal() const
		{
			return *this / magnitude();
		}

		/**
		 * \brief Normalises the vector so it has a magnitude of 1.
		 * \returns A reference to the now normalised vector.
		 */
		Vector<T, Size>& normalise()
		{
			return *this = normal();
		}

		/**
		 * \brief Limits the vector's magnitude.
		 * \details This will make the vector keep its direction but extend/shrink its magnitude.
		 * \param newMagnitude The vector's new magnitude
		 */
		Vector<T, Size>& limit(float newMagnitude)
		{
			float m = magnitude();
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] += components[idx] * newMagnitude / m;
			return *this;
		}

		/**
		 * \brief Accesses the vector's components using a given index.
		 * \param idx The specified index of the component to return.
		 * \warning This function performs no array-bounds checking. the passed index must be [0 .. Size - 1].
		 * \returns A modifiable reference to the component found at position idx.
		 */
		T& operator[](unsigned int idx)
		{
			return components[idx];
		}

		/**
		 * \brief Accesses the vector's components using a given index.
		 * \param idx The specified index of the component to return.
		 * \warning This function performs no array-bounds checking. the passed index must be [0 .. Size - 1].
		 * \returns A non-mutable reference to the component found at position idx.
		 */
		const T& operator[](unsigned int idx) const
		{
			return components[idx];
		}

		/**
		 * \brief Vector4 assignment operator overload.
		 * \param rhs The Vector4 from which to copy component values from.
		 */
		Vector<T, Size>& operator=(const Vector<T, Size>& rhs)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] = rhs.components[idx];
			return *this;
		}

		/**
		 * \brief Adds another vector to the vector.
		 * \details Addition is performed component-wise.
		 * \param rhs Another vector which will be added to the vector.
		 * \returns A reference to the vector.
		 */
		Vector<T, Size>& operator+=(const Vector<T, Size>& rhs)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] += rhs.components[idx];
			return *this;
		}

		/**
		 * \brief Subtracts another vector from the vector.
		 * \details Subtraction is performed component-wise.
		 * \param rhs Another vector which will be subtracted from the vector.
		 * \returns A reference to the vector.
		 */
		Vector<T, Size>& operator-=(const Vector<T, Size>& rhs)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] -= rhs.components[idx];
			return *this;
		}

		/**
		 * \brief Multiplies another vector with the vector.
		 * \details Multiplication is performed component-wise.
		 * \param rhs Another vector which will be multiplied with the vector.
		 * \returns A reference to the vector.
		 */
		Vector<T, Size>& operator*=(const Vector<T, Size>& rhs)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] *= rhs.components[idx];
			return *this;
		}

		/**
		 * \brief Divides the vector by another vector.
		 * \details Division is performed component-wise.
		 * \param rhs Another vector which the vector will be divided by.
		 * \returns A reference to the vector.
		 */
		Vector<T, Size>& operator/=(const Vector<T, Size>& rhs)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] /= rhs.components[idx];
			return *this;
		}

		/**
		 * \brief Multiplies the vector by a scalar value.
		 * \param s The value of which to multiply/scale the vector by.
		 * \returns A reference to the vector.
		 */
		Vector<T, Size>& operator*=(float s)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] *= s;
			return *this;
		}

		/**
		 * \brief Divides the vector by a scalar value.
		 * \param s The value of which to divide/scale the vector by.
		 * \returns A reference to the vector.
		 */
		Vector<T, Size>& operator/=(float s)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] /= s;
			return *this;
		}

		/**
		 * \brief Computes and returns the inverse of the vector, i.e: all components multiplied by -1.
		 * \returns A new vector which is the inverse of the vector.
		 */
		Vector<T, Size> operator-() const
		{
			return *this * -1.0f;
		}
	};

	/**
	 * \brief Calculates the addition of two vectors.
	 * \details Addition is performed component-wise.
	 * \param lhs The vector on the left-hand-side of the addition operand.
	 * \param rhs The vector on the right-hand-side of the addition operand.
	 * \returns A new vector which is the sum of the two given vectors.
	 */
	template<typename T, int Size>
	inline Vector<T, Size> operator+(Vector<T, Size> lhs, const Vector<T, Size>& rhs)
	{
		return lhs += rhs;
	}

	/**
	 * \brief Calculates the subtraction of two vectors.
	 * \details Subtraction is performed component-wise.
	 * \param lhs The vector on the left-hand-side of the subtraction operand.
	 * \param rhs The vector on the right-hand-side of the subtraction operand.
	 * \returns A new vector which is the product of the subtraction of the two given vectors.
	 */
	template<typename T, int Size>
	inline Vector<T, Size> operator-(Vector<T, Size> lhs, const Vector<T, Size>& rhs)
	{
		return lhs -= rhs;
	}

	/**
	 * \brief Calculates the multiplication of two vectors.
	 * \details Multiplication is performed component-wise.
	 * \param lhs The vector on the left-hand-side of the multiplication operand.
	 * \param rhs The vector on the right-hand-side of the multiplication operand.
	 * \returns A new vector which is the product of the two given vectors.
	 */
	template<typename T, int Size>
	inline Vector<T, Size> operator*(Vector<T, Size> lhs, const Vector<T, Size>& rhs)
	{
		return lhs *= rhs;
	}

	/**
	 * \brief Calculates the quotient of two vectors.
	 * \details Division is performed component-wise.
	 * \param lhs The vector on the left-hand-side of the division operand.
	 * \param rhs The vector on the right-hand-side of the division operand.
	 * \returns A new vector which is the quotient of the two given vectors.
	 */
	template<typename T, int Size>
	inline Vector<T, Size> operator/(Vector<T, Size> lhs, const Vector<T, Size>& rhs)
	{
		return lhs /= rhs;
	}

	/**
	 * \brief Multiplies/scales a vector by a scalar value.
	 * \param lhs The vector to be multiplied/scaled.
	 * \param s The value to multiply/scale the vector by.
	 * \returns The result of the multiplication of the vector and the scalar value.
	 */
	template<typename T, int Size>
	inline Vector<T, Size> operator*(Vector<T, Size> lhs, float s)
	{
		return lhs *= s;
	}

	/**
	 * \brief Divides/inversely scales a vector by a value.
	 * \param lhs The vector to be divided/inversely scaled.
	 * \param s The value to divide/inversely scale the vector by.
	 * \returns The result of the division of the vector and the scalar value.
	 */
	template<typename T, int Size>
	inline Vector<T, Size> operator/(Vector<T, Size> lhs, float s)
	{
		return lhs /= s;
	}

	/**
	 * \brief Multiplies/scales a vector by a scalar value.
	 * \param s The value to multiply/scale the vector by.
	 * \param lhs The vector to be multiplied/scaled.
	 * \returns The result of the multiplication of the vector and the scalar value.
	 */
	template<typename T, int Size>
	inline Vector<T, Size> operator*(float s, Vector<T, Size> rhs)
	{
		return rhs *= s;
	}

	/**
	 * \brief Divides/inversely scales a vector by a value.
	 * \param s The value to divide/inversely scale the vector by.
	 * \param lhs The vector to be divided/inversely scaled.
	 * \returns The result of the division of the vector and the scalar value.
	 */
	template<typename T, int Size>
	inline Vector<T, Size> operator/(float s, Vector<T, Size> rhs)
	{
		return rhs /= s;
	}

	/**
	 * \brief Compares two vectors.
	 * \details Comparisons are performed per-component.
	 * \param lhs The Vector to be compared to the second.
	 * \param lhs The Vector to be compared to the first.
	 * \returns True if the vectors are found to be equal.
	 */
	template<typename T, int Size>
	inline bool operator==(const Vector<T, Size>& lhs, const Vector<T, Size>& rhs)
	{
		for (unsigned int idx = 0; idx < Size; idx++)
			if (lhs.components[idx] != rhs.components[idx])
				return false;
		return true;
	}

	/**
	 * \brief Compares two vectors.
	 * \details Comparisons are performed per-component.
	 * \param lhs The Vector to be compared to the second.
	 * \param lhs The Vector to be compared to the first.
	 * \returns True if the vectors are not found to be equal.
	 */
	template<typename T, int Size>
	inline bool operator!=(const Vector<T, Size>& lhs, const Vector<T, Size>& rhs)
	{
		return !(lhs == rhs);
	}

}