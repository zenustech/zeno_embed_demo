cmake_minimum_required(VERSION 3.10)

# SHARED is required for ZENO libraries
add_library(YourProjectLib SHARED CustomNumber.cpp MyPrimitiveOps.cpp)

# Link the libzeno.so to invoke ZENO API
target_link_libraries(YourProjectLib PRIVATE zeno)

# To make ZENO automatic load your nodes,
# we need to output the .so file to the same
# directory where libzeno.so is. To do so:
get_property(OUTPUT_DIR TARGET zeno PROPERTY LIBRARY_OUTPUT_DIRECTORY)
# The OUTPUT_DIR should be ../external/zeno/zeno/lib,
# using get_property here to prevent hard-coded paths
set_target_properties(YourProjectLib PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}
    # the below 8 is required only for 'Microsoft Windows'
    RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}
    LIBRARY_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIR}
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIR}
)
