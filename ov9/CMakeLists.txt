cmake_minimum_required(VERSION 3.9)
project(ov9)

set(CMAKE_CXX_STANDARD 11)


add_executable(ov9 main.cpp Minesweeper.cpp Minesweeper.h utilities.cpp utilities.h)


# Detect and add SFML
set(SOURCE_FILES main.cpp)
set(SFML_ROOT "D:\\Programmer\\SFML-2.4.2-windows-gcc-6.1.0-mingw-64-bit\\SFML-2.4.2")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()