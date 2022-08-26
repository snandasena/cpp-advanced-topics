project(cpp20)

set(HEADERS src/base.h)
set(SOURCE  src/concepts_examples.cpp)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADERS})