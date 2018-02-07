cmake_minimum_required(VERSION 3.9)
project(ov6)

set(CMAKE_CXX_STANDARD 11)

add_executable(ov6 main.cpp Matrix2x2.cpp Matrix2x2.h Vector2.cpp Vector2.h utilities.cpp utilities.h)