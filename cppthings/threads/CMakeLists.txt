project(llthreads)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -O3 -pedantic -Wall -Werror")

#add_executable(demo src/main.cpp)
#add_executable(mtx src/mutual_exclusion.cpp)
#add_executable(recursivemtx src/recursive_mutex.cpp)
#add_executable(trylock src/try_lock.cpp)
#add_executable(shared_mutex src/shared_mutex.cpp)
#add_executable(deadlock  src/deadlock_demo.cpp)
#add_executable(abandoned_lock  src/abandoned_lock.cpp)
#add_executable(starvation_lock src/starvation_lock.cpp)
add_executable(llivelock_demo src/llivelock_demo.cpp)