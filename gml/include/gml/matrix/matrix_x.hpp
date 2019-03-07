/**
 * \file
 * \author \link https://georgemcdonagh.co.uk George McDonagh
 */

#pragma once

#include "../core.hpp"
#include "../vector/vector_x.hpp"

namespace gml
{
	/**
	 * \brief A struct templates for matrices of floating-point values.
	 * \details This struct is used to represent two-dimensional matrices of various sizes.
	 * \note All GML matrix data is stored in column-major order, i.e.: the contiguous memory of a matrix is stored column after column. You may often need a pointer to this data, the best way to get this is to simply use <code>&someMatrix[0][0];</code>. This provides a pointer to the matrix's first element.
	 */
	template<typename T, unsigned int Major, unsigned int Minor = Major>
	struct Matrix
	{
		using MatT = Matrix<T, Major, Minor>;
		using ColT = Vector<T, Minor>;
		using RowT = Vector<T, Major>;

		ColT columns[Major]; //!< The columns of the Matrix4

		/**
		 * \brief Default constructor. Elements of the Matrix are initialised to 0.0f by default.
		 */
		MatT() = default;

		/**
		 * \brief Constructs and returns a specific row of the Matrix.
		 * \param idx The index of the row to return.
		 * \returns A Vector comprised of the elements of the specified row.
		 * \warning This function performs no array-bounds checking. the passed index must be [0 .. Minor - 1] where Minor is the number of rows.
		 */
		RowT getRow(unsigned int idx) const
		{
			RowT v;
			for (unsigned int col = 0; col < Major; col++)
				v[col] = columns[col][idx];
			return v;
		}

		/**
		 * \brief Calculates and returns the transpose matrix of the Matrix.
		 * \details The transpose of a matrix is the same matrix but with elements of rows and columns switch around. In other words the matrix rows become the columns and the columns become the rows.
		 * \returns A Matrix that is the transpose of the original Matrix.
		 */
		MatT transpose() const
		{
			MatT m;
			for (unsigned int origCol = 0; origCol < Major; origCol++)
				for (unsigned int origRow = 0; origRow < Minor; origRow++)
					m[origRow][origCol] = columns[origCol][origRow];
			return m;
		}

		template<typename = typename std::enable_if<Major == Minor>::type>
		MatT minor()
		{
			if (Major == 1)
				return *this;

			MatT m;
			if (Major == 2)
			{
				m[0][0] = this->columns[1][1];
				m[0][1] = this->columns[1][0];
				m[1][0] = this->columns[0][1];
				m[1][1] = this->columns[0][0];
				return m;
			}

			for (unsigned int col = 0; col < Major; col++)
				for (unsigned int row = 0; row < Major; row++)
				{
					Matrix<T, Major - 1> subM;
					unsigned int subMCol = 0, subMRow = 0;
					for (unsigned int col2 = 0; col2 < Major; col2++)
					{
						if (col == col2)
							continue;
						subMRow = 0;
						for (unsigned int row2 = 0; row2 < Major; row2++)
						{
							if (row == row2)
								continue;
							subM[subMCol][subMRow] = this->columns[col2][row2];
							subMRow++;
						}
						subMCol++;
					}
					m[col][row] = subM.determinant();
				}
			return m;
		}

		template<typename = typename std::enable_if<Major == Minor>::type>
		MatT cofactor()
		{
			MatT m = minor();
			for (unsigned int col = 0; col < Major; col++)
				for (unsigned int row = 0; row < Major; row++)
					if ((col + row) % 2 != 0)
						m[col][row] *= -1.0f;
			return m;
		}

		template<typename = typename std::enable_if<Major == Minor>::type>
		MatT adjoint()
		{
			return cofactor().transpose();
		}

		/**
		 * \brief Calculates and returns the inverse matrix of the Matrix.
		 * \details In 3D graphics, the inverse of a matrix is useful to reverse the original matrix's transformation.
		 * \returns A Matrix that is the inverse of the original Matrix.
		 */
		template<typename = typename std::enable_if<Major == Minor>::type>
		MatT inverse()
		{
			return (1.0f / determinant()) * adjoint();
		}

