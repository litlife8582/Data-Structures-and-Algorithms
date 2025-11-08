cmake_minimum_required(VERSION 4.0)
project(Graph C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Graph
        GraphTraversal.c
        queue.c
        queue.h
)
