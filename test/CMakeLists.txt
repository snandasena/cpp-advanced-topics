project(testworks)

add_executable(logger src/logger_test.cpp)
target_link_libraries(logger -pthread)