		/**
		 * \brief Calculates and returns the determinant of the Matrix.
		 * \returns The determinant of the Matrix.
		 */
		template<typename = typename std::enable_if<Major == Minor>::type>
		float determinant() const
		{
			if (Major == 2)
				return((this->columns[0][0] * this->columns[1][1]) - (this->columns[1][0] * this->columns[0][1]));
			if (Major == 1)
				return this->columns[0][0];

			float d = 0.0f;
			int c, subi, subj, i, j;
			Matrix<T, (Major < 2) ? 1 : Major - 1> submat;
			for (c = 0; c < Major; c++)
			{
				subi = 0;
				for (i = 1; i < Major; i++)
				{
					subj = 0;
					for (j = 0; j < Major; j++)
					{
						if (j == c)
							continue;
						submat[subi][subj] = this->columns[i][j];
						subj++;
					}
					subi++;
				}
				d = d + (std::pow(-1, c) * this->columns[0][c] * submat.determinant());
			}
			return d;
		}

		/**
		 * \brief Accesses the columns of the Matrix using a given index.
		 * \param idx The specified index of the column to return.
		 * \returns A modifiable reference to the column found at the specified index.
		 * \warning This function performs no array-bounds checking. the passed index must be [0 .. Major - 1] where Major is the number of columns.
		 */
		ColT& operator[](unsigned int idx)
		{
			return columns[idx];
		}

		/**
		 * \brief Accesses the columns of the Matrix4 using a given index.
		 * \param idx The specified index of the column to return.
		 * \returns An immutable reference to the column found at the specified index.
		 * \warning This function performs no array-bounds checking. the passed index must be [0 .. Major - 1] where Major is the number of columns.
		 */
		const ColT& operator[](unsigned int idx) const
		{
			return columns[idx];
		}

		/**
		 * \brief Adds another Matrix4 to the Matrix.
		 * \details Addition is performed element-wise.
		 * \param rhs A Matrix that will be added to the Matrix on the left.
		 * \returns A modifiable reference to the Matrix4 after the addition.
		 */
		MatT& operator+=(const Matrix<T, Major, Minor>& rhs)
		{
			for (unsigned int idx = 0; idx < Major; idx++)
				columns[idx] += rhs.columns[idx];
			return *this;
		}

		/**
		 * \brief Subtracts another Matrix from the Matrix.
		 * \details Subtraction is performed element-wise.
		 * \param rhs A Matrix that will be subtracted away from the Matrix on the left.
		 * \returns A modifiable reference to the Matrix after the subtraction.
		 */
		MatT& operator-=(const Matrix<T, Major, Minor>& rhs)
		{
			for (unsigned int idx = 0; idx < Major; idx++)
				columns[idx] -= rhs.columns[idx];
			return *this;
		}

		/**
		 * \brief Multiplies the elements of the Matrix by a scalar value.
		 * \param s A scalar value to multiply each Matrix element by.
		 * \returns A modifiable reference to the Matrix after the multiplication.
		 */
		MatT& operator*=(float s)
		{
			for (unsigned int idx = 0; idx < Major; idx++)
				columns[idx] *= s;
			return *this;
		}

		/**
		 * \brief Divides the elements of the Matrix by a scalar value.
		 * \param s A scalar value to multiply each Matrix element by.
		 * \returns A modifiable reference to the Matrix after the division.
		 */
		MatT& operator/=(float s)
		{
			for (unsigned int idx = 0; idx < Major; idx++)
				columns[idx] /= s;
			return *this;
		}

		/**
		 * \brief Creates a copy of the Matrix with all components' signs flipped.
		 * \returns A Matrix with all components of the original Matrix multiplied by -1.0f.
		 */
		MatT operator-() const
		{
			return *this * -1.0f;
		}
	};

	/**
	 * \brief Adds together two matrices of the same dimensions.
	 * \details Addition is performed element-wise.
	 * \param lhs A Matrix that will be added to the Matrix4 on the right.
	 * \param rhs A Matrix that will be added to the Matrix4 on the left.
	 * \returns A Matrix that is the sum of the left and right Matrix operands.
	 */
	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator+(Matrix<T, Major, Minor> lhs, const Matrix<T, Major, Minor>& rhs)
	{
		return lhs += rhs;
	}

