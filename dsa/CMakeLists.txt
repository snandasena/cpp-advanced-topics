project(dsa)

set(CMAKE_CXX_STANDARD 14)
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")


#add_executable(linkedlist src/linkedlist_app.cpp ${SOURCES})
#add_executable(queuedemo src/queue_app.cpp ${SOURCES})
#add_executable(treeapp src/trees_app.cpp ${SOURCES})
#add_executable(graphapp src/graph_app.cpp ${SOURCES})
#add_executable(dlist src/doubly_linkedlist.cpp ${SOURCES})
add_executable(stackapp src/stack.cpp ${SOURCES})