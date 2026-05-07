cmake_minimum_required(VERSION 3.14)

project(Tutorial)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing() # CMake command to enable Ctest

add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(tests)