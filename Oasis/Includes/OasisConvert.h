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
#include <OasisRectangle.h>

#include <SFML/Graphics.hpp>

namespace Oasis
{
	class Convert
	{
	public: 
		template <typename T>
		static inline sf::Vector2<T> toSfmlVector2(const Vector2<T> &vector2)
		{
			return sf::Vector2<T>(vector2.x, vector2.y);
		} 

		template <typename T>
		static inline sf::Rect<T> toSfmlRectangle(const Rectangle<T> &rectangle)
		{
			return sf::Rect<T>(rectangle.left, rectangle.top, rectangle.width, rectangle.height);
		}
	};
};

#endif // __OASISCONVERT_H__
