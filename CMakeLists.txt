cmake_minimum_required(VERSION 3.10)
project(advanced_topics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)


add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")

#add_executable(advanced_topics main.cpp)
#add_executable(pointers pointers/pointers_01.cpp)
#add_executable(pointers pointers/pointers_02.cpp)
#add_executable(pointers pointers/pointers_03.cpp)
#add_executable(pointers pointers/pointers_as_function_arguments.cpp)
#add_executable(pointers pointers/pointers_and_arrays.cpp)
#add_executable(pointers pointers/arrays_as_function_arguments.cpp)
#add_executable(pointers pointers/charater_arrays_and_pointers.cpp)
#add_executable(pointers pointers/pointers_and_multidimentional_arrays.cpp)
#add_executable(pointers pointers/dyanamic_memory_allocation_cpp.cpp)
#add_executable(pointers pointers/dyanamic_memory_allocation_c_starndand_libs.cpp)
#add_executable(pointers pointers/pointers_as_function_returns.cpp)
#add_executable(pointers pointers/function_pointers.cpp)
#add_executable(pointers pointers/function_pointers_and_callbacks.cpp)

#add_executable(dsstructures ds/linked_list.cpp)
#add_executable(dsstructures ds/doubly_linked_list.cpp)
#add_executable(dsstructures ds/binary_search_tree.cpp)


#add_executable(header-files header-files/main.cpp header-files/PrintString.cpp header-files/PrintString.cpp)
#add_executable(header-files header-files/CarMain.cpp header-files/Car.cpp header-files/Car.h)
#add_executable(level-order ds/level_order_traversal.cpp)
#add_executable(path-planning path-planning/a_star.cpp)
#add_executable(idioms idioms/return_type_resolver.cpp)
#add_executable(idioms idioms/nullpointer.cpp)
#add_executable(idioms idioms/type_erasure.cpp)

#add_executable(ds ds/linkedlist.cpp)
#add_executable(ds ds/stack.cpp)
#add_executable(ds ds/statck_with_linkedlist.cpp)
#add_executable(ds ds/doublylinkedlist.cpp)
#add_executable(classes_and_objects classes_and_objects/friend_function.cpp)
#add_executable(ds ds/queue.cpp)
#add_executable(idioms idioms/static_polymorphism.cpp)

#add_executable(idioms idioms/type_erasure.cpp)
#add_executable(idioms idioms/type_erasyre_std_examples.cpp)
#add_executable(idioms idioms/std_any_implementation.cpp)
#add_executable(idioms idioms/CRTP.cpp)
#add_executable(idioms idioms/CRTP_continue.cpp)
#add_executable(idioms idioms/virtual_constructor.cpp)
#+++++++++++++++++++++++++++++++++++++++++++++++++++
#add_subdirectory(logger)
#include_directories(${PROJECT_SOURCE_DIR}/logger/include)
#
#add_executable(idioms idioms/PIMPL.cpp)
#target_link_libraries(idioms logger)
#+++++++++++++++++++++++++++++++++++++++++++++++++++

#+++++++++++++++++++++++++++++++++++++++++++++++++++
#add_subdirectory(fast_logger)
#include_directories(${PROJECT_SOURCE_DIR}/fast_logger/include)
#
#add_executable(idioms idioms/PIMPL_fast.cpp)
#target_link_libraries(idioms logger)

#+++++++++++++++++++++++++++++++++++++++++++++++++++


#add_executable(idioms idioms/SFINE.cpp)
#add_executable(idioms idioms/SFINE_continue.cpp)
#add_executable(idioms idioms/enableif.cpp)
#add_executable(idioms idioms/object_generator.cpp)
#add_executable(idioms idioms/RAII.cpp)
#add_executable(idioms idioms/ReferenceCounting.cpp)
#add_executable(idioms idioms/resource_return.cpp)
#add_executable(idioms idioms/SOO.cpp)
#add_executable(idioms idioms/EBO.cpp)

#add_executable(main main.cpp)

#add_executable(solid-srp SOLID/SRP/)

#add_executable(oop oop/main.cpp)

#add_executable(idioms idioms/EBO.cpp)

add_executable(c-pointers c-pointers/main.c)