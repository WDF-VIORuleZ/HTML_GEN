cmake_minimum_required(VERSION 3.9)
project(Console)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)

add_executable(Console main.cpp Application.cpp Application.hpp external.hpp)