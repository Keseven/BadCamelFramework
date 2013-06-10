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

#ifndef __OASISCOMMON_H__
#define __OASISCOMMON_H__

#include <OasisConfigure.h>

// Custom types
#include <OasisVector2.h>

// Standard containers
#include <string>
#include <vector>

namespace Oasis
{
	// 8 bit integer
	typedef signed char					int8;
    typedef unsigned char				uint8;

	// 16 bit integer
    typedef signed short				int16;
    typedef unsigned short				uint16;

	// 32 bit integer
    typedef signed int					int32;
    typedef unsigned int				uint32;

	// 64 bit integer
    #if OASIS_COMPILER == OASIS_COMPILER_MSVC
        typedef signed   __int64		int64;
        typedef unsigned __int64		uint64;
    #else
        typedef signed long long		int64;
        typedef unsigned long long		uint64;
    #endif

	// String typedefs
	typedef std::string string;
	
	// Define the most common Vector2 types
	typedef Vector2<int>				Vector2i;
	typedef Vector2<unsigned int>		Vector2u;
	typedef Vector2<float>				Vector2f;
};

// Forward declare SFML objects
namespace sf
{
	class RenderWindow;
}

#endif // __OASISCOMMON_H__