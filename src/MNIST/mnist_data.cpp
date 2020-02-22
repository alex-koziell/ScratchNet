#include "../../include/MNIST/mnist_data.hpp"

MNISTData::MNISTData()
{

};
MNISTData::~MNISTData()
{

};

void MNISTData::setFeatureVector(std::vector<uint8_t>* value) { feature_vector = value; };
void MNISTData::appendToFeatureVector(uint8_t value) { feature_vector->push_back(value); };

void MNISTData::setLabel(uint8_t value) { label = value; };
void MNISTData::setEnumLabel(int value) { enumLabel = value; };

int MNISTData::featureVectorSize() { return feature_vector->size(); };
uint8_t MNISTData::getLabel() { return label; };
int MNISTData::getEnumLabel() { return enumLabel; };
std::vector<uint8_t>* MNISTData::getFeatureVector() { return feature_vector; };