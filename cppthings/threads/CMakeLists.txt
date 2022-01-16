project(llthreads)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -Wall -Werror")

#add_executable(demo src/main.cpp)
#add_executable(mtx src/mutual_exclusion.cpp)
#add_executable(recursivemtx src/recursive_mutex.cpp)
#add_executable(trylock src/try_lock.cpp)
#add_executable(shared_mutex src/shared_mutex.cpp)
#add_executable(deadlock  src/deadlock_demo.cpp)
#add_executable(abandoned_lock  src/abandoned_lock.cpp)
#add_executable(starvation_lock src/starvation_lock.cpp)
#add_executable(llivelock_demo src/llivelock_demo.cpp


#add_executable(helloworl_thred udemy/hello_world.cpp)
#add_executable(callable_objects udemy/callable_objects.cpp)
#add_executable(promises_future udemy/promises_futures.cpp)
#add_executable(package_task udemy/package_task.cpp)
#add_executable(conditionalvrs udemy/conditional_vars.cpp)
#add_executable(blocking_queue udemy/blocking_que.cpp)
add_executable(asyncdemos udemy/async_demos.cpp)
add_executable(deadlock bo_qian/dead_lock.cpp)
target_link_libraries(deadlock -pthread)
