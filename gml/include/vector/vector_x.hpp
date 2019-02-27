#pragma once

#include <cmath>

namespace gml
{
	template<typename T, unsigned int Size>
	struct Vector
	{
		T components[Size] = { 0 };

		float magSqr() const
		{
			float magSqr = 0.0f;
			for (unsigned int idx = 0; idx < Size; idx++)
				magSqr += components[idx] * components[idx];
			return magSqr;
		}

		float mag() const
		{
			return std::sqrt(magSqr());
		}

		float dot(const Vector<T, Size>& v) const
		{
			float dot = 0.0f;
			for (unsigned int idx = 0; idx < Size; idx++)
				dot += components[idx] * v.components[idx];
			return dot;
		}

		Vector<T, Size> normal() const
		{
			return *this / mag();
		}

		Vector<T, Size>& normalise()
		{
			return *this = normal();
		}

		Vector<T, Size>& limit(float magnitude)
		{
			float m = mag();
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] += components[idx] * magnitude / m;
			return *this;
		}

		T& operator[](unsigned int idx)
		{
			return components[idx];
		}

		const T& operator[](unsigned int idx) const
		{
			return components[idx];
		}

		Vector<T, Size>& operator=(const Vector<T, Size>& rhs)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] = rhs.components[idx];
			return *this;
		}

		Vector<T, Size>& operator+=(const Vector<T, Size>& rhs)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] += rhs.components[idx];
			return *this;
		}

		Vector<T, Size>& operator-=(const Vector<T, Size>& rhs)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] -= rhs.components[idx];
			return *this;
		}

		Vector<T, Size>& operator*=(const Vector<T, Size>& rhs)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] *= rhs.components[idx];
			return *this;
		}

		Vector<T, Size>& operator/=(const Vector<T, Size>& rhs)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] /= rhs.components[idx];
			return *this;
		}

		Vector<T, Size>& operator*=(float s)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] *= s;
			return *this;
		}

		Vector<T, Size>& operator/=(float s)
		{
			for (unsigned int idx = 0; idx < Size; idx++)
				components[idx] /= s;
			return *this;
		}

		Vector<T, Size> operator-() const
		{
			return *this * -1.0f;
		}
	};

	template<typename T, int Size>
	inline Vector<T, Size> operator+(Vector<T, Size> lhs, const Vector<T, Size>& rhs)
	{
		return lhs += rhs;
	}

	template<typename T, int Size>
	inline Vector<T, Size> operator-(Vector<T, Size> lhs, const Vector<T, Size>& rhs)
	{
		return lhs -= rhs;
	}

	template<typename T, int Size>
	inline Vector<T, Size> operator*(Vector<T, Size> lhs, const Vector<T, Size>& rhs)
	{
		return lhs *= rhs;
	}

	template<typename T, int Size>
	inline Vector<T, Size> operator/(Vector<T, Size> lhs, const Vector<T, Size>& rhs)
	{
		return lhs /= rhs;
	}

	template<typename T, int Size>
	inline Vector<T, Size> operator*(Vector<T, Size> lhs, float s)
	{
		return lhs *= s;
	}

	template<typename T, int Size>
	inline Vector<T, Size> operator/(Vector<T, Size> lhs, float s)
	{
		return lhs /= s;
	}

	template<typename T, int Size>
	inline Vector<T, Size> operator*(float s, Vector<T, Size> rhs)
	{
		return rhs *= s;
	}

	template<typename T, int Size>
	inline Vector<T, Size> operator/(float s, Vector<T, Size> rhs)
	{
		return rhs /= s;
	}

	template<typename T, int Size>
	inline bool operator==(const Vector<T, Size>& lhs, const Vector<T, Size>& rhs)
	{
		for (unsigned int idx = 0; idx < Size; idx++)
			if (lhs.components[idx] != rhs.components[idx])
				return false;
		return true;
	}

	template<typename T, int Size>
	inline bool operator!=(const Vector<T, Size>& lhs, const Vector<T, Size>& rhs)
	{
		return !(lhs == rhs);
	}

}