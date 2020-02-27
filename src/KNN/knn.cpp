#include "../../include/KNN/knn.hpp"
#include "../../include/MNIST/mnist_data_handler.hpp"

#include <cmath>
#include <limits>
#include <map>
#include "stdint.h"

KNN::KNN(int initialK) { k = initialK; }

void KNN::findKNearest(MNISTData* queryPoint)
{
    neighbours = new std::vector<MNISTData*>;
    double min {std::numeric_limits<double>::max()};
    double previousMin {min};
    int index {0};
    
    for (int i=0; i<k; ++i)
    {
        if (i==0)
        {
            for (int j=0; j<queryPoint->featureVectorSize(); ++j)
            {
                double distance {calculateDistance(queryPoint, trainingData->at(j))};
                trainingData->at(j)->setDistance(distance);
                if (distance<min)
                {
                    min = distance;
                    index = j;
                }
            }
            neighbours->push_back(trainingData->at(index));
            previousMin = min;
            min = std::numeric_limits<double>::max();
        } else
        {
            for (int j=0; j<queryPoint->featureVectorSize(); ++j)
            {
                double distance { trainingData->at(j)->getDistance() };
                if (distance>previousMin && distance < min)
                {
                    min = distance;
                    index = j;
                }
            }
            neighbours->push_back(trainingData->at(index));
            previousMin = min;
            min = std::numeric_limits<double>::max();
        }
    }
}
void KNN::setTrainingData(std::vector<MNISTData*>* data)   { trainingData = data; }
void KNN::setTestData(std::vector<MNISTData*>* data)       { testData = data; }
void KNN::setValidationData(std::vector<MNISTData*>* data) { validationData = data; }
void KNN::setK(int value) { k = value; }

int KNN::predictClass()
{
    std::map<uint8_t, int> classFrequency;
    for (int i=0; i<neighbours->size(); ++i)
    {
        if (classFrequency.find(neighbours->at(i)->getLabel()) == classFrequency.end())
        {
            classFrequency[neighbours->at(i)->getLabel()] = 1;
        } else
        {
            ++classFrequency[neighbours->at(i)->getLabel()];
        }  
    }

    int best {0};
    int max  {0};
    for (auto keyValue: classFrequency)
    {
        if(keyValue.second > max)
        {
            max  = keyValue.second;
            best = keyValue.first;
        }
    }

    delete neighbours;
    return best;
}

double KNN::calculateDistance(MNISTData* queryPoint, MNISTData* input)
{
    if (queryPoint->featureVectorSize() != input->featureVectorSize())
    {
        printf("Feature vector size mismatch!");
        exit(1);
    }

    double distance {0.0};
    #ifdef EUCLIDEAN
        for (unsigned i=0; i<queryPoint->featureVectorSize(); ++i)
        {
            distance += pow(queryPoint->getFeatureVector()->at(i) - input->getFeatureVector()->at(i), 2);
        }
        distance = sqrt(distance);
    
    #elif defined MANHATTAN
    // Manhattan implementation here
    #endif

    return distance;
}
double KNN::validateModel()
{
    double currentPerformance {0};
    int count {0};
    int dataIndex {0};
    for (MNISTData* queryPoint: *validationData)
    {
        findKNearest(queryPoint);
        int prediction = predictClass();
        printf("%d -> %d\n", prediction, queryPoint->getLabel());
        if (prediction = queryPoint->getLabel())
        {
            ++count;
        }
        ++dataIndex;
        printf("Current performance = %.3f%%\n", (double{count}*100/double{dataIndex}));
    }
    currentPerformance = double{count}*100/double{validationData->size()};
    printf("Overall validation performance for K=%d: %.3f%%\n", k, currentPerformance);
    return currentPerformance;
}
double KNN::testModel()
{
    double currentPerformance {0};
    int count {0};
    for (MNISTData* queryPoint: *testData)
    {
        findKNearest(queryPoint);
        int prediction = predictClass();
        if (prediction = queryPoint->getLabel())
        {
            ++count;
        }
    }
    currentPerformance = double{count}*100/double{validationData->size()};
    printf("Overall test performance = %.3f%%\n", currentPerformance);
    return currentPerformance;
}

int main()
{
    MNISTDataHandler* dataHandler = new MNISTDataHandler();

    dataHandler->readFeatureVector("data/train-images-idx3-ubyte");
    dataHandler->readLabels("data/train-labels-idx1-ubyte");
    dataHandler->splitData();
    dataHandler->countClasses();

    KNN* knn = new KNN(0);
    knn->setTrainingData(dataHandler->getTrainingData());
    knn->setTestData(dataHandler->getTestData());
    knn->setValidationData(dataHandler->getValidationData());

    double performance {0};
    double bestPeformance {0};
    int bestK {1};
    for (int i=1; i<4; ++i)
    {
        if (i==1)
        {
            knn->setK(i);
            performance = knn->validateModel();
            bestPeformance = performance;
        } else
        {
            knn->setK(i);
            performance = knn->validateModel();
            if (performance>bestPeformance)
            {
                bestPeformance = performance;
                bestK = i;
            }
        }
    }
    knn->setK(bestK);
    printf("Best K: %d\n", bestK);
    knn->testModel();

    return 0;
}