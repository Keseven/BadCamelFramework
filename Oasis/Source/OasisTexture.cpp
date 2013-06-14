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

#include <OasisException.h>
#include <OasisTexture.h>

#include <SFML/Graphics.hpp>

namespace Oasis
{
	Texture::Texture(void)
	{
		m_sfmlTexture = new sf::Texture;
	}

	bool Texture::loadFromFile(const String &fileName)
	{
		if (!m_sfmlTexture->loadFromFile(fileName))
			OASIS_EXCEPTION(Exception::ET_COULD_NOT_OPEN_FILE, "Texture::loadFromFile", "Unable to locate or load file " + fileName);

		return true;
	}

	const sf::Texture *Texture::getSfmlTexture(void) const
	{
		return m_sfmlTexture;
	}
};