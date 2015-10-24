cmake_minimum_required(VERSION 2.6)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB SOURCES "*.h" "*.cpp")

add_executable(ColonizeET ${SOURCES})
target_link_libraries(ColonizeET ${SDL2_LIBRARY})
