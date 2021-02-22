cmake_minimum_required(VERSION 2.6)
project (hello)
set (cxx 11)
add_definitions(-DNDEBUG )
include_directories(include)
add_executable(hello main.cpp)

