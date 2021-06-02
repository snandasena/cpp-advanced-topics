project(websock)

add_executable(websock src/uwebsock.cpp)

target_link_libraries(websock z ssl uv uWS)