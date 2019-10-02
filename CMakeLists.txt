cmake_minimum_required(VERSION 3.15)
project(GNL C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(GNL
    get_next_line.h
    obrazec.c)
