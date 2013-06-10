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

#ifndef __OASISSTRING_H__
#define __OASISSTRING_H__

#include <OasisCommon.h>

namespace Oasis
{
	class OASIS_CLASS String : basic_string<UInt32>
	{
	public:    
		typedef std::basic_string<UInt32>::iterator			Iterator;
		typedef std::basic_string<UInt32>::const_iterator	ConstIterator;

		static const std::size_t InvalidPosition;

		String(void) {}
		String(char ansiChar, const std::locale &locale = std::locale());
		String(wchar_t wideChar);
		String(UInt32 utf32Char);
		String(const char *ansiString, const std::locale &locale = std::locale());
		String(const std::string &ansiString, const std::locale &locale = std::locale());
		String(const wchar_t *wideString);
		String(const std::wstring &wideString);
		String(const UInt32 *utf32String);   
		String(const std::basic_string<UInt32> &utf32String);
		String(const String &copy);

		virtual ~String(void) {}

		operator std::string(void) const;
		operator std::wstring(void) const;
		operator sf::String(void) const;

		std::string toAnsiString(const std::locale &locale = std::locale()) const;
		std::wstring toWideString(void) const;

		String &operator =(const String &right);
		String &operator +=(const String &right);

		UInt32 operator [](std::size_t index) const;
		UInt32 &operator [](std::size_t index);

		void clear(void);
		std::size_t getSize(void) const;
		bool isEmpty(void) const;

		void erase(std::size_t position, std::size_t count = 1);
		void insert(std::size_t position, const String &string);
		std::size_t find(const String &string, std::size_t start = 0) const;

		const UInt32 *getData() const;

		Iterator begin(void);
		ConstIterator begin(void) const;

		Iterator end(void);
		ConstIterator end(void) const;

	private:
		std::basic_string<UInt32> m_string;
	};

	bool operator ==(const String &left, const String &right);
	bool operator !=(const String &left, const String &right);
	bool operator <(const String &left, const String &right);
	bool operator >(const String &left, const String &right);
	bool operator <=(const String &left, const String &right);
	bool operator >=(const String &left, const String &right);
	String operator +(const String &left, const String &right);
};

#endif // __OASISSTRING_H__

