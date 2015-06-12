cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)

add_executable(threads src/threads.cpp)
target_link_libraries(threads pthread)
