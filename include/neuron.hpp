#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <iostream>
#include <math.h>
using namespace std;

class Neuron {
    public:
        Neuron(double value);

        void setValue(double value);

        // fast sigmoid funtion
        // f(x) = x / (1 + |x|)
        // derivative f(x) * (1 - f(x))
        void activate();
        void derive();

        double getValue() { return this->value; }
        double getActivation() { return this->activation; }
        double getDerivedVal() { return this->derivedVal; }

    private:
        // absolute value
        double value;

        // activation (between 0 and 1)
        double activation;

        // approximate derivative of the activated value
        double derivedVal;
};

#endif