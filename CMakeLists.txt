cmake_minimum_required(VERSION 2.6)
project(ColonizeET)

option(USE_EMSCRIPTEN "Set this true if deploying to JS with emscripten" OFF)

# Find cmake modules like FindSDL2.cmake, etc
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ColonizeET_SOURCE_DIR}/cmake")

if(USE_EMSCRIPTEN)
    # Emscripten only requires a compile flag to use SDL2
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s USE_SDL=2")
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_CXX_LINKER_FLAGS} -o ${CMAKE_PROJECT_NAME}.html")
else()
    # Get SDL2 libs
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIR})
endif()

add_subdirectory(src)
