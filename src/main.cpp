#include "../include/matrix.hpp"
#include "../include/neuron.hpp"
#include "../include/network.hpp"
#include "./tests/test_linearalgebra.cpp"
#include "../include/utils/linearalgebra.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    /*
    TODO:
    - consts where possible and const qualified functions
    - function templates/functionals
    - can we put foreach loops anywhere?
    - prefer pass by reference & for classes whenever possible
    - bias neurons
    - Rule: Do not copy initialize your classes
    */

    
    /* Linear algebra tests */
    // test_multiplyMatrices();
    // test_matrixVectorProduct();
    // test_transposeMatrix();
    // test_hadamardProduct();
    
    /* Initialize network */
    vector<int> layerSizes {3, 2, 1};   // layerSizes: the number of neurons in each layer.
    Network neuralNetwork = Network(layerSizes);    
    
    vector<double> input {1, 0, 1};     // input: the input values of the neurons in the input layer.
    neuralNetwork.setInput(input);
    neuralNetwork.printToConsole();

    /* Feedforward */
    neuralNetwork.feedForward();
    neuralNetwork.printToConsole();

    /* Backpropagate */
    vector<double> targetOutput { 100 };
    neuralNetwork.setTarget(targetOutput);
    neuralNetwork.backPropagate();

    /* Update weights */
    neuralNetwork.update();
    neuralNetwork.feedForward();
    neuralNetwork.printToConsole();

    return 0;
}
