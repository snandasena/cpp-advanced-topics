project(cppthings)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")

#find_package(GTest CONFIG REQUIRED)
include_directories(../googletest/include)

#add_subdirectory(stl)

add_subdirectory(threads)
#add_executable(basicsyntacxs src/basic_syntaxs.cpp)
#add_executable(fileio src/file_io.cpp)
#add_executable(binaryfile src/binary_file.cpp)
#add_executable(unformatted_chars src/unformatted_chars.cpp)
#add_executable(app src/main.cpp)
#add_executable(map_filter_reduce src/map_filter_reduce.cpp)
#add_executable(operator_overloading src/operator_overloading.cpp)

#add_executable(uniqueptr1 smart-pointers/unique_pointers.cpp)

#add_executable(staticpoly src/static_polymorphism.cpp)
#add_executable(constructor src/constructor_things.cpp)
#add_executable(funcover src/func_overriding.cpp)
#add_executable(friendfunc src/freind_func.cpp)
#add_executable(friendfunc src/static_member.cpp)
#add_executable(exceptionhandling src/exception_handling.cpp)
#add_executable(rawpointers smart-pointers/raw_pointers.cpp)
#add_executable(unittestssample unittests/sample.cpp)
#target_link_libraries(unittestssample gtest gtest_main pthread)
add_executable(mocktests unittests/mock_test.cpp)
target_link_libraries(mocktests gtest gmock gtest_main pthread)
