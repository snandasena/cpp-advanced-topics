project(wasm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

#add_executable(asyncmain cpp/async_main.c)
#add_executable(asyncmain cpp/async_main.c)
add_executable(guessing_game cpp/guessing_game.cpp)
