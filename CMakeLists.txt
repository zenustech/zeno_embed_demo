cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(zeno_embed_demo LANGUAGES C CXX)

#set(CMAKE_LINK_WHAT_YOU_USE TRUE)
set(ZENO_ENABLE_PYTHON OFF CACHE BOOL "For Embeding Usage")
set(ZENO_VISUALIZATION OFF CACHE BOOL "For Embeding Usage")
set(ZENO_GLOBALSTATE OFF CACHE BOOL "For Embeding Usage")
set(ZENO_FAULTHANDLER OFF CACHE BOOL "For Embeding Usage")
set(EXTENSION_gmpm ON CACHE BOOL "For Embeding Usage")
set(EXTENSION_mesher ON CACHE BOOL "For Embeding Usage")
add_subdirectory(external/zeno)

add_subdirectory(testApp)
