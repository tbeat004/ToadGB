cmake_minimum_required(VERSION 3.21)
project(ToadGB LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ToadGB 
    src/main.cpp
    src/chip8.cpp
    )

find_package(raylib CONFIG REQUIRED)
target_link_libraries(ToadGB PRIVATE raylib)