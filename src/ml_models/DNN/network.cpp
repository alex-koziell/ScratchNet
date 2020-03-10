#include "ml_models/DNN/network.hpp"
#include "ml_models/DNN/parameters.hpp"
#include "math/linearalgebra.hpp"
#include "math/numerical.hpp"

#include <ctime>
#include <iostream>
#include <vector>


using namespace std;

Network::Network(vector<int> &layerSizes, vector<Activation> &activationTypes)
{
    m_layerSizes = layerSizes;
    m_numLayers = layerSizes.size();
    
    m_errors.resize(m_numLayers-1);
    for (int l=0; l<m_numLayers-1; ++l)
    {
        m_errors.at(l).resize(m_layerSizes.at(l+1));
    }

    for (int layerNum=0; layerNum<m_numLayers; ++layerNum)
    { 
        m_layers.push_back(Layer(layerSizes.at(layerNum), activationTypes.at(layerNum))); // Then add it to this network's vector of layers.
    }

    for (int layerNum=0; layerNum<m_numLayers-1; ++layerNum)
    {
        m_weightMatrices.push_back
        (
            linalg::Matrix<double>
            ( // Create a new weight matrix for each pair of adjacent layers.
            layerSizes.at(layerNum+1),  // Rows correspond to neurons in next layer,
            layerSizes.at(layerNum),    // columns to neurons in current layer.
            true                        // Initialize weights to random doubles.
            )
        );

        for (int neuronIndex=0; neuronIndex<m_layers.at(layerNum+1).getSize(); ++neuronIndex)
        { // randomly initialize neuron biases in the hidden and output layers
            m_layers.at(layerNum+1).setBiasAt(neuronIndex, double{numerical::randomDouble()});
        }
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
        vector<double> currentLayerOutputs { m_layers.at(layerNum).getActivations() };
        vector<double> nextLayerInputs { m_weightMatrices.at(layerNum) * currentLayerOutputs };

        for (int neuronNum=0; neuronNum<nextLayerInputs.size(); ++neuronNum)
        {// set the inputs of the next layer, with bias
            m_layers.at(layerNum+1).setInputAt(neuronNum, nextLayerInputs.at(neuronNum));
        }

    }
}

void Network::backPropagate(bool isNewBatch)
{
    /*
    Implements backpropagation using quadratic cost function,
    with derivative (activation - target value).
    */

    // Compute the output error: equal to ( grad the vector of quadratic costs for
    // each neuron, Hadamard product the vector of derivatives of the output neurons ).
    vector<double> gradCost;
    vector<double> output {m_layers.back().getActivations()};
    vector<double> outputDerivatives {m_layers.back().getDerivatives()};
    
    for(int i=0; i<m_layers.back().getSize(); ++i)
    {
        gradCost.push_back(output.at(i) - m_targetOutput.at(i));
    }
    // Output error
    if (isNewBatch)
    {
        m_errors.at(m_numLayers-2) = linalg::hadamardProduct(gradCost, outputDerivatives);
    }
    else
    {
        m_errors.at(m_numLayers-2) += linalg::hadamardProduct(gradCost, outputDerivatives);
    }
    

    std::cout << "ERRORS:";
    linalg::print(m_errors.at(m_numLayers-2));

    // Backpropagate the error
    for(int i=m_numLayers-2; i>0; --i) // m_numLayers should be equal to m_weightMatrices.size()-1
    {
        linalg::Matrix<double> weights_T { m_weightMatrices.at(i).transpose() };
        vector<double> thisLayerDerivatives { m_layers.at(i).getDerivatives() };

        vector<double> backpropagatedError { weights_T * m_errors.at(i) };
        vector<double> thisLayerError {linalg::hadamardProduct(backpropagatedError, thisLayerDerivatives)};

        // m_errors goes from 0 to m_numLayers-2, where the first entry is the error in the first hidden layer
        if (isNewBatch)
        {
            m_errors.at(i-1) = thisLayerError;
        }
        else
        {
            m_errors.at(i-1) += thisLayerError;
        }

        // linalg::print(m_errors.at(i-1));
    };
}

