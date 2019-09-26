#include "../include/network.hpp"
#include "../include/utils/linearalgebra.hpp"

Network::Network(vector<int> &layerSizes)
{
    m_layerSizes = layerSizes;
    m_numLayers = layerSizes.size();

    // cout << "CREATING " << numLayers << " LAYERS..." << endl;
    for (int layerNum=0; layerNum<m_numLayers; ++layerNum)
    { 
        m_layers.push_back(Layer(layerSizes.at(layerNum)));                     // Then add it to this network's vector of layers.
    }
    // cout << m_layers.size() << " LAYERS CREATED." << endl;

    for (int layerNum=0; layerNum<m_numLayers-1; ++layerNum)
    {
        m_weightMatrices.push_back
        (
            Matrix
            ( // Create a new weight matrix for each pair of adjacent layers.
            layerSizes.at(layerNum+1),    // Rows correspond to neurons in next layer,
            layerSizes.at(layerNum),  // columns to neurons in current layer.
            true                        // Initialize weights to random doubles.
            )
        );
    }
}

void Network::setInput(vector<double> &input)
{
    /*
    Sets the inputs of the neurons in the 0th (input) layer.
    */

    m_input = input;

    for (int neuronIndex=0; neuronIndex<input.size(); ++neuronIndex)
    {
        m_layers.at(0).setInputAt(neuronIndex, input.at(neuronIndex));
    }
}

void Network::feedForward()
{
    /*
    Implements the feedforward algorithm.
    */

    for (int layerNum=0; layerNum<(m_layers.size()-1); ++layerNum) // for the input to penultimate layer
    {
        vector<double> currentLayerOutputs = m_layers.at(layerNum).getActivations();
        vector<double> nextLayerInputs = linalg::matrixVectorProduct
        (// calculate the inputs to the next layer
            m_weightMatrices.at(layerNum),
            currentLayerOutputs
        );

        for (int neuronNum=0; neuronNum<nextLayerInputs.size(); ++neuronNum)
        {// set the inputs of the next layer
            m_layers.at(layerNum+1).setInputAt(neuronNum, nextLayerInputs.at(neuronNum));
        }

    }
}

void Network::backPropagate()
{
    /*
    Implements backpropagation using quadratic cost function,
    with derivative (activation - target value).
    */

    // compute the output error: equal to grad the vector of quadratic costs for
    // each neuron, Hadamard product the vector of derivatives of the output neurons.
    vector<double> gradCost;
    vector<double> output = m_layers.back().getActivations();
    vector<double> outputDerivatives = m_layers.back().getDerivatives();
    
    for(int i=0; i<m_layers.back().getSize(); ++i)
    {
        gradCost.push_back(output.at(i) - m_targetOutput.at(i));
    }

    vector<double> outputError = linalg::hadamardProduct(gradCost, outputDerivatives);
    linalg::printToConsole(outputError);
    
}

void Network::printToConsole()
{
    /*
    Prints the input values of the neurons in the input layer,
    then the activations of the neurons in subsequent layers.
    */

    for (int layerIndex=0; layerIndex<m_numLayers; ++layerIndex) {

        if (layerIndex==0)
        {
            cout << "INPUT LAYER:" << endl;
            vector<double> layerVector{ m_layers.at(layerIndex).getInputs() };
            linalg::printToConsole(layerVector);
        } 
        else if (layerIndex==m_numLayers-1)
        {
            cout << "OUTPUT LAYER:" << endl;
            vector<double> layerVector{ m_layers.at(layerIndex).getActivations() };
            linalg::printToConsole(layerVector);   
        }
        else
        {
            cout << "LAYER " << layerIndex << ":" << endl;
            vector<double> layerVector{ m_layers.at(layerIndex).getActivations() };
            linalg::printToConsole(layerVector);
        }
    }
    cout << endl;
}