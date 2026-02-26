cmake_minimum_required(VERSION 3.25)
project(binary_search_tree)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../lib)

add_library(bst src/bst.c)

add_executable(main src/main.c)
target_link_libraries(main PRIVATE bst)

add_compile_options(-Wall -Wextra -pedantic)