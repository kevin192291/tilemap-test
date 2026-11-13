cmake_minimum_required(VERSION 3.20)
project(tilemap LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# >>> Kev-C++ managed - edits inside this block are overwritten
find_package(SFML 3 REQUIRED COMPONENTS Graphics Audio Network Window System)

add_executable(tilemap)
target_sources(tilemap PRIVATE
    src/TileMap.hpp
    src/main.cpp
)
set_target_properties(tilemap PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
target_compile_options(tilemap PRIVATE
    -Wall
    -Wextra
    $<$<CONFIG:Debug>:-O0>
    $<$<CONFIG:Release>:-O2>
)
target_link_libraries(tilemap PRIVATE
    SFML::Graphics
    SFML::Audio
    SFML::Network
    SFML::Window
    SFML::System
)
# <<< Kev-C++ managed

# Your own CMake code goes below. Kev-C++ never edits anything outside the managed block.
