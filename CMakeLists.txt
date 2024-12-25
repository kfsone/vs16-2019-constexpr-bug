cmake_minimum_required (VERSION 3.17)

# This does not affect the result.
#set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project (repro CXX)


add_executable (repro repro.cpp)
