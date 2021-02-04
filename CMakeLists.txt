cmake_minimum_required(VERSION 3.15)

project(flow_example LANGUAGES CXX VERSION 0.0.1)

find_package(flow REQUIRED)

add_executable(example example.cpp)
target_link_libraries(example PRIVATE flow)
