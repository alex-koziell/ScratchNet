#include "KMeans/kmeans.hpp"
#include "MNIST/mnist_data_handler.hpp"

int main()
{
    MNISTDataHandler* dataHandler = new MNISTDataHandler();

    dataHandler->readFeatureVector("data/train-images-idx3-ubyte");
    dataHandler->readLabels("data/train-labels-idx1-ubyte");
    dataHandler->splitData();
    dataHandler->countClasses();
    double performance {0.0};
    double bestPerformance {0.0};
    int bestK {1};

    for (int k=dataHandler->getClassCounts(); k<dataHandler->getTrainingData()->size()*0.1; ++k)
    {
        KMeans *kmeans = new KMeans(k);
        kmeans->setTrainingData(dataHandler->getTrainingData());
        kmeans->setTestData(dataHandler->getTestData());
        kmeans->setValidationData(dataHandler->getValidationData());

        
        kmeans->initClusters();
        kmeans->train();
        performance = kmeans->validate();
        if (performance>bestPerformance)
        {
            bestPerformance = performance;
            bestK = k;
        }
    }

    KMeans *kmeans = new KMeans(bestK);
    kmeans->setTrainingData(dataHandler->getTrainingData());
    kmeans->setTestData(dataHandler->getTestData());
    kmeans->setValidationData(dataHandler->getValidationData());

    kmeans->initClusters();
    kmeans->train();
    performance = kmeans->test();

    return 0;
}
