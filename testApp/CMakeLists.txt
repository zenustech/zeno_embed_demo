cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)
project(testApp)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_executable(testApp testApp.cpp)

target_include_directories(testApp PRIVATE .)

target_link_libraries(testApp PUBLIC glut GL GLU)
target_link_libraries(testApp PUBLIC zeno zeno_projects)
target_include_directories(testApp PRIVATE ../external/zeno/projects/oldzenbase/include)
target_include_directories(testApp PRIVATE ../external/zeno/projects/zenvdb/include)
set_property(TARGET testApp PROPERTY INTERPROCEDURAL_OPTIMIZATION FALSE)
