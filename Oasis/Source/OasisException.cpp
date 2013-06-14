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

namespace Oasis
{
	Exception::ExceptionType Exception::getType(void) const
	{
		return m_type;
	}

	const String &Exception::getSource(void) const
	{
		return m_source;
	}

	const String &Exception::getDescription(void) const
	{
		return m_descrpition;
	}

	const String &Exception::getFileName(void) const
	{
		return m_fileName;
	}

	UInt32 Exception::getLineNumber(void) const
	{
		return m_lineNumber;
	}
};