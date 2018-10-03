cmake_minimum_required(VERSION 2.8)

cmake_policy(SET CMP0015 NEW)

#Configuration du projet
project(TracerRayon)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(CMAKE_CXX_FLAGS "-std=gnu++14 ${CMAKE_CXX_FLAGS}")
#find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework)

#Configuration de l'exécutable
file(GLOB_RECURSE sources src/*.h src/*.cpp)
file(GLOB_RECURSE tests test/*.cpp)

#include_directories(${Boost_INCLUDE_DIR} ./include)
include_directories(./include)
add_executable(TracerRayon ${sources})

#Configuration de l'édition de liens
#target_link_libraries(TracerRayon GLU GL glut ${Boost_LIBRARIES})
target_link_libraries(TracerRayon GLU GL glut)

#enable_testing()
#add_executable(TestProjet ${tests})
#target_link_libraries(TestProjet GLU GL glut ${Boost_LIBRARIES})

#add_test(Test TestProjet)
