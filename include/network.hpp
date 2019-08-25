#ifndef _NETWORK_HPP_
#define _NETWORK_HPP_

#include <vector>
#include "matrix.hpp"
#include "layer.hpp"

using namespace std;

class Network {
    public:
        Network(vector<int> topology);

        void printToConsole();
        void setInput(vector<double> input);
    
    private:
        vector<int> topology; // a vector of integers corresponding to the number of neurons in each layer
        int numLayers;
        vector<Layer *> layers; // vector of pointers to Layer objects
        vector<Matrix *> weightMatrices;
        vector<double> input;

};

#endif