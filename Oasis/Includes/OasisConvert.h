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

#ifndef __OASISCONVERT_H__
#define __OASISCONVERT_H__

#include <OasisCommon.h>

#include <SFML/Graphics.hpp>

namespace Oasis
{
	class Convert
	{
	public: 	
		virtual ~Convert(void) {}

		template <typename T>
		static inline sf::Vector2<T> toSfmlVector2(const Vector2<T> &vector2)
		{
			return sf::Vector2<T>(vector2.x, vector2.y);
		}

		template <typename T>
		static inline Vector2<T> fromSfmlVector2(const sf::Vector2<T> &vector2)
		{
			return Vector2<T>(vector2.x, vector2.y);
		}

		template <typename T>
		static inline sf::Rect<T> toSfmlRectangle(const Rectangle<T> &rectangle)
		{
			return sf::Rect<T>(rectangle.left, rectangle.top, rectangle.width, rectangle.height);
		}

		template <typename T>
		static inline Rectangle<T> fromSfmlRectangle(const sf::Rect<T> &rectangle)
		{
			return Rectangle<T>(rectangle.left, rectangle.top, rectangle.width, rectangle.height);
		}

	protected:
		Convert(void) {}
	};
};

#endif // __OASISCONVERT_H__
