cmake_minimum_required(VERSION 3.6)
project(wumpus)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

add_subdirectory(test)
