#include "MNIST/mnist_data.hpp"

#include <vector>
#include "stdint.h"

void MNISTData::setFeatureVector(std::vector<double> value) { featureVector = value; }
void MNISTData::appendToFeatureVector(double value) { featureVector.push_back(value); }
void MNISTData::setLabel(int value)
{ 
    label = value;
    classVector.resize(NUM_CLASSES);
    for (int i=0; i<NUM_CLASSES; ++i)
    {
        classVector.at(i) = i==label ? 1 : 0;
    }
}
void MNISTData::setDistance(double value) { distance = value; }

int MNISTData::featureVectorSize() { return featureVector.size(); }
int MNISTData::getLabel() { return label; }
std::vector<double> MNISTData::getFeatureVector() { return featureVector; }
std::vector<double> MNISTData::getClassVector()   { return classVector; }

// KNN
double MNISTData::getDistance() { return distance; }