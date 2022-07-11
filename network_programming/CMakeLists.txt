project(networks)

set(CMAKE_CXX_FLAGS "-std=c++17 -fsanitize=address -ggdb3 -Wall -Wextra -pedantic -Werror")

# TCP Works

#add_executable(get_host_details src/TCP/get_host_details.cpp)
#add_executable(get_local_network_details src/TCP/get_local_network_details.cpp)
#add_executable(get_interfaces_details src/TCP/get_intefaces_details.cpp)
#add_executable(get_address_info src/TCP/get_address_info.cpp)
#add_executable(socket01 src/TCP/socket01.cpp)
#add_executable(socket02 src/TCP/socket02.cpp)
#add_executable(socket_connect src/TCP/socket_connect.cpp)
#add_executable(socket_listen src/TCP/socket_listern.cpp)
#add_executable(server01 src/TCP/server01.cpp)
#add_executable(client01 src/TCP/client01.cpp)
#add_executable(dual_stack_server src/TCP/dual_stack_server.cpp)
#add_executable(generic_tcp_client src/TCP/generic_tcp_client.cpp)
#add_executable(generic_tcp_server src/TCP/generic_tcp_server.cpp)
#
#

# UDP Works
add_executable(udpserver01 src/UDP/udp_server.cpp)
add_executable(udpclient01 src/UDP/udp_client.cpp)