cmake_minimum_required(VERSION 2.8.4)

# Project configuration

project(GE)

set(GE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(GE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(GE_BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(GE_VERSION_MAJOR 0)
set(GE_VERSION_MINOR 0)

# Windows configuration

if(MSVC)

#	 Library directory

	if(CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(GE_WIN_LIBRARIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/x86)
	else(CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(GE_WIN_LIBRARIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64)
	endif(CMAKE_SIZEOF_VOID_P EQUAL 4)

#	SDL2
	
	set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2)
	set(SDL2_LIBRARIES ${GE_WIN_LIBRARIES_DIR}/SDL2.lib)

#	GL
	find_package(OPENGL REQUIRED)
	if(NOT OPENGL_FOUND)
		message(ERROR " OPENGL not found!")
	endif(NOT OPENGL_FOUND)

#	GLEW

	set(GLEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/glew)
	set(GLEW_LIBRARIES ${GE_WIN_LIBRARIES_DIR}/glew32.lib)

endif(MSVC)

# Cygwin configuration

if(CYGWIN)

#	Library directory

	if(CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(GE_WIN_LIBRARIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/i686)
	else(CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(GE_WIN_LIBRARIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/x86_64)
	endif(CMAKE_SIZEOF_VOID_P EQUAL 4)

#	SDL2

	set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2)
	set(SDL2_LIBRARIES ${GE_WIN_LIBRARIES_DIR}/libSDL2.dll.a)

#	GL
	set(OPENGL_LIBRARIES /lib/w32api/libopengl32.a)

#	GLEW

	set(GLEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/glew)
	set(GLEW_LIBRARIES ${GE_WIN_LIBRARIES_DIR}/libglew32.dll.a)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwin32")

endif(CYGWIN)

# MinGW configuration

if(MINGW)
	
#	Library directory

	if(CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(GE_WIN_LIBRARIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/i686)
	else(CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(GE_WIN_LIBRARIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/x86_64)
	endif(CMAKE_SIZEOF_VOID_P EQUAL 4)

	message(${GE_WIN_LIBRARIES_DIR})
	
#	SDL2

	set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2)
	set(SDL2_LIBRARIES ${GE_WIN_LIBRARIES_DIR}/libSDL2.dll.a)

#	GL
	if(EXISTS "/MinGW/lib/libopengl32.a")
		set(OPENGL_LIBRARIES /MinGW/lib/libopengl32.a)
	else(EXISTS "/MinGW/lib/libopengl32.a")
		set(OPENGL_LIBRARIES ${ROOT}/tools/mingw64/x86_64-w64-mingw32/lib/libopengl32.a)
	endif(EXISTS "/MinGW/lib/libopengl32.a")

#	GLEW

	set(GLEW_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/glew)
	set(GLEW_LIBRARIES ${GE_WIN_LIBRARIES_DIR}/libglew32.dll.a)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwin32")
	
endif(MINGW)

# Linux configuration

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

#	SDL2

	set(SDL2_SEARCH_PATHS
		/usr/local
		/usr
	)
	
	find_path(SDL2_INCLUDE_DIR SDL.h
		PATH_SUFFIXES include/SDL2 include
		PATHS ${SDL2_SEARCH_PATHS}
	)
	
	find_library(SDL2_LIBRARIES_TEMP
		NAMES SDL2
		PATH_SUFFIXES lib64 lib
		PATHS ${SDL2_SEARCH_PATHS}
	)
	
	set(SDL2_LIBRARIES ${SDL2_LIBRARIES_TEMP})

#	GL

	find_package(OpenGL REQUIRED)
	if(NOT OPENGL_FOUND)
		message(ERROR " OPENGL not found!")
	endif(NOT OPENGL_FOUND)
	
#	GLEW
	
	find_package(GLEW REQUIRED)
	if(NOT GLEW_FOUND)
		message(ERROR " GLEW not found!")
	endif(NOT GLEW_FOUND)
	set(GLEW_INCLUDE_DIR ${GLEW_INCLUDE_DIRS}/GL)

endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# OSX configuration

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

#	SDL2

	set(SDL2_SEARCH_PATHS
		/usr/local
		/usr
		/Library/Frameworks
	)
	
	find_path(SDL2_INCLUDE_DIR SDL.h
		PATH_SUFFIXES include/SDL2 include
		PATHS ${SDL2_SEARCH_PATHS}
	)
	
	find_library(SDL2_LIBRARIES_TEMP
		NAMES SDL2
		PATH_SUFFIXES lib64 lib
		PATHS ${SDL2_SEARCH_PATHS}
	)
	
	set(SDL2_LIBRARIES ${SDL2_LIBRARIES_TEMP})

#	GL

	find_package(OpenGL REQUIRED)
	if(NOT OPENGL_FOUND)
		message(ERROR " OPENGL not found!")
	endif(NOT OPENGL_FOUND)
	
#	GLEW
	
	find_package(GLEW REQUIRED)
	if(NOT GLEW_FOUND)
		message(ERROR " GLEW not found!")
	endif(NOT GLEW_FOUND)
	set(GLEW_INCLUDE_DIR ${GLEW_INCLUDE_DIRS}/GL)

endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

# Target configuration

function(PREPEND var prefix)
	set(listVar "")
	foreach(f ${ARGN})
		list(APPEND listVar "${prefix}/${f}")
	endforeach(f)
	set(${var} "${listVar}" PARENT_SCOPE)
endfunction(PREPEND)

PREPEND(GE_HEADERS ${GE_INCLUDE_DIR}
# Assert
	geassert.h

# Math
	math/vec2.h

# Containers
	containers/array.h

# Types
	types.h
)

PREPEND(GE_SOURCE ${GE_SOURCE_DIR}
# Math
	math/vec2.cpp

#Containers
	containers/array.cpp

# Main
	main.cpp
)

add_executable(GE ${GE_SOURCE} ${GE_HEADERS})
include_directories(GE ${GE_INCLUDE_DIR})
set_target_properties(GE PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${GE_BIN_DIR})

# Source configuration

configure_file("${GE_INCLUDE_DIR}/config.h.in" "${GE_INCLUDE_DIR}/config.h")

# SDL2 configuration

include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(GE ${SDL2_LIBRARIES})

# GL configuration

include_directories(GE ${OPENGL_INCLUDE_DIR})
target_link_libraries(GE ${OPENGL_LIBRARIES})

# GLEW configuration

include_directories(GE ${GLEW_INCLUDE_DIR})
target_link_libraries(GE ${GLEW_LIBRARIES})

# Post-build configuration

if(MSVC OR CYGWIN OR MINGW)
	add_custom_command(TARGET GE POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			"${GE_WIN_LIBRARIES_DIR}/SDL2.dll"
			$<TARGET_FILE_DIR:GE>
	)
	add_custom_command(TARGET GE POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			"${GE_WIN_LIBRARIES_DIR}/glew32.dll"
			$<TARGET_FILE_DIR:GE>
	)
endif(MSVC OR CYGWIN OR MINGW)
