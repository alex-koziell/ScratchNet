#include "ml_models/DNN/layer.hpp"
#include "ml_models/DNN/parameters.hpp"

Layer::Layer(int numNeurons, Activation activationType)
{
    /*
    Initializes the layer with the appropriate number of neurons.
    Indices in the neuron vector start at 0, so we have neuron indices
    from 0 to numNeurons-1.
    */

    m_numNeurons = numNeurons;
    m_activationType = activationType;
    m_activationsVector.resize(m_numNeurons);
    for (int neuronIndex=0; neuronIndex<numNeurons; ++neuronIndex)
    {
        // currently initializes layer with neuron inputs all 0.0 - to be researched
        m_neurons.push_back(Neuron(0.0, m_activationType));
    }
}

/*
TODO: create a more functional approach to retrieving and setting values;
currently Layer has wayyy to much repeated for loops in getInputs(), getActivations(), etc. 
*/

void Layer::setActivationType(Activation activationType)
{
    m_activationType = activationType;
    for (Neuron neuron : m_neurons)
    {
        neuron.setActivationType(m_activationType);
    }
}

void Layer::setInputAt(int neuronIndex, double input)
{
    /*
    Sets the input of neuron at 'neuronIndex' in the neurons vector.
    */

    m_neurons.at(neuronIndex).setInput(input);
    m_activationsVector.at(neuronIndex) = m_neurons.at(neuronIndex).getActivation();
}

void Layer::setBiasAt(int neuronIndex, double bias)
{
    /*
    Sets the bias of neuron at neuronIndex in the layer.
    */

   m_neurons.at(neuronIndex).setBias(bias);
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
    Returns the activation of each neuron in the layer as a vector.
    */
    return m_activationsVector;
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

double Layer::getActivationAt(int neuronIndex) const
{
    return m_neurons.at(neuronIndex).getActivation();
}

double Layer::getBiasAt(int neuronIndex) const
{
    return m_neurons.at(neuronIndex).getBias();
}