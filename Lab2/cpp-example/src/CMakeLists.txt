cmake_minimum_required(VERSION 3.15)

project(HelloWorld VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(Primitives)

add_executable(HelloWorld main.cpp)

target_link_libraries(HelloWorld PUBLIC Primitives)

target_include_directories(HelloWorld PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

