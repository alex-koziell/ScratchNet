#include "../include/network.hpp"

#include "../include/math/matrix.h"
#include "../include/math/linearalgebra.h"
#include "../include/preprocessing/preprocessor.hpp"

#include "./tests/test_linearalgebra.cpp"
#include "./tests/test_preprocessor.cpp"

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    /*
    TODO/RULES:
    - consts where possible and const qualified functions
    - function templates/functionals
    - prefer pass classes by reference whenever possible
    - Rule: Do not copy initialize your classes
    */

    /* Get training data */
    Preprocessor trainingClass = Preprocessor("./data/XOR_train.txt"); 
    const int inputLayerSize  = trainingClass.getInputSize();
    const int outputLayerSize = trainingClass.getOutputSize();
    vector<vector<vector<double>>> trainingData = trainingClass.getTrainingData();

    /* Initialize network, then train */
    vector<int> layerSizes {inputLayerSize, 4, outputLayerSize};
    Network neuralNetwork {Network(layerSizes)};
    neuralNetwork.train(trainingData);


    /* ---------------TESTS/DEBUG---------------*/

    /* Linear algebra tests */
    // test_matrixMultiplication();
    // test_matrixVectorMultiplication();
    // test_transposeMatrix();
    // test_hadamardProduct();

    /* Preprocessor test */
    // test_preprocessor();

    /*------------------------------------------*/

    return 0;
}
