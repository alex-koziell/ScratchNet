#include "../include/neuron.hpp"

Neuron::Neuron(double input) {
    this->input = input;
    activate();
    derive();
}

void Neuron::setInput(double newInput) {
    /*
    Sets the neuron's input to a new value, then
    recomputes the activation and its derivative.
    */

    this->input = newInput;
    activate();
    derive();
}

void Neuron::activate() {
    /*
    Sets the activation value of the neuron
    currently using the fast sigmoid function:

    f(x) = 1 / (1 + |x|)

    */

    this->activation = this->input / (1 + abs(this->input));
}

void Neuron::derive() {
    /*
    Sets the derivative according to the
    current the activation function.

    f'(x) = f(x) * (1 - f(x))

    */

    this->derivative = this->activation * (1 - this->activation);
}