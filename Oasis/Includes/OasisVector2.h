/*
This file is part of Oasis (part of the Bad Camel Gaming toolset).

Oasis is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Oasis is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Oasis.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __OASISVECTOR2_H__
#define __OASISVECTOR2_H__

#include <OasisCommon.h>

namespace Oasis
{
	template <typename T>
	class Vector2
	{
	public :		
		T x;
		T y;

		inline Vector2() : x(0), y(0) {}    
		inline Vector2(T X, T Y) : x(X), y(Y) {}

		template <typename U>
		inline explicit Vector2(const Vector2<U>& vector) : x(static_cast<T>(vector.x)), y(static_cast<T>(vector.y)) {}

		virtual inline ~Vector2(void) {}	

		operator sf::Vector2<T>(void) const;
	};
	
	typedef Vector2<int>				Vector2i;
	typedef Vector2<unsigned int>		Vector2u;
	typedef Vector2<float>				Vector2f;
		
	template <typename T>
	inline Vector2<T> operator -(const Vector2<T> &right)
	{
		return Vector2<T>(-right.x, -right.y);
	}

	template <typename T>
	inline Vector2<T> &operator +=(Vector2<T> &left, const Vector2<T> &right)
	{
		left.x += right.x;
		left.y += right.y;

		return left;
	}

	template <typename T>
	inline Vector2<T> &operator -=(Vector2<T> &left, const Vector2<T> &right)
	{
		left.x -= right.x;
		left.y -= right.y;

		return left;
	}

	template <typename T>
	inline Vector2<T> operator +(const Vector2<T> &left, const Vector2<T> &right)
	{
		return Vector2<T>(left.x + right.x, left.y + right.y);
	}

	template <typename T>
	inline Vector2<T> operator -(const Vector2<T> &left, const Vector2<T> &right)
	{
		return Vector2<T>(left.x - right.x, left.y - right.y);
	}

	template <typename T>
	inline Vector2<T> operator *(const Vector2<T> &left, T right)
	{
		return Vector2<T>(left.x * right, left.y * right);
	}

	template <typename T>
	inline Vector2<T> operator *(T left, const Vector2<T> &right)
	{
		return Vector2<T>(right.x * left, right.y * left);
	}

	template <typename T>
	inline Vector2<T> &operator *=(Vector2<T> &left, T right)
	{
		left.x *= right;
		left.y *= right;

		return left;
	}

	template <typename T>
	inline Vector2<T> operator /(const Vector2<T> &left, T right)
	{
		return Vector2<T>(left.x / right, left.y / right);
	}

	template <typename T>
	inline Vector2<T> &operator /=(Vector2<T> &left, T right)
	{
		left.x /= right;
		left.y /= right;

		return left;
	}

	template <typename T>
	inline bool operator ==(const Vector2<T> &left, const Vector2<T> &right)
	{
		return (left.x == right.x) && (left.y == right.y);
	}

	template <typename T>
	inline bool operator !=(const Vector2<T> &left, const Vector2<T> &right)
	{
		return (left.x != right.x) || (left.y != right.y);
	}
};


#endif // __OASISVECTOR2_H__
