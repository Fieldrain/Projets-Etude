project(Robot)
cmake_minimum_required(VERSION 2.8)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/)

if (UNIX)
    set(OPENGL_gl_LIBRARY /usr/lib/i386-linux-gnu/libGL.so)
    set(OPENGL_INCLUDE_DIR /usr/include)
endif (UNIX)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

#Configuration de l'exécutable
file(GLOB_RECURSE headers src/*.h)
file(GLOB_RECURSE sources src/*.cpp)

include_directories(${INCLUDE_DIR})

add_executable(Robot ${headers} ${sources})

#Configuration de l'édition de liens
target_link_libraries(Robot ${OPENGL_LIBRARY} ${GLUT_LIBRARIES})