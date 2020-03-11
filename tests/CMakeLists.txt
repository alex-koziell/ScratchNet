# Tests need to be added as executables first
add_executable(test_linearalgebra test_linearalgebra.cpp)
add_executable(test_XORpreprocessor test_XORpreprocessor.cpp)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(test_linearalgebra PRIVATE math_lib)
target_link_libraries(test_XORpreprocessor PRIVATE data_processing_lib)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME test_linearalgebra COMMAND test_linearalgebra) # Command can be a target
add_test(NAME test_XORpreprocessor COMMAND test_XORpreprocessor)