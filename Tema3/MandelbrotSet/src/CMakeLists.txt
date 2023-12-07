cmake_minimum_required(VERSION 3.15)

project(MandelbrotSet VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(MandelbrotSet main.cpp)

find_package(glfw3 REQUIRED)
target_link_libraries(MandelbrotSet glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(MandelbrotSet OpenGL::GL)

target_include_directories(MandelbrotSet PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

