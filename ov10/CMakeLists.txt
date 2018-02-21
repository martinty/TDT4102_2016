cmake_minimum_required(VERSION 3.9)
project(ov10)

set(CMAKE_CXX_STANDARD 11)

add_executable(ov10 main.cpp Image.cpp Image.h Matrix.cpp Matrix.h ImageIO.cpp Vector.cpp Vector.h Shape.cpp Shape.h)