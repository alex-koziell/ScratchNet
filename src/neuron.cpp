#include "../include/neuron.hpp"

// constructor
Neuron::Neuron(double val) {
    this->val = val;

    // set activation and gradient
    activate();
    derive();
}

void Neuron::setVal(double newVal) {
    this->val = val;
    activate();
    derive();
}

void Neuron::activate() {
    this->activatedVal = this->val / (1 + abs(this->val));
}

void Neuron::derive() {
    this->derivedVal = this->activatedVal * (1 - this->activatedVal);
}