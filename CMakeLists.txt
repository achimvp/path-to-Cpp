cmake_minimum_required(VERSION 3.8)

project(Tutorial)

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
)