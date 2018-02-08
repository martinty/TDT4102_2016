cmake_minimum_required(VERSION 3.9)
project(ov7)

set(CMAKE_CXX_STANDARD 11)

add_executable(ov7 main.cpp utilities.cpp utilities.h Matrix.cpp Matrix.h)