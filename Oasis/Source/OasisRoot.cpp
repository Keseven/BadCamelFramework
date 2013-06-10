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
#include <OasisRoot.h>
#include <OasisWindow.h>

#include <SFML/System.hpp>

namespace Oasis
{
	Root::Root(uint16 width, uint16 height)
	{
		createWindow(Vector2u(width, height));
	}

	Root::Root(const Vector2u &dimensions)
	{
		createWindow(dimensions);
	}

	const Window *Root::getWindow(void) const
	{
		return m_window;
	}

	void Root::createWindow(const Vector2u &dimensions) const
	{

	}
};