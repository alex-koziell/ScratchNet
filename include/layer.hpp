#ifndef _LAYER_HPP_
#define _LAYER_HPP_

#include <vector>
#include "neuron.hpp"

using namespace std;

class Layer {
    public:
        Layer(int size);

    private:
        int size;
        vector<Neuron *> neurons;
};

#endif