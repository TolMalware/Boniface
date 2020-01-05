cmake_minimum_required(VERSION 3.15)
project(web_framework)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_FLAGS  "-lfcgi")
add_definitions(${CMAKE_CXX_FLAGS})
add_executable(web_framework main.cpp context/request/Request.cpp context/request/Request.h context/response/Response.cpp context/response/Response.h context/Context.cpp context/Context.h app/MiddlewareManager.cpp app/MiddlewareManager.h context/utils.hpp)