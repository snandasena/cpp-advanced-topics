project(llthreads)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -O3 -pedantic -Wall -Werror")

#add_executable(demo src/main.cpp)
add_executable(mtx src/mutual_exclusion.cpp)