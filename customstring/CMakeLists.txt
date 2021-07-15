project(customstring)

add_definitions(-std=c++17)
set(CXX_FLAGS "-Wall -O3")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(SOURCES src/utest.cpp src/ctstring.cpp)

add_executable(customstring ${SOURCES})