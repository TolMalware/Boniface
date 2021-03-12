cmake_minimum_required(VERSION 3.15)
project(Boniface)
SET(CMAKE_CXX_FLAGS  "-lfcgi")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE SOURCES
        "src/*.h"
        "src/*.cpp"
        )
add_executable(Boniface examples/main.cpp ${SOURCES})
target_link_libraries(${PROJECT_NAME} fcgi)