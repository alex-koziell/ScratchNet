#ifndef KNN_HPP
#define KNN_HPP

#include <vector>
#include "../MNIST/mnist_data.hpp"

class KNN {
    private:
        int k;
        std::vector<MNISTData*>* neighbours;
        std::vector<MNISTData*>* trainingData;
        std::vector<MNISTData*>* testData;
        std::vector<MNISTData*>* validationData;
        double distance;
        
    public:
        KNN(int initialK);

        void findKNearest(MNISTData* queryPoint);
        void setTrainingData(std::vector<MNISTData*>* data);
        void setTestData(std::vector<MNISTData*>* data);
        void setValidationData(std::vector<MNISTData*>* data);
        void setK(int value);

        int predictClass();
        double calculateDistance(MNISTData* queryPoint, MNISTData* input);
        double getDistance();
        double validateModel();
        double testModel();
};

#endif