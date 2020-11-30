cmake_minimum_required(VERSION 3.17)
project(huffcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(huffcode huffcode_test.cpp huffcode.cpp)