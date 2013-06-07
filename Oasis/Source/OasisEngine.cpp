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

#include <OasisCommon.h>
#include <OasisEngine.h>

#include <SFML/Graphics.hpp>

namespace Oasis
{
	Engine::Engine(void)
	{
		
	}

	Engine::Engine(std::string &workingDirectory)
	{
		SetWorkingDirectory(workingDirectory);
	}

	void Engine::SetWorkingDirectory(std::string &workingDirectory)
	{
		m_workingDirectory = workingDirectory;
	}

	void Engine::Start(void)
	{
		sf::RenderWindow window(sf::VideoMode(400, 400), "Demonstration");		
		
		sf::Texture texture;
		if (!texture.loadFromFile(m_workingDirectory + "HellowWorld.png"))
			return;

		sf::Sprite sprite;
		sprite.setTexture(texture);		

		sf::Event event;
		
		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(sprite);
			window.display();
		}
	}

	void Engine::Stop(void)
	{
	
	}
};