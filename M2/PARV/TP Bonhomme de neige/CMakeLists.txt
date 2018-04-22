#Configuration du projet
project(TpNeige)
cmake_minimum_required(VERSION 2.8)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/include/)

if (UNIX)
    set(OPENGL_gl_LIBRARY /usr/lib/x86_64-linux-gnu/libGL.so)
    set(OPENGL_INCLUDE_DIR /usr/include)

    set(GLFW_LIBRARY /usr/lib/x86_64-linux-gnu/libglfw.so)
    set(GLEW_LIBRARY /usr/lib/x86_64-linux-gnu/libGLEW.so)
endif (UNIX)

if(WIN32)
    SET(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:\"MSVCRT\")
    set(GLFW_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/lib/glfw3.lib)
    set(GLEW_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/lib/glew32.lib)
endif(WIN32)

find_package(OpenGL REQUIRED)

#Configuration de l'exécutable
file(GLOB_RECURSE headers src/*.h)
file(GLOB_RECURSE sources src/*.cpp)

include_directories(${INCLUDE_DIR})

add_executable(TpNeige ${headers} ${sources})

#Configuration de l'édition de liens
target_link_libraries(TpNeige ${OPENGL_LIBRARY} ${GLFW_LIBRARY} ${GLEW_LIBRARY})

