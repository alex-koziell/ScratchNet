#include "../include/layer.hpp"
#include "../include/matrix.hpp"

Layer::Layer(int numNeurons) {
    /*
    Initializes the layer with the appropriate number of neurons.
    Indices in the neuron vector start at 0, so we have neuron indices
    from 0 to numNeurons-1.
    */

    this->numNeurons = numNeurons;
    for (int neuronIndex=0; neuronIndex<numNeurons; ++neuronIndex)
    {
        Neuron *newNeuron = new Neuron(0.00); // currently initializes layer with neuron inputs all 0.0 - to be researched
        this->neurons.push_back(newNeuron);
    }
}

/*
TODO: create a more functional approach to retrieving and setting values;
currently Layer has wayyy to much repeated for loops in getInputs(), getActivations(), etc. 
*/


void Layer::setInputAt(int neuronIndex, double input) {
    /*
    Sets the input of neuron at 'neuronIndex' in the neurons vector.
    */

    this->neurons.at(neuronIndex)->setInput(input);
}

Matrix* Layer::getInputs() {
    /*
    Returns the inputs of the neurons in the layer as a matrix object
    (rather than a vector: this allows us to use the matrix multiplication
    'function class').
    */

    Matrix *inputsMatrix = new Matrix(1, this->numNeurons, false);

    for (int neuronIndex=0; neuronIndex<this->numNeurons; ++neuronIndex)
    { // uses the getInput() accessor function of the neuron class to map the neurons' input values to inputsMatrix.
        inputsMatrix->setValue(0, neuronIndex, this->neurons.at(neuronIndex)->getInput());
    }

    return inputsMatrix;
}

Matrix* Layer::getActivations() {
    /*
    Returns the activation of each neuron in the layer.
    */

    Matrix *activationMatrix = new Matrix(1, this->numNeurons, false);

    for (int neuronIndex=0; neuronIndex<this->numNeurons; ++neuronIndex)
    {   // uses accessor function of the neuron class similarly to Layer::getInputs()
        activationMatrix->setValue(0, neuronIndex, this->neurons.at(neuronIndex)->getActivation());
    }

    return activationMatrix;
}

Matrix* Layer::getDerivatives() {
    /*
    Returns the derivative of the activation for each neuron in the layer.
    */

    Matrix *derivativesMatrix = new Matrix(1, this->numNeurons, false);

    for (int neuronIndex=0; neuronIndex<this->numNeurons; ++neuronIndex)
    {
        derivativesMatrix->setValue(0, neuronIndex, this->neurons.at(neuronIndex)->getDerivative());
    }

    return derivativesMatrix;  
}