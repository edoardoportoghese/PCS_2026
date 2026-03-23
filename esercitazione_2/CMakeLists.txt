cmake_minimum_required(VERSION 3.10)


project(esercitazione_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(es2_2 es2_2.cpp)
add_executable(Bubblesort Bubblesort.cpp)