project(openglworks)

#--- Find GLUT
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})


add_definitions(${GLUT_DEFINITIONS})
if (NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif (NOT GLUT_FOUND)


#--- Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if (NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif (NOT OPENGL_FOUND)


#
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

#--- GL includes
include_directories(
#        "/usr/include/GL"
        "${PROJECT_SOURCE_DIR}/include"
)

#add_executable(inidemo src/opengl_init.cpp)
#target_link_libraries(inidemo ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

#add_executable(opendotdemo src/opengl_dot_demo.cpp)
#target_link_libraries(opendotdemo ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

add_executable(triangle src/ogldev_util.cpp src/opengl_triangle.cpp )
target_link_libraries(triangle ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

