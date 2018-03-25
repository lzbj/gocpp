cmake_minimum_required(VERSION 3.8)
project(cppgo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp currency.cpp currency.h)
add_executable(cppgo ${SOURCE_FILES})