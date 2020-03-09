set(HEADER_LIST "${scratchnet_SOURCE_DIR}/include/ml_models/DNN/layer.hpp"
                "${scratchnet_SOURCE_DIR}/include/ml_models/DNN/network.hpp"
                "${scratchnet_SOURCE_DIR}/include/ml_models/DNN/neuron.hpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(dnn_lib layer.cpp network.cpp neuron.cpp ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(dnn_lib PUBLIC ${scratchnet_SOURCE_DIR}/include)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
