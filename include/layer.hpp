#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <vector>
#include "neuron.hpp"
#include "matrix.hpp"

using namespace std;

class Layer
{
    /*
    A vector of neurons, facilitating layer-wise operations on the network.
    */

    public:
        Layer(int numNeurons);

        void setInputAt(int neuronIndex, double input); // Set the value of the neuron at neuronIndex to the value specified by input.
        void setBiasAt (int neuronIndex, double bias);  // Sets bias of neuron at neuronIndex

        vector<double> getInputs()        const;   // Returns a vector of the neuron inputs for this layer.
        vector<double> getActivations()   const;   // Returns a vector of the neuron activations.
        vector<double> getDerivatives()   const;   // Returns a vector of the neuron derivatives.
        double getBiasAt(int neuronIndex) const;   // Returns the bias of the neuron at neuronIndex.

        int getSize() const { return m_numNeurons; }

    private:
        int m_numNeurons;           // Number of neurons in the layer.
        vector<Neuron> m_neurons;   // A vector holding the this layer's neurons.
};

#endif