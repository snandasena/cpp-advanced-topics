project(dsa)

set(CMAKE_CXX_STANDARD 14)
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")


add_executable(linkedlist src/main.cpp ${SOURCES})