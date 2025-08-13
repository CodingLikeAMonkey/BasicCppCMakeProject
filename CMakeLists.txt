cmake_minimum_required(VERSION 3.15)
project(MyProject)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Static library
add_library(static_lib STATIC src/static_lib/static_lib.cpp)
target_include_directories(static_lib PUBLIC include)

# Add headers to VS project for static lib
target_sources(static_lib PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/static_lib.h>
)

# Shared library
add_library(dynamic_lib SHARED src/dynamic_lib/dynamic_lib.cpp)
target_include_directories(dynamic_lib PUBLIC include)
target_compile_definitions(dynamic_lib PRIVATE DYNAMIC_LIB_EXPORT)

# Add headers to VS project for dynamic lib
target_sources(dynamic_lib PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/dynamic_lib.h>
)

# Header-only library
add_library(header_only INTERFACE)
target_include_directories(header_only INTERFACE include)

# Add header-only files to VS project
target_sources(header_only INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/header_only/math_utils.h>
)

# Executable
add_executable(main_app app/main.cpp)
target_link_libraries(main_app static_lib dynamic_lib header_only)

# Add headers to executable's project if needed
target_sources(main_app PRIVATE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/static_lib.h>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/dynamic_lib.h>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/header_only/math_utils.h>
)

# Copy DLL to executable directory (Windows)
if(WIN32)
    add_custom_command(TARGET main_app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:dynamic_lib>
        $<TARGET_FILE_DIR:main_app>
    )
endif()