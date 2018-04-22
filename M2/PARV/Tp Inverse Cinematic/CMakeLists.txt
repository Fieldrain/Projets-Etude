project(IK)
cmake_minimum_required(VERSION 2.8)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/include/)

if (UNIX)
    set(OPENGL_gl_LIBRARY /usr/lib/x86_64-linux-gnu/libGL.so)
    set(OPENGL_INCLUDE_DIR /usr/include)

    set(ARMA_LIBRARY /usr/lib/libarmadillo.so)
    set(APACK_LIBRARY /usr/lib/liblapack.so)
    set(ABLAS_LIBRARY /usr/lib/libblas.so)
endif (UNIX)

if(WIN32)
    set(GLUT_glut_LIBRARY C:/LibExterne/lib/x64/freeglut.lib)
    set(ARMA_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/lib/armadillo.lib)
    set(APACK_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/lib/lapack_win64_MT.lib)
    set(ABLAS_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/lib/blas_win64_MT.lib)
endif(WIN32)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

#Configuration de l'exécutable
file(GLOB_RECURSE headers src/*.h)
file(GLOB_RECURSE sources src/*.cpp)

include_directories(${INCLUDE_DIR})

add_executable(IK ${headers} ${sources})

#Configuration de l'édition de liens
target_link_libraries(IK ${OPENGL_LIBRARY} ${GLUT_glut_LIBRARY} ${ARMA_LIBRARY} ${APACK_LIBRARY} ${ABLAS_LIBRARY})