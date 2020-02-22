#ifndef MNIST_DATA_HANDLER_HPP
#define MNIST_DATA_HANDLER_HPP

#include <fstream>
#include <map>
#include "stdint.h"
#include <string>
#include <unordered_set>
#include <vector>

#include "mnist_data.hpp"

class MNISTDataHandler {
    private:
        std::vector<MNISTData*>* allData;
        std::vector<MNISTData*>* trainingData;
        std::vector<MNISTData*>* testData;
        std::vector<MNISTData*>* validationData;

        int numClasses;
        int featureVectorSize;
        std::map<uint8_t, int> classMap;

        const double TRAIN_SET_PERCENT {0.6};
        const double TEST_SET_PERCENT {0.2};
        const double VALIDATION_SET_PERCENT {0.2};

    public:
        MNISTDataHandler();
        ~MNISTDataHandler();

        void readFeatureVector(std::string path);
        void readLabels(std::string path);
        void splitData();
        void countClasses();
        

        uint32_t convertToLittleEndian(const unsigned char* bytes);
        std::vector<MNISTData*>* getTrainingData();
        std::vector<MNISTData*>* getTestData();
        std::vector<MNISTData*>* getValidationData();



};

#endif