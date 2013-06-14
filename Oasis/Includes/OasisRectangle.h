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

#ifndef __OASISRECTANGLE_H__
#define __OASISRECTANGLE_H__

#include <OasisCommon.h>

namespace Oasis
{
	template <typename T>
	class Rectangle
	{
	public:			
		T left;
		T top;
		T width;
		T height;
				
		inline Rectangle(void) : left(0), top(0), width(0), height(0) {}
		inline Rectangle(T rectangleLeft, T rectangleTop, T rectangleWidth, T rectangleHeight) : left(rectangleLeft), top(rectangleTop), width(rectanlgeWidth), height(rectangleHeight) {}
		inline Rectangle(const Vector2<T> &position, const Vector2<T> &size) : left(position.x), top(position.y), width(size.x), height(size.y) {}

		static const Rectangle ZERO = Rectangle();

		template <typename U>
		inline explicit Rectangle(const Rectangle<U> &rectangle) : left(static_cast<T>(rectangle.left)), top(static_cast<T>(rectangle.top)), width(static_cast<T>(rectangle.width)), height(static_cast<T>(rectangle.height)) {}

		virtual inline ~Rectangle(void) {}

		inline bool contains(T x, T y) const
		{
			return (x >= left) && (x < left + width) && (y >= top) && (y < top + height);
		}

		inline bool contains(const Vector2<T> &point) const
		{
			return contains(point.x, point.y);
		}

		inline bool intersects(const Rectangle<T> &rectangle) const
		{
			Rectangle<T> intersection;
			return intersects(rectangle, intersection);
		}

		inline bool intersects(const Rectangle<T> &rectangle, Rectangle<T> &intersection) const
		{
			T interLeft = std::max(left, rectangle.left);
			T interTop = std::max(top, rectangle.top);
			T interRight = std::min(left + width, rectangle.left + rectangle.width);
			T interBottom = std::min(top + height, rectangle.top + rectangle.height);

			if ((interLeft < interRight) && (interTop < interBottom))
			{
				intersection = Rectangle<T>(interLeft, interTop, interRight - interLeft, interBottom - interTop);
				return true;
			}
			else
			{
				intersection = Rectangle<T>(0, 0, 0, 0);
				return false;
			}
		}
	};

	typedef Rectangle<int>				IntRectangle;
	typedef Rectangle<float>			FloatRectangle;

	template <typename T>
	inline bool operator ==(const Rectangle<T> &left, const Rectangle<T> &right)
	{
		return (left.left == right.left) && (left.width == right.width) && (left.top == right.top) && (left.height == right.height);
	}

	template <typename T>
	inline bool operator !=(const Rectangle<T> &left, const Rectangle<T> &right)
	{
		return !(left == right);
	}
};

#endif // __OASISRECTANGLE_H__