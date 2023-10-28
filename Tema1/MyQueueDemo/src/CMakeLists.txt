cmake_minimum_required(VERSION 3.15)

project(MyQueueDemo VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(MyQueue)

add_executable(MyQueueDemo main.cpp)

target_link_libraries(MyQueueDemo PUBLIC MyQueue)

target_include_directories(MyQueueDemo PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

