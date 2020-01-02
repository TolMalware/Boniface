cmake_minimum_required(VERSION 3.15)
project(web_framework)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS  "-lfcgi")
add_definitions(${CMAKE_CXX_FLAGS})
add_executable(web_framework main.cpp)