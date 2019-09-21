#include "../include/layer.hpp"
#include "../include/matrix.hpp"

Layer::Layer(int size) {
    this->size = size;

    // cout << "CREATING LAYER OF " << size << " NEURONS" << endl;
    for (int neuronIndex=0; neuronIndex<size; neuronIndex++) {
        // cout << "CREATING NEURON" << endl;
        Neuron *newNeuron = new Neuron(0.00);
        this->neurons.push_back(newNeuron);
        // cout << this->neurons.size() << " NEURONS CREATED IN CURRENT LAYER." << endl;
    }
}

void Layer::setValue(int neuronIndex, double input) {
    this->neurons.at(neuronIndex)->setInput(input);
}

Matrix* Layer::getValues() {
    Matrix *valuesMatrix = new Matrix(1, this->size, false);

    for (int i=0; i<this->size; i++) {
        valuesMatrix->setValue(0, i, this->neurons.at(i)->getInput());
    }

    return valuesMatrix;
}

Matrix* Layer::getActivations() {
    Matrix *valuesMatrix = new Matrix(1, this->size, false);

    for (int i=0; i<this->size; i++) {
        valuesMatrix->setValue(0, i, this->neurons.at(i)->getActivation());
    }

    return valuesMatrix;
}

Matrix* Layer::getDerivatives() {
    Matrix *valuesMatrix = new Matrix(1, this->size, false);

    for (int i=0; i<this->size; i++) {
        valuesMatrix->setValue(0, i, this->neurons.at(i)->getDerivative());
    }

    return valuesMatrix;     
}