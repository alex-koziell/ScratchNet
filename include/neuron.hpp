#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <iostream>
#include <math.h>
using namespace std;

class Neuron 
{
/*
Neuron class with the essential features required for a 
feedforward neural network: an input value, an activation value,
and the ability to get the derivative of its activation.
*/

    public:
        Neuron(double input);

        void setInput(double input);    // Function to set the input.
        void activate();                // Function to compute the activation.
        void derive();                  // Function to compute the derivative of the activation.

        double getInput()      { return this->input; }      // Accessor for input value.
        double getActivation() { return this->activation; } // Accessor for activation value.
        double getDerivative() { return this->derivative; } // Accessor for the derrivative of the activation.

    private:
        double input;       // Input value
        double activation;  // Activation of the neuron.
        double derivative;  // Derivative of the neuron's activation.
};

#endif