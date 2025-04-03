cmake_minimum_required(VERSION 3.26)
project(algohw2)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(algohw2
        include/item.h
        include/methods.h
        src/main.cpp
        src/metrics.cpp
        src/sort.cpp
        src/utilities.cpp)