	/**
	 * \brief Subtracts one Matrix from another.
	 * \details Subtraction is performed element-wise.
	 * \param lhs A Matrix to be subtracted from.
	 * \param rhs A Matrix will subtracted from the left Matrix operand.
	 * \returns A Matrix that is the result of subtracting the right Matrix operand from the left Matrix operand.
	 */
	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator-(Matrix<T, Major, Minor> lhs, const Matrix<T, Major, Minor>& rhs)
	{
		return lhs -= rhs;
	}

	/**
	 * \brief Multiplies the elements of a Matrix by a scalar value.
	 * \param lhs A Matrix whose elements will be multiplied by the scalar value.
	 * \param s A scalar value to multiply each Matrix element by.
	 * \returns A Matrix which is the original Matrix with all of its elements multiplied.
	 */
	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator*(Matrix<T, Major, Minor> lhs, float s)
	{
		return lhs *= s;
	}

	/**
	 * \brief Multiplies the elements of a Matrix by a scalar value.
	 * \param s A scalar value to multiply each Matrix element by.
	 * \param rhs A Matrix whose elements will be multiplied by the scalar value.
	 * \returns A Matrix which is the original Matrix with all of its elements multiplied by the scalar value.
	 */
	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator*(float s, Matrix<T, Major, Minor> rhs)
	{
		return rhs *= s;
	}

	/**
	 * \brief Divides the elements of a Matrix by a scalar value.
	 * \param lhs A Matrix whose elements will be divided by the scalar value.
	 * \param s A scalar value to divide each Matrix element by.
	 * \returns A Matrix which is the original Matrix with all of its elements divided by the scalar value.
	 */
	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator/(Matrix<T, Major, Minor> lhs, float s)
	{
		return lhs /= s;
	}

	/**
	 * \brief Multiplies one Matrix by another.
	 * \details The resulting matrix is a matrix with the same number of columns as the right Matrix operand and the same number as rows as the left Matrix operand.
	 * \note In order for two matrices to be multiplied together, then the left Matrix operand must have the same number of columns as the right Matrix operand has rows.
	 * \param lhs The left Matrix operand.
	 * \param rhs The right Matrix operand.
	 * \returns A Matrix which is the product matrix of the left Matrix operand and the right Matrix operand.
	 */
	template<typename T, unsigned int RowsLHS, unsigned int N, unsigned int ColsRHS>
	inline Matrix<T, ColsRHS, RowsLHS> operator*(const Matrix<T, N, RowsLHS>& lhs, const Matrix<T, ColsRHS, N>& rhs)
	{
		Matrix<T, ColsRHS, RowsLHS> result;
		for (unsigned int col = 0; col < ColsRHS; col++)
			for (unsigned int row = 0; row < RowsLHS; row++)
				result[col][row] = lhs.getRow(row).dot(rhs.columns[col]);
		return result;
	}

	/**
	 * \brief Multiplies a Matrix with a Vector.
	 * \note In order for a Vector to be multiplied with a Matrix the Vector must have the same number of components as the Matrix has rows.
	 * \param lhs The left Matrix operand.
	 * \param rhs The right Vector operand.
	 * \returns A Vector which is the product of the Matrix and the original Vector.
	 */
	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Vector<T, Minor> operator*(const Matrix<T, Major, Minor>& lhs, const Vector<T, Minor>& rhs)
	{
		Vector<T, Minor> v;
		for (unsigned int idx = 0; idx < Minor; idx++)
			v[idx] = getRow(idx).dot(rhs);
	}

	/**
	 * \brief Checks the equivelance of two Matrix instances of the same type and size.
	 * \param lhs The left Matrix operand.
	 * \param rhs The right Matrix operand.
	 * \returns True if the elements of the two Matrix instances are equal.
	 */
	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline bool operator==(const Matrix<T, Major, Minor>& lhs, const Matrix<T, Major, Minor>& rhs)
	{
		for (unsigned int idx = 0; idx < Major; idx++)
			if (lhs[idx] != rhs[idx])
				return false;
		return true;
	}

	/**
	 * \brief Checks the not-equivelance of two Matrix instances of the same type and size.
	 * \param lhs The left Matrix operand.
	 * \param rhs The right Matrix operand.
	 * \returns True if any of the elements of the two Matrix instances are not equal.
	 */
	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline bool operator!=(const Matrix<T, Major, Minor>& lhs, const Matrix<T, Major, Minor>& rhs)
	{
		return !(lhs == rhs);
	}
}