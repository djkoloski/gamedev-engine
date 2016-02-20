cmake_minimum_required(VERSION 2.8.4)

# Project configuration

project(GE)

set(GE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(GE_VERSION_MAJOR 0)
set(GE_VERSION_MINOR 0)

# Windows configuration

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2)

	if(MSVC)
		if(CMAKE_SIZEOF_VOID_P EQUAL 4)
			set(GE_WIN_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/x86)
		else(CMAKE_SIZEOF_VOID_P EQUAL 4)
			set(GE_WIN_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64)
		endif(CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(SDL2_LIBRARY ${GE_WIN_LIBRARY_DIR}/SDL2.lib ${GE_WIN_LIBRARY_DIR}/SDL2main.lib)
	endif(MSVC)

	if(CYGWIN)
		if(CMAKE_SIZEOF_VOID_P EQUAL 4)
			set(GE_WIN_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/i686)
		else(CMAKE_SIZEOF_VOID_P EQUAL 4)
			set(GE_WIN_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/x86_64)
		endif(CMAKE_SIZEOF_VOID_P EQUAL 4)
		set(SDL2_LIBRARY ${GE_WIN_LIBRARY_DIR}/libSDL2.dll.a ${GE_WIN_LIBRARY_DIR}/libSDL2main.a)
	endif(CYGWIN)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# Linux configuration

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set(SDL2_SEARCH_PATHS
		/usr/local
		/usr
	)
	
	find_path(SDL2_INCLUDE_DIR SDL.h
		PATH_SUFFIXES include/SDL2 include
		PATHS ${SDL2_SEARCH_PATHS}
	)
	
	find_library(SDL2_LIBRARY_TEMP
		NAMES SDL2
		PATH_SUFFIXES lib64 lib
		PATHS ${SDL2_SEARCH_PATHS}
	)
	
	find_library(SLD2MAIN_LIBRARY_TEMP
		NAMES SDL2main
		PATH_SUFFIXES lib64 lib
		PATHS ${SDL2_SEARCH_PATHS}
	)
	
	set(SDL2_LIBRARY ${SDL2_LIBRARY_TEMP} ${SDL2MAIN_LIBRARY_TEMP})
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

# Target configuration

add_executable(GE ${GE_SOURCE_DIR}/main.cpp)
set_target_properties(GE PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Source configuration

configure_file("${GE_SOURCE_DIR}/config.h.in" "${GE_SOURCE_DIR}/config.h")

# SDL2 configuration

include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(GE ${SDL2_LIBRARY})

# Post-build configuration

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	add_custom_command(TARGET GE POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_if_different
			"${GE_LIBRARY_DIR}/SDL2.dll"
			$<TARGET_FILE_DIR:GE>
	)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")

message(${GE_SOURCE_DIR})
message(${GE_BINARY_DIR})
message(${SDL2_INCLUDE_DIR})
message(${SDL2_LIBRARY})
