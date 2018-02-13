cmake_minimum_required(VERSION 3.9)
project(ov8)

set(CMAKE_CXX_STANDARD 11)

add_executable(ov8 main.cpp utilities.cpp utilities.h CourseCatalog.cpp CourseCatalog.h)