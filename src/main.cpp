#include <iostream>
#include <iomanip>
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"
#include "../include/network.hpp"
#include "../include/utils/multiplymatrices.hpp"

using namespace std;

int main() {

    /* layerSizes: the number of neurons in each layer. */
    vector<int> layerSizes;
    layerSizes.push_back(3);
    layerSizes.push_back(2);
    layerSizes.push_back(3);

    /* input: the input values of the neurons in the input layer. */
    vector<double> input;
    input.push_back(1.0);
    input.push_back(0.0);
    input.push_back(1.0);

    cout << "//--------------------------------//" << endl;
    cout << "\tCREATING NEW NETWORK..." << endl;
    cout << "//--------------------------------//" << endl << endl;

    Network *neuralNetwork = new Network(layerSizes);

    cout << "NUMBER OF LAYERS: " << layerSizes.size() << endl << endl;
    cout << "NUMBER OF INPUT NEURONS (LAYER 0): " << layerSizes.at(0) << endl;
    for (int layerNum=1; layerNum<layerSizes.size()-1; ++layerNum)
    {
    cout << "LAYER " << layerNum << " SIZE:\t\t\t   " << layerSizes.at(layerNum) << endl;
    }
    cout << "NUMBER OF OUTPUT NEURONS:          " << layerSizes.back() << endl << endl;

    /* Set the input values of the network, then print to console. */
    neuralNetwork->setInput(input);
    // neuralNetwork->printToConsole(); // runs slow - need to work out why

    /* Matrix Multiplication Test */
    Matrix *A = new Matrix(1, 2, true);
    Matrix *B = new Matrix(2, 4, true);

    Matrix *C = (new utils::MultiplyMatrices(A, B))->execute();

    cout << endl;
    cout << "Matrix A:" << endl;
    A->printToConsole();
    cout << endl << "Matrix B:" << endl;
    B->printToConsole();
    cout << endl << "Matrix C = AB:" << endl;
    C->printToConsole();

    return 0;
}
