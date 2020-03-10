#include "ml_models/DNN/network.hpp"

#include "math/matrix.hpp"
#include "math/linearalgebra.hpp"
#include "data_processing/XOR/XOR_preprocessor.hpp"
#include "data_processing/MNIST/mnist_data.hpp"
#include "data_processing/MNIST/mnist_data_handler.hpp"

#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
    /*
    TODO/RULES:
    - consts where possible and const qualified functions
    - function templates/functionals
    - prefer pass classes by reference whenever possible
    - Rule: Do not copy initialize your classes
    */

   if(argc<=1)
   {
       cout <<"Usage: dnn EXAMPLE"<<endl
            <<"Current available examples:"<<endl
            <<"XOR"<<endl
            <<"MNIST"<<endl;
   } else
   {
          printf("ScratchNet");

        /* Get training data and network parameters */
        vector<vector<vector<double>>> trainingData;
        vector<int> layerSizes;

        if(!strcmp(argv[1], "XOR"))
        {
            XORPreprocessor trainingClass("./data/XOR_train.txt"); 
            const int inputLayerSize  = trainingClass.getInputSize();
            const int outputLayerSize = trainingClass.getOutputSize();
            trainingData = trainingClass.getTrainingData();
            layerSizes = {inputLayerSize, 5, outputLayerSize};
        }
        else if (!strcmp(argv[1], "MNIST"))
        {
            MNISTDataHandler dataHandler{MNISTDataHandler()};
            dataHandler.readFeatureVector("data/train-images-idx3-ubyte");
            dataHandler.readLabels("data/train-labels-idx1-ubyte");
            dataHandler.splitData();
            dataHandler.countClasses();
            trainingData.resize(dataHandler.getTrainingData().size());
            for (int i=0; i<dataHandler.getTrainingData().size(); ++i)
            {
                vector<vector<double>> currentSample
                {
                    dataHandler.getTrainingData().at(i).getFeatureVector(),
                    dataHandler.getTrainingData().at(i).getClassVector()
                };
                trainingData.at(i) = currentSample;
            }
            layerSizes = {784, 32, 10};
        }
        
        /* Initialize network, then train */
        Network neuralNetwork {Network(layerSizes)};
        neuralNetwork.train(trainingData);
    }

    return 0;
}
