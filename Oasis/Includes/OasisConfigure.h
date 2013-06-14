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

#ifndef __OASISCONFIGURE_H__
#define __OASISCONFIGURE_H__

// Standard preprocessor error/warning output
#define OASIS_PRECOMPILER_ASSERT(constant, message)		static_assert(constant, "OASIS COMPILATION ERROR: " message);
#define OASIS_PRECOMPILER_ERROR(message)				OASIS_PRECOMPILER_ASSERT(0, message)

// 0. Input defines
// ----------------

// The following defines can be specified as part of the build to influence the configuration
// OASIS_BUILD_STATIC - Indicates whether the library will be statically linked
// OASIS_BUILD_NON_CLIENT - Indicates whether this build is for a client application

// 1. Platform and architecture
// ----------------------------
// Defines OASIS_PLATFORM and OASIS_ARCHITECTURE

// The supported platforms
#define OASIS_PLATFORM_WINDOWS					1

// The supported architectures
#define OASIS_ARCHITECTURE_32_BIT				1
#define OASIS_ARCHITECTURE_64_BIT				2

// Detect the current platform and architecture
#if defined(_WIN64)
#	define OASIS_PLATFORM OASIS_PLATFORM_WINDOWS
#	define OASIS_ARCHITECTURE OASIS_ARCHITECTURE_64_BIT
#elif defined(_WIN32)
#	define OASIS_PLATFORM OASIS_PLATFORM_WINDOWS
#   define OASIS_ARCHITECTURE OASIS_ARCHITECTURE_32_BIT
#else
	OASIS_PRECOMPILER_ERROR("Unsupported platform detected.")
#endif

// 2. Compiler and compiler version
// --------------------------------
// Defines OASIS_COMPILER and OASIS_COMPILER_VERSION

// The supported compilers
#define OASIS_COMPILER_MSVC						1

// Detect the compiler and version
#if defined(_MSC_VER)
#   define OASIS_COMPILER OASIS_COMPILER_MSVC
#   define OASIS_COMPILER_VERSION _MSC_VER
	OASIS_PRECOMPILER_ASSERT(_MSC_VER >= 1700, "Unsupported MSVC version detected.")
#else
	OASIS_PRECOMPILER_ERROR("Unsupported compiler detected.")
#endif

// 3. Import/export directives
// ---------------------------
// Defines OASIS_CLASS and OASIS_CLASS_PRIVATE

// Static builds do not need import/exports
#if defined(OASIS_BUILD_STATIC)
#	define OASIS_CLASS
#	define OASIS_CLASS_PRIVATE
#else
#	if OASIS_PLATFORM == OASIS_PLATFORM_WINDOWS
#		define OASIS_CLASS_PRIVATE
#   	if defined(OASIS_BUILD_NON_CLIENT)
#       	define OASIS_CLASS __declspec(dllexport)
#   	else        
#       	define OASIS_CLASS __declspec(dllimport)        
#   	endif   	
#	endif
#endif

// 4. Debug flags
// --------------
// Defines OASIS_DEBUG_MODE

#if defined(_DEBUG) || defined(DEBUG)
#   define OASIS_DEBUG_MODE 1
#else
#   define OASIS_DEBUG_MODE 0
#endif

// 5. Compiler configuration
// -------------------------
// Performs compiler specific configuration

#if OASIS_COMPILER == OASIS_COMPILER_MSVC
	// Disable: "<type> needs to have dll-interface to be used by clients'	
#	pragma warning(disable: 4251)
	// Disable: "non dll-interface class used as base for dll-interface class"
#	pragma warning(disable: 4275)
#endif

// 6. Ensure all defines have been set
// -----------------------------------
// This is to test that any changes above have not resulted in an unset define

#if !defined(OASIS_PLATFORM)
	OASIS_PRECOMPILER_ERROR("OASIS_PLATFORM has not been defined.")
#endif
#if !defined(OASIS_ARCHITECTURE)
	OASIS_PRECOMPILER_ERROR("OASIS_ARCHITECTURE has not been defined.")
#endif
#if !defined(OASIS_COMPILER)
	OASIS_PRECOMPILER_ERROR("OASIS_COMPILER has not been defined.")
#endif
#if !defined(OASIS_COMPILER_VERSION)
	OASIS_PRECOMPILER_ERROR("OASIS_COMPILER_VERSION has not been defined.")
#endif
#if !defined(OASIS_CLASS)
	OASIS_PRECOMPILER_ERROR("OASIS_CLASS has not been defined.")
#endif
#if !defined(OASIS_CLASS_PRIVATE)
	OASIS_PRECOMPILER_ERROR("OASIS_CLASS_PRIVATE has not been defined.")
#endif
#if !defined(OASIS_DEBUG_MODE)
	OASIS_PRECOMPILER_ERROR("OASIS_DEBUG_MODE has not been defined.")
#endif

#endif // __OASISCONFIGURE_H__