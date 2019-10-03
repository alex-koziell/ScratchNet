#include "../include/math/matrix.h"
#include "../include/math/linearalgebra.h"
#include "../include/neuron.hpp"
#include "../include/network.hpp"
// // #include "./tests/test_linearalgebra.cpp"
// #include "../include/utils/linearalgebra.hpp"
#include "../include/utils/preprocessor.hpp"
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
    - bias neurons
    - Rule: Do not copy initialize your classes
    */

    /* Get training data */
    // Preprocessor trainingClass = Preprocessor("./data/XOR_train.txt"); 
    // const int inputLayerSize  = trainingClass.getInputSize();
    // const int outputLayerSize = trainingClass.getOutputSize();
    // vector<vector<vector<double>>> trainingData = trainingClass.getTrainingData();

    // /* Initialize network, then train */
    // vector<int> layerSizes {inputLayerSize, 4, outputLayerSize};
    // Network neuralNetwork {Network(layerSizes)};
    // neuralNetwork.train(trainingData);


    /* ---------------TESTS/DEBUG---------------*/

    /* Linear algebra tests */
    // test_multiplyMatrices();
    // test_matrixVectorProduct();
    // test_transposeMatrix();
    // test_hadamardProduct();

    /* Preprocessor test */
    // test_preprocessor();

    /*------------------------------------------*/

    linalg::Matrix<double> A(3,3,true);
    A.print();

    linalg::Matrix<double> AT = A.transpose();
    AT.print();

    linalg::Matrix<double> AAT = A*AT;
    AAT.print();

    vector<double> v {1, 2, 3};
    vector<double> u {A*v};

    cout<<"Matrix A:"<<endl;
    A.print();
    cout<<"times vector v:"<<endl;
    linalg::print(v);
    cout<<"equals vector u:"<<endl;
    linalg::print(u);

    return 0;
}
