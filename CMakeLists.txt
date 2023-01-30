cmake_minimum_required(VERSION 3.20)
project(Samples)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB_RECURSE SRC main.cpp cpp/*.cpp)

add_executable(${PROJECT_NAME} ${SRC})