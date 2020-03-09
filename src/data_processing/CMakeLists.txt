set(HEADER_LIST "${scratchnet_SOURCE_DIR}/include/data_processing/MNIST/common.hpp"
                "${scratchnet_SOURCE_DIR}/include/data_processing/MNIST/mnist_data_handler.hpp"
                "${scratchnet_SOURCE_DIR}/include/data_processing/MNIST/mnist_data.hpp"

                "${scratchnet_SOURCE_DIR}/include/data_processing/XOR/XOR_preprocessor.hpp"
                )

# Make an automatic library - will be static or dynamic based on user setting
add_library(data_processing_lib MNIST/common.cpp MNIST/mnist_data_handler.cpp MNIST/mnist_data.cpp XOR/XOR_preprocessor.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(data_processing_lib PUBLIC ${scratchnet_SOURCE_DIR}/include)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
