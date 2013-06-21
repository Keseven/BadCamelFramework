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

#include <OasisUID.h>

namespace Oasis
{	
	std::map<String, UInt16> UID::m_uids;

	UInt16 UID::getNext(void)
	{
		return getNext("__OASIS_UID__");
	}

	UInt16 UID::getNext(const String &name)
	{
		if (m_uids.find(name) == m_uids.end())
			m_uids[name] = 0;

		return ++m_uids[name];

	}
};