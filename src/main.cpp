#include "network.hpp"

#include "math/matrix.h"
#include "math/linearalgebra.h"
#include "preprocessing/preprocessor.hpp"
#include "MNIST/mnist_data.hpp"
#include "MNIST/mnist_data_handler.hpp"

#include "tests/test_linearalgebra.cpp"
#include "tests/test_preprocessor.cpp"

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    /*
    TODO/RULES:
    - consts where possible and const qualified functions
    - function templates/functionals
    - prefer pass classes by reference whenever possible
    - Rule: Do not copy initialize your classes
    */

   printf("ScratchNet");

    // /* Get training data */
    // Preprocessor trainingClass("./data/XOR_train.txt"); 
    // const int inputLayerSize  = trainingClass.getInputSize();
    // const int outputLayerSize = trainingClass.getOutputSize();
    // vector<vector<vector<double>>> trainingData { trainingClass.getTrainingData() };

    MNISTDataHandler dataHandler{MNISTDataHandler()};

    dataHandler.readFeatureVector("data/train-images-idx3-ubyte");
    dataHandler.readLabels("data/train-labels-idx1-ubyte");
    dataHandler.splitData();
    dataHandler.countClasses();

    cout << "Preproccessing Training Data for Network" << endl;
    vector<vector<vector<double>>> trainingData(dataHandler.getTrainingData().size());
    for (int i=0; i<dataHandler.getTrainingData().size(); ++i)
    {
        vector<vector<double>> currentSample
        {
        dataHandler.getTrainingData().at(i).getFeatureVector(),
        dataHandler.getTrainingData().at(i).getClassVector()
        };
        trainingData.at(i) = currentSample;
    }

    /* Initialize network, then train */
    cout << "Training Network for " << dataHandler.getClassCounts() << " classes." << endl;
    vector<int> layerSizes {784, 64, 64, dataHandler.getClassCounts()};
    Network neuralNetwork {Network(layerSizes)};
    neuralNetwork.train(trainingData);


    /* ---------------TESTS/DEBUG---------------*/

    // /* Linear algebra tests */
    // test_matrixMultiplication();
    // test_matrixVectorMultiplication();
    // test_transposeMatrix();
    // test_hadamardProduct();

    // /* Preprocessor test */
    // test_preprocessor();

    /*------------------------------------------*/

    return 0;
}
