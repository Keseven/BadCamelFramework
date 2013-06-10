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

#ifndef __OASISWINDOW_H__
#define __OASISWINDOW_H__

namespace Oasis
{
	class OASIS_CLASS Window
	{
	public:
		Window(uint16 width, uint16 height, const string &title);
		Window(const Vector2u &dimensions, const string &title);

		void setSize(uint16 width, uint16 height) const;
		void setSize(const Vector2u &dimensions) const;

	protected:
		sf::RenderWindow *m_sfmlWindow;

		void createSFMLWindow(const Vector2u &dimensions, const string &title);
	};
};

#endif // __OASISWINDOW_H__