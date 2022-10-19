project(UnitTests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(testRunner src/TestRunner.cpp src/IDatabaseConnection.cpp src/EmployeeManager.cpp)

target_link_libraries(
        testRunner
        gtest
        gmock)
