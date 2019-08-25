#include "../include/neuron.hpp"

// constructor
Neuron::Neuron(double value) {
    this->value = value;

    // set activation and gradient
    activate();
    derive();
}

void Neuron::setValue(double newValue) {
    this->value = newValue;
    activate();
    derive();
}

void Neuron::activate() {
    this->activation = this->value / (1 + abs(this->value));
}

void Neuron::derive() {
    this->derivedVal = this->activation * (1 - this->activation);
}