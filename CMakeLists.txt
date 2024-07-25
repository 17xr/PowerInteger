cmake_minimum_required(VERSION 3.28)
project(power_integer)

set(CMAKE_CXX_STANDARD 23)

link_libraries(gmp)

add_executable(power_integer main.cpp)