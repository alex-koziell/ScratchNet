#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <vector>
#include "neuron.hpp"
#include "matrix.hpp"

using namespace std;

class Layer {
    public:
        Layer(int size);

        void setValue(int neuronIndex, double value); // set value of neuron at neuronIndex

        Matrix* getValues();
        Matrix* getActivations();
        Matrix* getDerivatives();

    private:
        int size;
        vector<Neuron *> neurons;
};

#endif