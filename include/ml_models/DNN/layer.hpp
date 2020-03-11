#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include "neuron.hpp"
#include "parameters.hpp"
#include <vector>

using namespace std;

class Layer
{
    /*
    A vector of neurons, facilitating layer-wise operations on the network.
    */

    public:
        Layer(int numNeurons, Activation activationType);

        void setActivationType(Activation toType);      // Set the activation type of all neurons in the layer.
        void setInputAt(int neuronIndex, double input); // Set the value of the neuron at neuronIndex to the value specified by input.
        void setBiasAt (int neuronIndex, double bias);  // Sets bias of neuron at neuronIndex

        vector<double> getInputs()        const;   // Returns a vector of the neuron inputs for this layer.
        vector<double> getActivations()   const;   // Returns a vector of the neuron activations.
        vector<double> getDerivatives()   const;   // Returns a vector of the neuron derivatives.

        double getActivationAt(int neuronIndex) const; // Returns activation of neuron at neuronIndex in m_neurons.
        double getBiasAt(int neuronIndex) const;       // Returns the bias of the neuron at neuronIndex.

        int getSize() const { return m_numNeurons; }

    private:
        Activation m_activationType;
        int m_numNeurons;           // Number of neurons in the layer.
        vector<double> m_activationsVector;
        vector<Neuron> m_neurons;   // A vector holding the this layer's neurons.
};

#endif