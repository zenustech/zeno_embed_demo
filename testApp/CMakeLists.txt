
cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)
project(testApp)
add_definitions(-D__TBB_CPP20_COMPARISONS_PRESENT=0)  

# add cmake file
include (common)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive -fPIC -Wall -Wextra -Wno-unused-parameter -Wcast-align -Wformat=2 -Winit-self -Wmissing-include-dirs -Woverloaded-virtual -Wno-error=redundant-decls -march=native -fno-math-errno -Wno-unused-but-set-parameter")
find_package(TBB CONFIG REQUIRED COMPONENTS tbb tbbmalloc)
find_package(IlmBase REQUIRED COMPONENTS Half REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(OpenVDB REQUIRED)
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

add_executable(testApp testApp.cpp)

#simd compiler flags
if (WIN32)
else()
target_compile_options(testApp PRIVATE "-march=native")
endif()


target_include_directories(testApp PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_directories(testApp PUBLIC /usr/lib/x86_64-linux-gnu:/usr/local/lib)

target_link_libraries(testApp PRIVATE TBB::tbb TBB::tbbmalloc)

#disable default malloc options
if (WIN32)
  target_compile_options(testApp PRIVATE -DNOMINMAX)
endif()

#target_link_libraries(ZenEulerLib PRIVATE OpenVDB::openvdb )
#target_link_libraries(ZenEulerLib PRIVATE Eigen3::Eigen)


target_link_libraries(testApp PUBLIC zeno gmpm glut GL GLU X11 Xrandr Xi GL)
target_include_directories(testApp PRIVATE ../external/zeno/projects/oldzenbase/include)
target_include_directories(testApp PRIVATE ../external/zeno/projects/zenvdb/include)
target_include_directories(testApp PRIVATE ../external/zeno/projects/gmpm/include)
target_include_directories(testApp PRIVATE ../external/zeno/zeno/include)


