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

#include <OasisConvert.h>
#include <OasisSprite.h>
#include <OasisTexture.h>

#include <SFML/Graphics.hpp>

namespace Oasis
{	
	Sprite::~Sprite(void)
	{
		OASIS_DELETE(m_sfmlSprite);
	}
		
	void Sprite::reset(void)
	{
		if (m_sfmlSprite)
			if (m_sfmlSprite->getTexture())
				OASIS_DELETE(m_sfmlSprite);

		if (!m_sfmlSprite)
			m_sfmlSprite = new sf::Sprite;
	}

	void Sprite::setTexture(Texture *texture) const
	{		
		m_sfmlSprite->setTexture(*texture->getSfmlTexture());		
	}

	void Sprite::setTexture(Texture *texture, const IntRectangle &rectangle) const
	{
		setTexture(texture);
		m_sfmlSprite->setTextureRect(Convert::toSfmlRectangle(rectangle));
	}

	const FloatVector2 Sprite::getPosition(void)
	{
		return Convert::fromSfmlVector2(m_sfmlSprite->getPosition());
	}

	void Sprite::setPosition(const FloatVector2 &position) const
	{
		m_sfmlSprite->setPosition(Convert::toSfmlVector2(position));
	}

	void Sprite::move(UInt16 x, UInt16 y) const
	{
		move(FloatVector2(x, y));
	}

	void Sprite::move(const FloatVector2 &offset) const
	{
		m_sfmlSprite->move(Convert::toSfmlVector2(offset));
	}
	
	sf::Sprite *Sprite::getSfmlSprite(void) const
	{
		return m_sfmlSprite;
	}
};