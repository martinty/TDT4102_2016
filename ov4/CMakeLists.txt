cmake_minimum_required(VERSION 3.9)
project(ov4)

set(CMAKE_CXX_STANDARD 11)

add_executable(ov4 main.cpp utilities.cpp utilities.h tests.cpp tests.h mastermind.cpp mastermind.h)