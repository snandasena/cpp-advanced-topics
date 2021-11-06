project(lowlatency)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -Wall -Werror")

#add_executable(mainapp src/main.cpp)
#add_executable(lockfreequeue src/lock_free_queue.cpp)
#add_executable(blockingqueue src/blocking_queue.cpp)
#add_executable(shareddata src/shared_data.cpp)
#add_executable(promisenfuture src/promise_n_future.cpp)
add_executable(asynctask src/async_task.cpp)
