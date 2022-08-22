cmake_minimum_required(VERSION 3.10.2)
set(CMAKE_CXX_STANDARD 11)

project(fleet_manager VERSION 1.0)

add_executable(${PROJECT_NAME} main.cpp fleet_functions.cpp help_functions.cpp)
