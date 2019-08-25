#include <iostream>
#include <iomanip>
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"
#include "../include/network.hpp"

using namespace std;

int main() {
    vector<int> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(3);

    vector<double> input;
    input.push_back(1.0);
    input.push_back(0.0);
    input.push_back(1.0);

    cout << "//--------------------------------//" << endl;
    cout << "\t CREATING NEW NETWORK..." << endl;
    cout << "//--------------------------------//" << endl << endl;

    Network *neuralNetwork = new Network(topology);

    cout << "NUMBER OF LAYERS: " << topology.size() << endl;
    cout << "NUMBER OF INPUT NEURONS: " << topology.at(0) << endl << endl;
    neuralNetwork->setInput(input);

    neuralNetwork->printToConsole();


    return 0;
}
