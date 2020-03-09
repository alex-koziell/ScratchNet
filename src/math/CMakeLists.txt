set(HEADER_LIST "${scratchnet_SOURCE_DIR}/include/math/linearalgebra.hpp"
                "${scratchnet_SOURCE_DIR}/include/math/matrix.hpp"
                "${scratchnet_SOURCE_DIR}/include/math/numerical.hpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(math_lib numerical.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(math_lib PUBLIC ${scratchnet_SOURCE_DIR}/include)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
