cmake_minimum_required(VERSION 3.10)
project(logger)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCE ${PROJECT_SOURCE_DIR}/src/Logger.cpp)

add_library(logger STATIC ${SOURCE})