project(ipc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

#add_executable(ipc src/ipc_leaning.c)
#add_executable(waitpid src/wait_pidtest.cpp)
add_executable(forkandwait src/fork_and_wait.c)