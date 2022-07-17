project(Threads)

#add_executable(${PROJECT_NAME} src/conditional_variables.cpp)
add_executable(${PROJECT_NAME} src/producer_consumer.cpp)
target_link_libraries(${PROJECT_NAME} -pthread)