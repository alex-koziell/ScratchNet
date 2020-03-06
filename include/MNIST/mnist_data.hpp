#ifndef MNIST_DATA_HPP
#define MNIST_DATA_HPP

#include <vector>
#include "stdint.h"
#include "stdio.h"

class MNISTData {
    private:
        std::vector<uint8_t>* featureVector;
        std::vector<double> doubleFeatureVector;
        std::vector<int> classVector;
        uint8_t label;
        int enumLabel;
        double distance;

    public:
        MNISTData();
        ~MNISTData();

        void setFeatureVector(std::vector<uint8_t>*);
        void appendToFeatureVector(uint8_t);
        void setLabel(uint8_t);
        void setEnumLabel(int);
        void setDistance(double);

        int featureVectorSize();
        uint8_t getLabel();
        int getEnumLabel();
        std::vector<uint8_t>* getFeatureVector();
        double getDistance();

        
};

#endif