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
        void setBiasAt (int neuronIndex, double bias);  // Sets bias of neuron at neuronIndex

        vector<double> getInputs();        // NEEDS DESCRIPTION
        double getBiasAt(int neuronIndex);
        vector<double> getActivations();   // ^
        vector<double> getDerivatives();   // ^

        int getSize() { return m_numNeurons; }

    private:
        int m_numNeurons;           // Number of neurons in the layer.
        vector<Neuron> m_neurons;   // A vector holding the this layer's neurons.
};

#endif