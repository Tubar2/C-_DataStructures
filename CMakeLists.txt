cmake_minimum_required(VERSION 3.17)
project(Arrays)

set(CMAKE_CXX_STANDARD 17)

add_executable(Arrays main.cpp MyArray/MyArray.hpp MyArray/MyArray.tpp)