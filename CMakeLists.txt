cmake_minimum_required(VERSION 3.10.0)
project(CS303_Assignment2 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)


set(SOURCES main.cpp
  SinglyList.h
  SinglyList.tpp
  Stack.h
  Stack.tpp)

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

