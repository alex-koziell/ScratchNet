#ifndef _NETWORK_HPP_
#define _NETWORK_HPP_

#include <vector>
#include "matrix.hpp"
#include "layer.hpp"

using namespace std;

class Network {
    public:
        Network(vector<int> topology);

        /*
        Data Visualisation
        */
        void printToConsole();
        
        /*
        Parameter setting.
        */
        void setInput(vector<double> input);
        
        /*
        Learning functionality: feedforward, backpropagation
        */
       void feedForward();
       void backPropagate();
    
    private:
        vector<int> topology; // a vector of integers corresponding to the number of neurons in each layer
        int numLayers;
        vector<Layer *> layers; // vector of pointers to Layer objects
        vector<Matrix *> weightMatrices;
        vector<double> input;

};

#endif