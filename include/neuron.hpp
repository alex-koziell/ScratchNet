#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <iostream>
#include <math.h>
using namespace std;

class Neuron {
    public:
        Neuron(double val);

        // fast sigmoid funtion
        // f(x) = x / (1 + |x|)
        // derivative f(x) * (1 - f(x))
        void activate();
        void derive();

        double getVal() { return this->val; }
        double getActivatedVal() { return this->activatedVal; }
        double getDerivedVal() { return this->derivedVal; }

    private:
        // absolute value
        double val;

        // activation (between 0 and 1)
        double activatedVal;

        // approximate derivative of the activated value
        double derivedVal;
};

#endif