#include "data_processing/XOR/XOR_preprocessor.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

Preprocessor::Preprocessor(string filePath)
{
    /*
    Using the image filepath, create data that can be used by the network to train.

    The output format (m_data) is 3-dimensional vector, where indices i,j,k
    correspond to training sample, input/output vector, and neuron index respectively.
    */

    ifstream inFile(filePath);

    // first line dictates required input and output layer sizes
    string layerSizes;
    getline(inFile, layerSizes);
    istringstream layerSizeStream (layerSizes);
    while(!layerSizeStream.eof())
    {
        layerSizeStream >> m_inputSize;
        layerSizeStream >> m_outputSize;
    }

    // create separate input and target output vectors
    while (!inFile.eof())
    {
        vector<vector<double>> trainingSample; // data for this training sample

        string inputs;
        getline(inFile, inputs); // read an input line
        vector<double> sampleInputs { createLayerVector(inputs) }; // create a vector of inputs
        trainingSample.push_back(sampleInputs); // j=0 in m_data corresponds to an input vector

        string outputs;
        getline(inFile, outputs); // the next line is an output line 
        vector<double> sampleOutputs { createLayerVector(outputs)};
        trainingSample.push_back(sampleOutputs); // j=1 corresponds to an output vector

        m_data.push_back(trainingSample); // add the sample to the complete dataset
    }

}

vector<double> Preprocessor::createLayerVector(string values)
{
    /*
    Turns a string of doubles, separated by spaces, into a vector of doubles
    which can be read as the input/output activations of the network.
    (Or the inputs/activations of any layer, for that matter).
    */

    vector<double> layerVector;
    stringstream valueStream (values);
    while(!valueStream.eof())
    {
        double value;
        valueStream >> value; // read in until a space occurs
        layerVector.push_back(value);
    }
    return layerVector;
}