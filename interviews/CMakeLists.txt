project(interviews)

set(CMAKE_CXX_FLAGS "-fsanitize=address -ggdb3 -Wall -Wextra")

add_executable(interviews src/main.cpp)
add_executable(sorting src/sorting.cpp)