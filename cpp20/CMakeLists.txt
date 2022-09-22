project(cpp20)

find_package(Boost REQUIRED)

set(CMAKE_CXX_FLAGS "-fcoroutines")
set(HEADERS src/base.h)
#set(SOURCE  src/concepts_examples.cpp)
#set(SOURCE  src/corutines.cpp)
#set(SOURCE src/flyweight.cpp)
set(SOURCE src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})

#add_executable(templates src/function_template.cpp)
add_executable(unique_pointers src/unique_pointers.cpp)