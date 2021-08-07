cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(zeno_embed_demo LANGUAGES C CXX)

add_subdirectory(external/zeno)

add_subdirectory(testApp)
