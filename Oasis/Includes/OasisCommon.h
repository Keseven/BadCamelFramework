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

#include <deque>
#include <string>

#define OASIS_DELETE(variable)						if (variable) {delete variable; variable = NULL;}

namespace Oasis
{
	// 8 bit integer
	typedef signed char					Int8;
    typedef unsigned char				UInt8;

	// 16 bit integer
    typedef signed short				Int16;
    typedef unsigned short				UInt16;

	// 32 bit integer
    typedef signed int					Int32;
    typedef unsigned int				UInt32;

	// 64 bit integer
    #if OASIS_COMPILER == OASIS_COMPILER_MSVC
        typedef signed   __int64		Int64;
        typedef unsigned __int64		UInt64;
    #else
        typedef signed long long		Int64;
        typedef unsigned long long		UInt64;
    #endif

	typedef std::string String;
	
	class Animation;
	class Sprite;
	class SpriteManager;
	class Texture;	
};

namespace sf
{
	class RenderWindow;
	class Sprite;
	class Texture;
}

#endif // __OASISCOMMON_H__