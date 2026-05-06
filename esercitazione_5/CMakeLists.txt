cmake_minimum_required(VERSION 3.20)

project(esercitazione5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(small_times
    small_times.cpp
    timecounter.cpp
)

add_executable(test_bubblesort
    test_bubblesort.cpp
)

add_test(NAME test_bubblesort COMMAND test_bubblesort)

add_executable(test_insertion
    test_insertion.cpp
)

add_test(NAME test_insertion COMMAND test_insertion)

add_executable(test_selection
    test_selection.cpp
)

add_test(NAME test_selection COMMAND test_selection)

add_executable(test_mergesort
    test_mergesort.cpp
)

add_test(NAME test_mergesort COMMAND test_mergesort)

add_executable(test_quicksort
    test_quicksort.cpp
)

add_test(NAME test_quicksort COMMAND test_quicksort)

enable_testing()