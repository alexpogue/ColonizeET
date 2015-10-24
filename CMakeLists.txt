cmake_minimum_required(VERSION 2.6)
project(ColonizeET)

# Find cmake modules like FindSDL2.cmake, etc
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ColonizeET_SOURCE_DIR}/cmake")

# Get SDL2 libs
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_subdirectory(src)
