#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <iostream>
#include <math.h>
using namespace std;

class Neuron {
    public:
        Neuron(double value);

        /*
        Function to set the input.
        */
        void setValue(double value);

        /*
        Functions for computing the activation value
        and its derivative from the neuron's input value.
        */ 
        void activate();
        void derive();

        /*
        Functions for accessing the input value,
        activation and derivative of the neuron.
        */
        double getValue() { return this->value; }
        double getActivation() { return this->activation; }
        double getDerivedVal() { return this->derivedVal; }

    private:
        // input value
        double value;

        // activation (between 0 and 1)
        double activation;

        // approximate derivative of the activation
        double derivedVal;
};

#endif