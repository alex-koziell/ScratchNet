#ifndef COMMON_HPP
#define COMMON_HPP

#include "MNIST/mnist_data.hpp"
#include <vector>

class commonData {
    protected:
        std::vector<MNISTData> trainingData;
        std::vector<MNISTData> testData;
        std::vector<MNISTData> validationData;

    public:
        void setTrainingData(std::vector<MNISTData> data);
        void setTestData(std::vector<MNISTData> data);
        void setValidationData(std::vector<MNISTData> data);
};


#endif