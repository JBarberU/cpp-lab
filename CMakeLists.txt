cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -std=c++14)

set(SRC
  src/main.cpp
)

add_executable(threads ${SRC})
target_link_libraries(threads pthread)
