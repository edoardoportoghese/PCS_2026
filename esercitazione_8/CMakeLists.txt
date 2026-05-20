cmake_minimum_required(VERSION 3.10)

project(esercitazione8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Cerca Eigen installato nel sistema
find_package(Eigen3 REQUIRED)

# Eseguibile
add_executable(test_grad test_grad.cpp)

# Link/include di Eigen
target_link_libraries(test_grad Eigen3::Eigen)