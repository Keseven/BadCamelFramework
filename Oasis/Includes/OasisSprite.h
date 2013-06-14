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

#ifndef __OASISSPRITE_H__
#define __OASISSPRITE_H__

#include <OasisCommon.h>

namespace Oasis
{
	class OASIS_CLASS Sprite
	{
	public:		
		enum MovementDirection
		{		
			MD_NONE,
			MD_UP,
			MD_UP_RIGHT,
			MD_RIGHT,
			MD_DOWN_RIGHT,
			MD_DOWN,
			MD_DOWN_LEFT,
			MD_LEFT,
			MD_UP_LEFT,

			MD_
		};

		Sprite(void);

		virtual ~Sprite(void) {}

		void setTexture(Texture *texture, const IntRectangle &rectangle = IntRectangle::ZERO) const;
		//void setMovementAnimation(MovementDirection direction, MovementAnimation *animation) const;

	protected:
		sf::Sprite *m_sfmlSprite;
		MovementDirection currentMovementDirection;
		std::vector<Animation*> m_movementAnimations;
	};
};

#endif // __OASISSPRITE_H__