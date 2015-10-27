cmake_minimum_required(VERSION 2.6)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(ColonizeET Graphics.h Graphics.cpp main.cpp)

if(NOT USE_EMSCRIPTEN)
    target_link_libraries(ColonizeET ${SDL2_LIBRARY})
endif()
