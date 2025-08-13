cmake_minimum_required(VERSION 3.15)
project(MyProject)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Configuration for Windows DLL exports
add_compile_definitions(DYNAMIC_LIB_EXPORT)

# Static library
add_library(static_lib STATIC
    src/static_lib/static_lib.cpp
)
target_include_directories(static_lib PUBLIC include)

# Shared library
add_library(dynamic_lib SHARED
    src/dynamic_lib/dynamic_lib.cpp
)
target_include_directories(dynamic_lib PUBLIC include)
set_target_properties(dynamic_lib PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)  # Simplify Windows DLL

# Executable
add_executable(main_app app/main.cpp)
target_link_libraries(main_app static_lib dynamic_lib)