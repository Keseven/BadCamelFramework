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
#include <OasisWindow.h>

#include <SFML/Graphics.hpp>

namespace Oasis
{
	Window::Window(UInt16 width, UInt16 height, const String &title)
	{
		initialise(Vector2u(width, height), title);
	}

	Window::Window(const Vector2u &dimensions, const String &title)
	{
		initialise(dimensions, title);
	}

	void Window::setSize(UInt16 width, UInt16 height) const
	{
		setSize(Vector2u(width, height));
	}

	void Window::setSize(const Vector2u &dimensions) const
	{
		m_sfmlWindow->setSize(Convert::toSFMLVector2(dimensions));
	}

	void Window::setTitle(const String &title) const
	{
		m_sfmlWindow->setTitle(title);
	}

	void Window::initialise(const Vector2u &dimensions, const String &title)
	{
		createSFMLWindow(dimensions, title);
	}

	void Window::createSFMLWindow(const Vector2u &dimensions, const String &title)
	{
		m_sfmlWindow = new sf::RenderWindow(sf::VideoMode(dimensions.x, dimensions.y), title); 
	}
};