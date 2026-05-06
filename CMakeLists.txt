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

add_library(vector_utils)

target_sources(vector_utils
    PRIVATE
        vector_utils.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            vector_utils.hpp
)
target_link_libraries(arrays
    PRIVATE
        vector_utils
)

add_executable(pointers)

target_sources(pointers
    PUBLIC
        pointers_main.cpp
)

add_library(pointers_lib)

target_sources(pointers_lib
    PRIVATE
        pointers.cpp
    
    PUBLIC
        FILE_SET HEADERS
        FILES
            pointers.hpp
)

target_link_libraries(pointers
    PRIVATE
        pointers_lib
)

add_executable(heap_memory)

target_sources(heap_memory
    PUBLIC
        heap_memory.cpp
)

target_link_libraries(heap_memory
    PUBLIC
        vector_utils
)

add_executable(sensor_main)

target_sources(sensor_main
    PUBLIC
        sensor_main.cpp
)

add_library(sensor)

target_sources(sensor
    PRIVATE
        sensor.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES
            sensor.hpp
)

target_link_libraries(sensor_main
    PUBLIC
        sensor
)

#===== TESTS ======#
add_executable(array_tests)

target_sources(array_tests
    PUBLIC
        array_tests.cpp
)

add_executable(pointer_tests)

target_sources(pointer_tests
    PUBLIC
        pointer_tests.cpp
)

target_link_libraries(pointer_tests
    PRIVATE
        pointers_lib
        GTest::gtest_main
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

add_executable(heap_memory_tests)

target_sources(heap_memory_tests
    PRIVATE
        heap_memory_tests.cpp
)

target_link_libraries(heap_memory_tests
    PRIVATE
        vector_utils
        GTest::gtest_main
)

add_executable(sensor_tests)

target_sources(sensor_tests
    PRIVATE
        sensor_tests.cpp
)

target_link_libraries(sensor_tests
    PRIVATE
        sensor
        GTest::gtest_main
)

target_compile_options(heap_memory PRIVATE -fsanitize=address)
target_link_options(heap_memory PRIVATE -fsanitize=address)

include(GoogleTest)
gtest_discover_tests(array_tests)
gtest_discover_tests(pointer_tests)
gtest_discover_tests(heap_memory_tests)
gtest_discover_tests(sensor_tests)