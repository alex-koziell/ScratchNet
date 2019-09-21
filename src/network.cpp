#include "../include/network.hpp"

Network::Network(vector<int> topology) {
    this->topology = topology;
    this->numLayers = topology.size();

    // cout << "CREATING " << numLayers << " LAYERS..." << endl;
    for (int i=0; i<numLayers; i++) {
        Layer *newLayer = new Layer(topology.at(i)); // create a new layer of size given by topology

        this->layers.push_back(newLayer);
        // cout << this->layers.size() << " LAYERS CREATED." << endl;
    }

    for (int i=0; i<numLayers-1; i++) {
        Matrix *newMatrix = new Matrix(
            topology.at(i), // rows correspond to neurons in current layer
            topology.at(i+1), // columns to neurons in next layer
            true // randomly initialize weights
        );

        this->weightMatrices.push_back(newMatrix);
    }
}

void Network::setInput(vector<double> input) {
    this->input = input;

    for (int i=0; i<input.size(); i++) {
        this->layers.at(0)->setInputAt(i, input.at(i));
    }
}

void Network::printToConsole() {
    for (int i=0; i<numLayers; i++) {
        cout << "LAYER " << i << ":" << endl;

        if (i==0) {
            Matrix *thisLayer = this->layers.at(i)->getInputs();
            thisLayer->printToConsole();

        } else {
            Matrix *thisLayer = this->layers.at(i)->getActivations();
            thisLayer-> printToConsole();
        }
    }
}

void Network::feedForward() {
    /*
    Implements the feedforward algorithm.
    */

    for (int layerNum=0; layerNum<(this->layers.size()-1); layerNum++)
    {

    }
}