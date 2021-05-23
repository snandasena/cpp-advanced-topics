project(threads)

SET(CMAKE_CXX_FLAGS "-std=c++17 -pthread -O3 -pedantic -Wall -Werror")

#add_executable(threadtest thread_test.cpp)
#add_executable(hellothreads hello_threads.cpp)
#add_executable(quize_one quize_one.cpp)
#add_executable(thread_with_function_object thread_with_function_object.cpp)
#add_executable(pass_lambdas_to_threads pass_lambdas_to_threads.cpp)
add_executable(variadic_templates variadic_templates.cpp)