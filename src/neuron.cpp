#include "../include/neuron.hpp"

Neuron::Neuron(double input) {
    m_input = input;
    activate();
    derive();
}

Neuron::Neuron(double input, double bias) {
    m_input = input;
    m_bias = bias;
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

void Neuron::setBias(double bias)
{
    m_bias = bias;
}

void Neuron::activate() {
    /*
    Sets the activation value of the neuron
    currently using the fast sigmoid function:

    f(x) = x / (1 + |x|)

    */

    m_activation = (m_input + m_bias) / (1 + abs(m_input + m_bias));
}

void Neuron::derive() {
    /*
    Sets the derivative according to the
    current activation function.

    f'(x) = f(x) * (1 - f(x))

    */

    m_derivative = m_activation * (1 - m_activation);
}