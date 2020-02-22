#ifndef MNIST_DATA_HPP
#define MNIST_DATA_HPP

#include <vector>
#include "stdint.h"
#include "stdio.h"

class MNISTData {
    private:
        std::vector<uint8_t>* feature_vector;
        uint8_t label;
        int enumLabel;

    public:
        MNISTData();
        ~MNISTData();

        void setFeatureVector(std::vector<uint8_t>*);
        void appendToFeatureVector(uint8_t);
        void setLabel(uint8_t);
        void setEnumLabel(int);

        int featureVectorSize();
        uint8_t getLabel();
        int getEnumLabel();
        std::vector<uint8_t>* getFeatureVector();
};

#endif