void Network::update()
{
    /*
    Using the most recent error, updates the weight matrices
    and neuron biases.
    */

   for(int l=0; l<m_weightMatrices.size(); ++l)
   {
        linalg::Matrix<double> &currentWeightMatrix = m_weightMatrices.at(l);      // weight of connections from layer l to layer l+1
        vector<double> &currentError = m_errors.at(l);
        double learningCoefficient {m_LEARNINGRATE / m_BATCHSIZE};

        // neuron indexing: i in layer l and j in layer l+1
        int maxj { currentWeightMatrix.numRows()-1 };
        int i {0}; int j {0};
        for(double matrixEntry: currentWeightMatrix.getValues())
        {
            matrixEntry -= learningCoefficient
                           * m_layers.at(l).getActivationAt(i) // activation of neuron i in layer l
                           * m_errors.at(l).at(j);
            if(j<maxj)
            {
                ++j;
            } else {
                double newBias { m_layers.at(l+1).getBiasAt(j)
                - learningCoefficient
                * m_errors.at(l).at(j)};
                m_layers.at(l+1).setBiasAt(j, newBias);
                
                j = 0;
                ++i;
            }
        }
   }
}

void Network::train(vector<vector<vector<double>>> trainingData)
{
    /*
    Trains the network on a training set, given data in the appropriate format.
    */

    int trainingPass {1};
    int sampleNum    {1};

    for (vector<vector<double>> trainingSample : trainingData) // for each training sample
    {
        clock_t time0 {clock()};
        /* Set inputs */
        vector<double> input {trainingSample.at(0)};
        setInput(input);
        clock_t time1 {clock()};

        /* Current target */
        vector<double> targetOutput {trainingSample.at(1)};
        setTarget(targetOutput);
        clock_t time2 {clock()};
        /* Feedforward */
        std::cout << "(PASS : " << trainingPass << ")" << endl;
        feedForward();
        clock_t time3 {clock()};
        // printToConsole();
        std::cout << "OUTPUT LAYER:";
        vector<double> layerVector{ m_layers.at(m_numLayers-1).getActivations() };
        linalg::print(layerVector);
        std::cout << "Target: [";
        for (double output : targetOutput)
        {
            std::cout << " " << output << ",";
        }
        std::cout << "]"<<endl;

        /* Backpropagate */
        clock_t time4 {clock()};
        backPropagate(sampleNum==1);
        clock_t time5 {clock()};

        /* Update weights if end of batch */
        if (sampleNum == m_BATCHSIZE)
        {
            update();
            sampleNum = 0; // new batch, ++sampleNum below resets it to 1 by the end of the training pass
        }

        ++sampleNum;
        ++trainingPass;

        clock_t time6 {clock()};
        cout<<"Time for setting input: "<<time1-time0<<endl;
        cout<<"Time for setting target: "<<time2-time1<<endl;
        cout<<"Time for feedforward: "<<time3-time2<<endl;
        cout<<"Time for backprop: "<<time5-time4<<endl;
        cout<<"Time for update: "<<time6-time5<<endl;
        cout<<"Time for full pass: "<<time6-time0<<endl<<endl;
    }
}

void Network::printToConsole() const
{
    /*
    Prints the input values of the neurons in the input layer,
    then the activations of the neurons in subsequent layers.
    */

    for (int layerIndex=0; layerIndex<m_numLayers; ++layerIndex) {

        if (layerIndex==0)
        {
            std::cout << "INPUT LAYER:";
            vector<double> layerVector{ m_layers.at(layerIndex).getInputs() };
            linalg::print(layerVector);
        } 
        else if (layerIndex==m_numLayers-1)
        {
            std::cout << "OUTPUT LAYER:";
            vector<double> layerVector{ m_layers.at(layerIndex).getActivations() };
            linalg::print(layerVector);
        }
        else
        {
            std::cout << "LAYER " << layerIndex << ":";
            vector<double> layerVector{ m_layers.at(layerIndex).getActivations() };
            linalg::print(layerVector);
        }
    }
    std::cout << endl;
}