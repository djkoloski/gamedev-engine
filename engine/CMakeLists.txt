cmake_minimum_required(VERSION 3.5)

# Project configuration

project(GE)

set(GE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(GE_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/x86)
else(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(GE_LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/x64)
endif(CMAKE_SIZEOF_VOID_P EQUAL 4)

set(GE_VERSION_MAJOR 0)
set(GE_VERSION_MINOR 0)

# Target configuration

add_executable(GE ${GE_SOURCE_DIR}/main.cpp)
set_target_properties(GE PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

# Source configuration

configure_file("${GE_SOURCE_DIR}/config.h.in" "${GE_SOURCE_DIR}/config.h")

# SDL2 configuration

set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl2)
include_directories(${SDL2_INCLUDE_DIR})
target_link_libraries(GE ${GE_LIBRARY_DIR}/SDL2.lib)
target_link_libraries(GE ${GE_LIBRARY_DIR}/SDL2main.lib)

# Post-build configuration

add_custom_command(TARGET GE POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
		"${GE_LIBRARY_DIR}/SDL2.dll"
		$<TARGET_FILE_DIR:GE>
)

message(${GE_SOURCE_DIR})
message(${GE_BINARY_DIR})
message(${GE_LIBRARY_DIR})
message(${SDL2_INCLUDE_DIR})
