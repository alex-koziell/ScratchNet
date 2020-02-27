#include "../../include/MNIST/mnist_data.hpp"

MNISTData::MNISTData()
{
 featureVector = new std::vector<uint8_t>;
}
MNISTData::~MNISTData()
{

}

void MNISTData::setFeatureVector(std::vector<uint8_t>* value) { featureVector = value; }
void MNISTData::appendToFeatureVector(uint8_t value) { featureVector->push_back(value); }
void MNISTData::setLabel(uint8_t value) { label = value; }
void MNISTData::setEnumLabel(int value) { enumLabel = value; }
void MNISTData::setDistance(double value) { distance = value; }

int MNISTData::featureVectorSize() { return featureVector->size(); }
uint8_t MNISTData::getLabel() { return label; }
int MNISTData::getEnumLabel() { return enumLabel; }
std::vector<uint8_t>* MNISTData::getFeatureVector() { return featureVector; }
double MNISTData::getDistance() { return distance; }