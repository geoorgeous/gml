#pragma once

#include "../core.hpp"
#include "../vector/vector_x.hpp"

namespace gml
{
	template<typename T, unsigned int Major, unsigned int Minor>
	struct Matrix
	{
		Vector<T, Minor> columns[Major];

		Vector<T, Major> getRow(unsigned int idx) const
		{
			Vector<T, Major> v;
			for (unsigned int col = 0; col < Major; col++)
				v[idx] = columns[col][idx];
			return v;
		}

		Matrix<T, Minor, Major> transpose() const
		{
			Matrix<T, Minor, Major> m;
			for (unsigned int origCol = 0; origCol < Major; origCol++)
				for (unsigned int origRow = 0; origRow < Minor; origRow++)
					m[origRow][origCol] = columns[origCol][origRow];
			return m;
		}

		Vector<T, Minor>& operator[](unsigned int idx)
		{
			return columns[idx];
		}

		const Vector<T, Minor>& operator[](unsigned int idx) const
		{
			return columns[idx];
		}

		Matrix<T, Major, Minor>& operator+=(const Matrix<T, Major, Minor>& rhs)
		{
			for (int idx = 0; idx < Major; idx++)
				columns[idx] += rhs.columns[idx];
			return *this;
		}

		Matrix<T, Major, Minor>& operator-=(const Matrix<T, Major, Minor>& rhs)
		{
			for (int idx = 0; idx < Major; idx++)
				columns[idx] -= rhs.columns[idx];
			return *this;
		}

		Matrix<T, Major, Minor>& operator*=(float s)
		{
			for (int idx = 0; idx < Major; idx++)
				columns[idx] *= s;
			return *this;
		}

		Matrix<T, Major, Minor>& operator/=(float s)
		{
			for (int idx = 0; idx < Major; idx++)
				columns[idx] /= s;
			return *this;
		}

		Matrix<T, Major, Minor> operator-() const
		{
			return *this * -1.0f;
		}
	};

	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator+(Matrix<T, Major, Minor> lhs, const Matrix<T, Major, Minor>& rhs)
	{
		return lhs += rhs;
	}

	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator-(Matrix<T, Major, Minor> lhs, const Matrix<T, Major, Minor>& rhs)
	{
		return lhs -= rhs;
	}

	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator*(Matrix<T, Major, Minor> lhs, float s)
	{
		return lhs *= s;
	}

	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator*(float s, Matrix<T, Major, Minor> rhs)
	{
		return rhs *= s;
	}

	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator/(Matrix<T, Major, Minor> lhs, float s)
	{
		return lhs /= s;
	}

	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator*(const Matrix<T, Major, Minor>& lhs, const Matrix<T, Minor, Major>& rhs)
	{
		Matrix4 result;
		for (int col = 0; col < Major; col++)
			for (int row = 0; row < Minor; row++)
				result[col][row] = lhs.getRow(row).dot(rhs.columns[col]);
		return result;
	}

	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Matrix<T, Major, Minor> operator/(const Matrix<T, Major, Minor>& lhs, const Matrix<T, Major, Minor>& rhs)
	{
		return lhs * rhs.inverse();
	}

	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline Vector<T, Minor> operator*(const Matrix<T, Major, Minor>& lhs, const Vector<T, Minor>& rhs)
	{
		Vector<T, Minor> v;
		for (unsigned int idx = 0; idx < Minor; idx++)
			v[idx] = getRow(idx).dot(rhs);
	}

	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline bool operator==(const Matrix<T, Major, Minor>& lhs, const Matrix<T, Major, Minor>& rhs)
	{
		for (int idx = 0; idx < Major; idx++)
			if (lhs[idx] != rhs[idx])
				return false;
		return true;
	}

	template<typename T, unsigned int Major, unsigned int Minor = Major>
	inline bool operator!=(const Matrix<T, Major, Minor>& lhs, const Matrix<T, Major, Minor>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename T, unsigned int Rank>
	struct SqMatrix : public Matrix<T, Rank, Rank>
	{
		static const unsigned int rank = Rank;

		SqMatrix<T, Rank> inverse()
		{
			// todo
			SqMatrix<T, Rank> m;
			return m;
		}

		float determinant() const
		{
			if (Rank == 2)
				return((this->columns[0][0] * this->columns[1][1]) - (this->columns[1][0] * this->columns[0][1]));
			if (Rank == 1)
				return this->columns[0][0];

			float d = 0.0f;
			int c, subi, subj, i, j;
			SqMatrix<T, Rank - 1> submat;
			for (c = 0; c < 4; c++)
			{
				subi = 0;
				for (i = 1; i < 4; i++)
				{
					subj = 0;
					for (j = 0; j < 4; j++)
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
	};
}