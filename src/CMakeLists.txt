add_library(pointers)
target_sources(pointers
    PRIVATE pointers/pointers.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS pointers
        FILES
            pointers/pointers.hpp
)
add_library(sensor)
target_sources(sensor
    PRIVATE sensor/sensor.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS sensor
        FILES
            sensor/sensor.hpp
)
add_library(structs)
target_sources(structs
    PRIVATE structs/structs.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS structs
        FILES
            structs/structs.hpp
)
add_library(vector_utils)
target_sources(vector_utils
    PRIVATE vector_utils/vector_utils.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS vector_utils
        FILES
            vector_utils/vector_utils.hpp
)