#include "KNN/knn.hpp"
#include "MNIST/mnist_data_handler.hpp"

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