project(lowlatency)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -Wall -Werror")

add_executable(lockfreequeue src/lock_free_queue.cpp)
add_executable(mainapp src/main.cpp)