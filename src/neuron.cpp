#include "../include/neuron.hpp"
#include <cmath>

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

    Originally the fast sigmoid function, f(x) = x / (1 + |x|),
    which failed to converge on XOR training data.
    
    Now using tanh(x), which works on XOR!

    */

    m_activation = tanh(m_input + m_bias);
}

void Neuron::derive() {
    /*
    Sets the derivative according to the
    current activation function.

    Fast sigmoid: f'(x) = f(x) * (1 - f(x))
    d/dx(tanh(x)) = 1 - tanh^2(x)

    */

    m_derivative = 1 - m_activation * m_activation;
}