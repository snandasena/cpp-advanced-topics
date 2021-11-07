project(asio-samples)

add_definitions(-std=c++2a)

include_directories(../asio/include)

add_executable(app src/main.cpp)
target_link_libraries(app -pthread)