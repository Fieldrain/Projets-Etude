#Configuration du projet
project(MARCHING)
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
    set(ARMA_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/lib/armadillo.lib)
    set(APACK_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/lib/lapack_win64_MT.lib)
    set(ABLAS_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/lib/blas_win64_MT.lib)
endif(WIN32)

find_package(OpenGL REQUIRED)

#Configuration de l'exécutable
file(GLOB_RECURSE headers src/*.h)
file(GLOB_RECURSE sources src/*.cpp)

include_directories(${INCLUDE_DIR})

add_executable(MARCHING ${headers} ${sources})

#Configuration de l'édition de liens
target_link_libraries(MARCHING ${OPENGL_LIBRARY} ${GLFW_LIBRARY} ${GLEW_LIBRARY} ${ARMA_LIBRARY} ${APACK_LIBRARY} ${ABLAS_LIBRARY})

