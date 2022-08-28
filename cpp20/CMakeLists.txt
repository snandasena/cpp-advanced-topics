project(cpp20)

set(CMAKE_CXX_FLAGS "-fcoroutines")
set(HEADERS src/base.h)
#set(SOURCE  src/concepts_examples.cpp)
set(SOURCE  src/corutines.cpp)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})