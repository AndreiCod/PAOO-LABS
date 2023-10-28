add_library(MyQueue STATIC MyQueue.cpp)

target_include_directories(MyQueue INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")