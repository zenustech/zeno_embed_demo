cmake_minimum_required(VERSION 3.10)
project(zeno_addon_wizard LANGUAGES C CXX)

if (WIN32)
    # Windows should always use Release build to prevent possible traps
    set(CMAKE_BUILD_TYPE Release)
endif()

# Enable C++17 support
set(CMAKE_CXX_STANDARD 17)

# Ask PyZENO to link with your target
set(ZENO_ADDITIONAL_LINKS YourProject)

# Import ZENO
add_subdirectory(external/zeno)

# Add your project
add_subdirectory(YourProject)
