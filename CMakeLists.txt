cmake_minimum_required (VERSION 3.0)

project (scratchnet VERSION 2.0
                    DESCRIPTION "Machine learning 'from scratch' in C++"
                    LANGUAGES CXX)

set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -DEUCLIDEAN")

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
    
    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDE's
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)
endif()

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(apps)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(tests)
endif()

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