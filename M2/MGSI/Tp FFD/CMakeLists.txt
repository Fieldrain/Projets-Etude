macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)

#Configuration du projet
project(FFD)
cmake_minimum_required(VERSION 2.8)
use_cxx11()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin/)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bibliotheques/include/)

if (UNIX)
    set(OPENGL_gl_LIBRARY /usr/lib/x86_64-linux-gnu/libGL.so)
    set(OPENGL_INCLUDE_DIR /usr/include)

    set(GLFW_LIBRARY /usr/lib/x86_64-linux-gnu/libglfw.so)
    set(GLEW_LIBRARY /usr/lib/x86_64-linux-gnu/libGLEW.so)

    set(ARMA_LIBRARY /usr/lib/libarmadillo.so)
    set(APACK_LIBRARY /usr/lib/liblapack.so)
    set(ABLAS_LIBRARY /usr/lib/libblas.so)
endif (UNIX)

if(WIN32)
    SET(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:\"MSVCRT\")

    set(GLFW_LIBRARY C:/LibExterne/lib/x64/glfw3.lib)
    set(GLEW_LIBRARY C:/LibExterne/lib/x64/glew32.lib)
    
    set(ARMA_LIBRARY C:/LibExterne/lib/x64/armadillo.lib)
    set(APACK_LIBRARY C:/LibExterne/lib/x64/lapack_win64_MT.lib)
    set(ABLAS_LIBRARY C:/LibExterne/lib/x64/blas_win64_MT.lib)
endif(WIN32)

find_package(OpenGL REQUIRED)

#Configuration de l'exécutable
file(GLOB_RECURSE headers src/*.h)
file(GLOB_RECURSE sources src/*.cpp)

include_directories(${INCLUDE_DIR})

add_executable(FFD ${headers} ${sources})

#Configuration de l'édition de liens
target_link_libraries(FFD ${OPENGL_LIBRARY} ${GLFW_LIBRARY} ${GLEW_LIBRARY} ${ARMA_LIBRARY} ${APACK_LIBRARY} ${ABLAS_LIBRARY})

