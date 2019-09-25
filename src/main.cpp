#include <iostream>
#include <iomanip>
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"
#include "../include/network.hpp"
#include "../include/utils/linearalgebra.hpp"

using namespace std;

int main() {
    /*
    TODO:
    - const
    - references
    - function templates/functionals
    - can we put foreach loops anywhere?
    - null pointer function argument checks
    - prefer pass by reference & for classes whenever possible
    - bias neurons
    - Rule: Do not copy initialize your classes
    - Recommendation: Do not add this-> to all uses of your class members. Only do so when you have a specific reason to. use m_ instead.
    */

    cout << "//--------------------------------//" << endl;
    cout << "\tCREATING NEW NETWORK..." << endl;
    cout << "//--------------------------------//" << endl << endl;

    /* layerSizes: the number of neurons in each layer. */
    vector<int> layerSizes {3, 2, 1};
    /* input: the input values of the neurons in the input layer. */
    vector<double> input {1, 1, 1};

    Network neuralNetwork = Network(layerSizes);

    cout << "NUMBER OF LAYERS: " << layerSizes.size() << endl << endl;
    cout << "NUMBER OF INPUT NEURONS (LAYER 0): " << layerSizes.at(0) << endl;
    for (int layerNum=1; layerNum<layerSizes.size()-1; ++layerNum)
    {
    cout << "LAYER " << layerNum << " SIZE:\t\t\t   " << layerSizes.at(layerNum) << endl;
    }
    cout << "NUMBER OF OUTPUT NEURONS:          " << layerSizes.back() << endl << endl;

    /* Set the input values of the network, then print to console. */
    neuralNetwork.setInput(input);
    neuralNetwork.printToConsole();

    /* Matrix Multiplication Test */
    Matrix A = Matrix(1, 2, true);
    Matrix B = Matrix(2, 4, true);

    Matrix C = linalg::multiplyMatrices(A, B);

    cout << endl;
    cout << "Matrix A:" << endl;
    A.printToConsole();
    cout << endl << "Matrix B:" << endl;
    B.printToConsole();
    cout << endl << "Matrix C = AB:" << endl;
    C.printToConsole();

    /* Test transpose */
    cout << endl << "D:" << endl;
    Matrix D = Matrix(3, 2, true);
    D.printToConsole();
    cout << endl << "D tranposed:";
    Matrix DT = D.transpose();
    DT.printToConsole();

    return 0;
}
