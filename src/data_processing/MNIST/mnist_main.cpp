#include "MNIST/mnist_data_handler.hpp"

int main()
{
    MNISTDataHandler *dataHandler = new MNISTDataHandler();
    dataHandler->readFeatureVector("data/train-images-idx3-ubyte");
    dataHandler->readLabels("data/train-labels-idx1-ubyte");
    dataHandler->splitData();
    dataHandler->countClasses();

    return 0;
}