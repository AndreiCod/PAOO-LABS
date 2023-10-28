cmake_minimum_required(VERSION 3.15)

project(MyLinkedList VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MyLinkedList main.cpp)

target_include_directories(MyLinkedList PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

