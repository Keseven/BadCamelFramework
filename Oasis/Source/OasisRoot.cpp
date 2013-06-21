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

#include <OasisRoot.h>
#include <OasisSpriteManager.h>

#include <SFML/Graphics.hpp>

namespace Oasis
{	
	Root::Root(const IntVector2 &dimensions, const String &title)
	{
		m_sfmlWindow = new sf::RenderWindow(sf::VideoMode(dimensions.x, dimensions.y), title);

		m_spriteManager = new SpriteManager;
	}

	Root::~Root(void)
	{
		OASIS_DELETE(m_sfmlWindow);
		
		OASIS_DELETE(m_spriteManager);
	}
		
	void Root::Run(void)
	{
		while (m_sfmlWindow->isOpen())
		{
			sf::Event event;
			while (m_sfmlWindow->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_sfmlWindow->close();
			}

			m_sfmlWindow->clear();

			Sprite *sprite = m_spriteManager->getFirstItem();

			while (sprite)
			{
				m_sfmlWindow->draw(*sprite->getSfmlSprite());
				sprite = m_spriteManager->getNextItem();
			}

			m_sfmlWindow->display();
		}
	}

	SpriteManager *Root::getSpriteManager(void) const
	{
		return m_spriteManager;
	}
};