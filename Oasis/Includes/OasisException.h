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

#ifndef __OASISEXCEPTION_H__
#define __OASISEXCEPTION_H__

#include <OasisCommon.h>

namespace Oasis
{
	class OASIS_CLASS Exception
    {   
    public:      
        enum ExceptionType
		{
			ET_COULD_NOT_OPEN_FILE
        };

		Exception(ExceptionType type, const String &source, const String &description, const char *fileName, UInt32 lineNumber) : m_type(type), m_source(source), m_descrpition(description), m_fileName(fileName), m_lineNumber(lineNumber) {}
		virtual ~Exception() {}

		ExceptionType getType(void) const;
		const String &getSource(void) const;
		const String &getDescription(void) const;
		const String &getFileName(void) const;
		UInt32 getLineNumber(void) const;
       
	protected:
		ExceptionType m_type;
		String m_source;
		String m_descrpition;
		String m_fileName;
		UInt32 m_lineNumber;
    };
};

#define OASIS_EXCEPTION(type, source, description) throw Oasis::Exception(type, source, description, __FILE__, __LINE__);

#endif // __OASISEXCEPTION_H__