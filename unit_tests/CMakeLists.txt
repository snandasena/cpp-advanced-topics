project(UnitTests)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest)
include_directories(${GTEST_INCLUDE_DIRS})

set(GMOCK_LIBRARIES /usr/lib/libgmock.a /usr/lib/libgmock_main.a)


add_executable(testRunner src/TestRunner.cpp src/IDatabaseConnection.cpp src/EmployeeManager.cpp)
target_link_libraries(testRunner ${GTEST_LIBRARIES} pthread)
