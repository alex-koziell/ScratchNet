cmake_minimum_required (VERSION 3.0)

project (scratchnet)

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DEUCLIDEAN")

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(apps)

# add_executable(
#     mnistTest

#     src/MNIST/mnist_data_handler.cpp
#     src/MNIST/mnist_data.cpp
#     src/MNIST/mnist_main.cpp
# )
# target_include_directories(
#     mnistTest PUBLIC
#     "${PROJECT_BINARY_DIR}/include"
# )

# add_executable(
#     scratchnet
    
#     src/main.cpp
#     src/neuron.cpp
#     src/layer.cpp
#     src/network.cpp

#     src/math/numerical.cpp
    
#     src/preprocessing/preprocessor.cpp
#     src/common.cpp
#     src/MNIST/mnist_data_handler.cpp
#     src/MNIST/mnist_data.cpp
# )
# target_include_directories(
#     scratchnet PUBLIC
#     "${PROJECT_BINARY_DIR}/include"
# )

# add_executable(
#     knn

#     src/common.cpp
#     src/MNIST/mnist_data_handler.cpp
#     src/MNIST/mnist_data.cpp
#     src/KNN/knn.cpp
#     src/KNN/knn_main.cpp
# )
# target_include_directories(
#     knn PUBLIC
#     "${PROJECT_BINARY_DIR}/include"
# )

# add_executable(
#     kmeans

#     src/common.cpp
#     src/MNIST/mnist_data_handler.cpp
#     src/MNIST/mnist_data.cpp
#     src/KMeans/kmeans.cpp
#     src/KMeans/kmeans_main.cpp
# )
# target_include_directories(
#     kmeans PUBLIC
#     "${PROJECT_BINARY_DIR}/include"
# )