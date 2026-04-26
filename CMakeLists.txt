cmake_minimum_required(VERSION 3.14)

project(Tutorial)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing() # CMake command to enable Ctest

add_executable(auto_keyword)

target_sources(auto_keyword
    PUBLIC
        auto_keyword.cpp
)

add_executable(structs)

target_sources(structs
    PUBLIC
        structs.cpp)

add_executable(arrays)

target_sources(arrays
    PUBLIC
        arrays.cpp
)

add_executable(array_tests)

target_sources(array_tests
    PUBLIC
        array_tests.cpp
)

add_library(test_utils)

target_sources(test_utils
    PRIVATE
        test_utils.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            test_utils.hpp
)

target_link_libraries(array_tests
    PRIVATE
        test_utils
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(array_tests)