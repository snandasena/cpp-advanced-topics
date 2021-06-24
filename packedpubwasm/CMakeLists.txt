project(packedpubwasm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(pong cpp/src/pong.cpp)