#include "../include/neuron.hpp"

Neuron::Neuron(double input) {
    m_input = input;
    activate();
    derive();
}

void Neuron::setInput(double newInput) {
    /*
    Sets the neuron's input to a new value, then
    recomputes the activation and its derivative.
    */

    m_input = newInput;
    activate();
    derive();
}

void Neuron::activate() {
    /*
    Sets the activation value of the neuron
    currently using the fast sigmoid function:

    f(x) = 1 / (1 + |x|)

    */

    m_activation = m_input / (1 + abs(m_input));
}

void Neuron::derive() {
    /*
    Sets the derivative according to the
    current the activation function.

    f'(x) = f(x) * (1 - f(x))

    */

    m_derivative = m_activation * (1 - m_activation);
}