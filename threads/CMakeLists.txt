project(Threads)

add_executable(${PROJECT_NAME} src/conditional_variables.cpp)
target_link_libraries(${PROJECT_NAME} -pthread)