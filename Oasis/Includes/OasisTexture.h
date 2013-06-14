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

#ifndef __OASISTEXTURE_H__
#define __OASISTEXTURE_H__

#include <OasisCommon.h>

namespace Oasis
{
	class OASIS_CLASS Texture
	{
		friend class Sprite;

	public:
		Texture(void);
		
		virtual ~Texture(void) {}

		bool loadFromFile(const String &fileName);

	protected:
		sf::Texture *m_sfmlTexture;

		const sf::Texture *getSfmlTexture(void) const;
	};
};

#endif // __OASISTEXTURE_H__