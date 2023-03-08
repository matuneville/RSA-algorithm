cmake_minimum_required(VERSION 3.23)
project(RSA_algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(RSA_algorithm
        main.cpp)
add_executable(RSA_testing
        src/testing.cpp)
