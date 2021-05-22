project(threads)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -O3 -pedantic -Wall -Werror")

#add_executable(threadtest thread_test.cpp)
add_executable(hellothreads hello_threads.cpp)