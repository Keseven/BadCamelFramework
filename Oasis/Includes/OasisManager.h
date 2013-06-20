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

#ifndef __OASISMANAGER_H__
#define __OASISMANAGER_H__

#include <OasisCommon.h>

namespace Oasis
{
	template <class T>
	class Manager
    {
	public:
		virtual ~Manager(void) {}

	
	protected:
		std::deque<T> m_managedArray;

		Manager(void) {}		
	};
};

#endif // __OASISMANAGER_H__