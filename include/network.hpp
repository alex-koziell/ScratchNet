#ifndef _NETWORK_HPP_
#define _NETWORK_HPP_

#include <vector>
#include "matrix.hpp"
#include "layer.hpp"

using namespace std;

class Network {
    /*
    Class that embodies the whole network, given a vector 'layerSizes',
    whose length is the number of layers, and whose elements dictate the
    number of neurons in each layer.
    */

    public:
        Network(vector<int> layerSizes);

        void printToConsole(); // Displays the structure of the network in the console

        void setInput(vector<double> input); // Sets the activation values of the input neurons.
        
        void feedForward();      // Implements feed forward part of learning.
        void backPropagate();    // Implements back propagtion part of learning.
    
    private:
        vector<int> m_layerSizes;             // A vector of integers containing the number of neurons in each layer.
        int m_numLayers;                      // A separate variable equal to the length of layerSizes, for more concise code.
        vector<Layer> m_layers;               // A vector containing the actual layer objects of the network. 
        vector<Matrix> m_weightMatrices;      // A vector of weight matrices for the connections between adjacent layers.
        vector<double> m_input;               // Inputs of the network (the activations of the input neurons).

};

#endif