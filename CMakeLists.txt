cmake_minimum_required(VERSION 3.29.6)
project(CS303_Assignment2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS)


set(SOURCES main.cpp
  SinglyList.h
  SinglyList.tpp
  Stack.h
  Stack.tpp)

add_executable(main ${SOURCES})

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

