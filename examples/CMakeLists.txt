add_executable(arrays)
target_sources(arrays
    PUBLIC
        arrays.cpp
)
target_link_libraries(arrays
    PRIVATE
        vector_utils
)

add_executable(heap_memory)
target_sources(heap_memory
    PUBLIC
        heap_memory.cpp
)
target_link_libraries(heap_memory
    PRIVATE
        vector_utils
)
target_compile_options(heap_memory PRIVATE -fsanitize=address)
target_link_options(heap_memory PRIVATE -fsanitize=address)
