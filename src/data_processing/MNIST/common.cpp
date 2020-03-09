#include "data_processing/MNIST/common.hpp"
#include "data_processing/MNIST/mnist_data.hpp"
#include <vector>

void commonData::setTrainingData(std::vector<MNISTData> data)   { trainingData = data; }
void commonData::setTestData(std::vector<MNISTData> data)       { testData = data; }
void commonData::setValidationData(std::vector<MNISTData> data) { validationData = data; }