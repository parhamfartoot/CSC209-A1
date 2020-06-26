cmake_minimum_required(VERSION 3.15)
project(a1 C)

set(CMAKE_C_STANDARD 11)

add_executable(a1
        count_cells.c
        image.c)
