#include "ml_models/DNN/neuron.hpp"
#include "ml_models/DNN/parameters.hpp"
#include <cmath>
#include <algorithm>

Neuron::Neuron(double input, Activation type)
{
    m_input = input;
    m_activationType = type;
    activate();
    derive();
}

Neuron::Neuron(double input, double bias, Activation type)
{
    m_input = input;
    m_bias = bias;
    activate();
    derive();
}

void Neuron::setActivationType(Activation type)
{
    m_activationType = type;
}

void Neuron::setInput(double newInput)
{
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
    Sets the activation value of the neuron.
    */

   switch(m_activationType)
   {
        case Activation::TANH:
            m_activation = tanh(m_input + m_bias);
            break;
        case Activation::RELU:
            m_activation = std::max(0.0, m_input);
            break;
        case Activation::FAST_SIGMOID:
            m_activation = m_input / (1 + abs(m_input));
            break;
        default:
            m_activation = tanh(m_input + m_bias);
            break;
   }
    
}

void Neuron::derive() {
    /*
    Sets the derivative according to the
    current activation function.

    Fast sigmoid: f'(x) = f(x) * (1 - f(x))
    d/dx(tanh(x)) = 1 - tanh^2(x)

    */

    switch(m_activationType)
    {
        case Activation::TANH:
            m_derivative = 1 - m_activation * m_activation;
            break;
        case Activation::RELU:
            m_activation = m_input>0 ? 1 : 0;
            break;
        case Activation::FAST_SIGMOID:
            m_derivative = m_activation*(1-m_activation);
            break;
        default:
            m_derivative = 1 - m_activation * m_activation;
            break;
    }
    
}