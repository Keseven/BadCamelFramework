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

#ifndef __OASISROOT_H__
#define __OASISROOT_H__

#include <OasisCommon.h>

namespace Oasis
{
	class OASIS_CLASS Root
	{
	public:		
		Root(const IntVector2 &dimensions, const String &title);
		virtual ~Root(void);

		void Run(void);

		SpriteManager *getSpriteManager(void) const;

	protected:
		sf::RenderWindow *m_sfmlWindow;
		
		SpriteManager *m_spriteManager;
	};
};

#endif // __OASISROOT_H__