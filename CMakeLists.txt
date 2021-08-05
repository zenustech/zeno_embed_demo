cmake_minimum_required(VERSION 3.10)
project(zeno_addon_wizard LANGUAGES C CXX)

# Enable C++17 support
set(CMAKE_CXX_STANDARD 17)

# Import ZENO
add_subdirectory(external/zeno)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/external/zeno/zeno/cmake ${CMAKE_MODULE_PATH})

# Add your project
add_subdirectory(YourProject)
