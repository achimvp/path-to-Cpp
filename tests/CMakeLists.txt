include(FetchContent)
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_library(test_utils)

target_sources(test_utils
    PRIVATE test_utils/test_utils.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS test_utils
        FILES
            test_utils/test_utils.hpp
)
target_link_libraries(test_utils PUBLIC vector_utils)

add_executable(array_tests array_tests.cpp)
target_link_libraries(array_tests PRIVATE test_utils GTest::gtest_main)

add_executable(heap_memory_tests heap_memory_tests.cpp)
target_link_libraries(heap_memory_tests PRIVATE test_utils GTest::gtest_main)

add_executable(pointer_tests pointer_tests.cpp)
target_link_libraries(pointer_tests PRIVATE pointers GTest::gtest_main)

add_executable(sensor_tests sensor_tests.cpp)
target_link_libraries(sensor_tests PRIVATE sensor GTest::gtest_main)

gtest_discover_tests(array_tests)
gtest_discover_tests(heap_memory_tests)
gtest_discover_tests(pointer_tests)
gtest_discover_tests(sensor_tests)