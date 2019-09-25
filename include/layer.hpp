#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <vector>
#include "neuron.hpp"
#include "matrix.hpp"

using namespace std;

class Layer
{
/*
Class to hold a layer of neurons, allowing for layer-wise
operations on the network.
*/

    public:
        Layer(int numNeurons);

        void setInputAt(int neuronIndex, double input); // Set the value of the neuron at neuronIndex to the value specified by input.

        Matrix getInputs();        // NEEDS DESCRIPTION
        Matrix getActivations();   // ^
        Matrix getDerivatives();   // ^

    private:
        int m_numNeurons;           // Number of neurons in the layer.
        vector<Neuron> m_neurons;   // A vector holding the this layer's neurons.
};

#endif