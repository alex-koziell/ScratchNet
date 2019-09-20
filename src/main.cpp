#include <iostream>
#include <iomanip>
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"
#include "../include/network.hpp"

using namespace std;

int main() {

    /* topology: contains the number of neurons in each layer. */
    vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(3);

    /* input: the starting values of the input neurons. */
    vector<double> input;
    input.push_back(1.0);
    input.push_back(0.0);
    input.push_back(1.0);

    cout << "//--------------------------------//" << endl;
    cout << "\t CREATING NEW NETWORK..." << endl;
    cout << "//--------------------------------//" << endl << endl;

    Network *neuralNetwork = new Network(topology);

    cout << "NUMBER OF LAYERS: " << topology.size() << endl;
    cout << "NUMBER OF INPUT NEURONS: " << topology.at(0) << endl;
    cout << "NUMBER OF OUTPUT NEURONS: " << topology.back() << endl << endl;

    for (int layerNum=0; layerNum<topology.size(); layerNum++) {
        cout << "Layer " << layerNum << ':';
        cout << setw(15-topology.at(layerNum)*2.5);
        for (int neuronNum=0; neuronNum<topology.at(layerNum); neuronNum++) {
            cout << 'o' << setw(5) << ' ';
        }
        cout << endl;
    }
    cout << endl;


    neuralNetwork->setInput(input);

    neuralNetwork->printToConsole();


    return 0;
}
