cmake_minimum_required (VERSION 3.0)

project (scratchnet)

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(
    scratchnet
    src/scratchnet.cpp
)