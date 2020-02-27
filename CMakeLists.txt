cmake_minimum_required (VERSION 3.0)

project (scratchnet)

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DEUCLIDEAN")

add_executable(
    scratchnet
    
    src/main.cpp
    src/neuron.cpp
    src/layer.cpp
    src/network.cpp

    src/math/numerical.cpp
    
    src/preprocessing/preprocessor.cpp
)

add_executable(
    knn

    src/MNIST/mnist_data_handler.cpp
    src/MNIST/mnist_data.cpp
    src/KNN/knn.cpp
)