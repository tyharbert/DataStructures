add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wno-write-strings")
cmake_minimum_required(VERSION 2.8.11 FATAL_ERROR)

#project declarations
project(test1 CXX)
project(test2 CXX)

include_directories(
	libraries
)

# test program executables
add_executable(test1 tests/test1.cpp)
add_executable(test2 tests/test2.cpp)
