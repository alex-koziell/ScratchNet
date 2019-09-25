#include "../include/network.hpp"
#include "../include/utils/linearalgebra.hpp"

Network::Network(vector<int> &layerSizes) {
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

void Network::setInput(vector<double> &input) {
    /*
    Sets the inputs of the neurons in the 0th (input) layer.
    */

    m_input = input;

    for (int neuronIndex=0; neuronIndex<input.size(); ++neuronIndex)
    {
        m_layers.at(0).setInputAt(neuronIndex, input.at(neuronIndex));
    }
}

void Network::feedForward() {
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

void Network::printToConsole() {
    /*
    Prints the input values of the neurons in the input layer,
    then the activations of the neurons in subsequent layers.
    */

    for (int layerNum=0; layerNum<m_numLayers; ++layerNum) {

        if (layerNum==0)
        {
            cout << "INPUT LAYER:" << endl;
            Matrix thisLayer{ m_layers.at(layerNum).getInputs() };
            thisLayer.printToConsole();
        } else {
            cout << "LAYER " << layerNum << ":" << endl;
            vector<double> thisLayer{ m_layers.at(layerNum).getActivations() };
            linalg::printToConsole(thisLayer);
        }
    }
    cout << endl;
}