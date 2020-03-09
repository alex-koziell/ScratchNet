#include "ml_models/DNN/layer.hpp"

Layer::Layer(int numNeurons) {
    /*
    Initializes the layer with the appropriate number of neurons.
    Indices in the neuron vector start at 0, so we have neuron indices
    from 0 to numNeurons-1.
    */

    m_numNeurons = numNeurons;
    for (int neuronIndex=0; neuronIndex<numNeurons; ++neuronIndex)
    {
        // currently initializes layer with neuron inputs all 0.0 - to be researched
        m_neurons.push_back(Neuron(0.0));
    }
}

/*
TODO: create a more functional approach to retrieving and setting values;
currently Layer has wayyy to much repeated for loops in getInputs(), getActivations(), etc. 
*/


void Layer::setInputAt(int neuronIndex, double input)
{
    /*
    Sets the input of neuron at 'neuronIndex' in the neurons vector.
    */

    m_neurons.at(neuronIndex).setInput(input);
}

void Layer::setBiasAt(int neuronIndex, double bias)
{
    /*
    Sets the bias of neuron at neuronIndex in the layer.
    */

   m_neurons.at(neuronIndex).setBias(bias);
}

double Layer::getBiasAt(int neuronIndex) const
{
    return m_neurons.at(neuronIndex).getBias();
}

vector<double> Layer::getInputs() const {
    /*
    Returns the inputs of the neurons in the layer as a matrix object
    (rather than a vector: this allows us to use the matrix multiplication
    'function class').
    */

    vector<double> inputsVector;

    for (int neuronIndex=0; neuronIndex<m_numNeurons; ++neuronIndex)
    { // uses the getInput() accessor function of the neuron class to map the neurons' input values to inputsVector.
        inputsVector.push_back(m_neurons.at(neuronIndex).getInput());
    }

    return inputsVector;
}

vector<double> Layer::getActivations() const {
    /*
    Returns the activation of each neuron in the layer.
    */

    vector<double> activationVector;

    for (int neuronIndex=0; neuronIndex<m_numNeurons; ++neuronIndex)
    {   // uses accessor function of the neuron class similarly to Layer::getInputs()
        activationVector.push_back(m_neurons.at(neuronIndex).getActivation());
    }

    return activationVector;
}

vector<double> Layer::getDerivatives() const {
    /*
    Returns the derivative of the activation for each neuron in the layer.
    */

    vector<double> derivativesVector;

    for (int neuronIndex=0; neuronIndex<m_numNeurons; ++neuronIndex)
    {
        derivativesVector.push_back(m_neurons.at(neuronIndex).getDerivative());
    }

    return derivativesVector;  
}