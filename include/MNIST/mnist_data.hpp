#ifndef MNIST_DATA_HPP
#define MNIST_DATA_HPP

#include <vector>
#include "stdint.h"
#include "stdio.h"

class MNISTData {
    private:
        std::vector<double> featureVector;
        std::vector<double> classVector;
        int label;
        int NUM_CLASSES {10};

        // KNN
        double distance;

    public:
        void setFeatureVector(std::vector<double>);
        void appendToFeatureVector(double);
        void setLabel(int);
        
        int featureVectorSize();
        int getLabel();
        int getEnumLabel();
        std::vector<double> getFeatureVector();
        std::vector<double> getClassVector();

        // KNN
        void setDistance(double);
        double getDistance();

        
};

#endif