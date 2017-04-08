cmake_minimum_required(VERSION 3.3)
project(Tetromino-Solver)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

include_directories(include/)
file(GLOB SOURCES "src/*.cpp")

add_executable(tetro_solve ${SOURCES})
