#include "../include/layer.hpp"

Layer::Layer(int size) {
    this->size = size;

    // add neurons to layer
    for (int i=0; i++; i<size) {
        Neuron *n = new Neuron(0.00);
        this->neurons.push_back(n);
    }
}