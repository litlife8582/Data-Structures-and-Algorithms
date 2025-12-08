cmake_minimum_required(VERSION 4.0)
project(Sorting C)

set(CMAKE_C_STANDARD 11)

add_executable(Sorting
        CountSort.c
        InsertionSort.c
        MergeSort.c
        QuickSort.c
        SelectionSort.c)
