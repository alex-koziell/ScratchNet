add_executable(dnn dnn.cpp)

target_link_libraries(dnn PRIVATE dnn_lib)
target_link_libraries(dnn PRIVATE data_processing_lib)
target_link_libraries(dnn PRIVATE math_lib)