#include "../../include/utils/preprocessor.hpp"

void test_preprocessor()
{
    Preprocessor trainingClass = Preprocessor("./data/XOR_train.txt"); 
    const int inputLayerSize = trainingClass.getInputSize();
    const int outputLayerSize = trainingClass.getOutputSize();

    vector<vector<vector<double>>> trainingData = trainingClass.getTrainingData();

    for (vector<vector<double>> trainingSample : trainingData)
    {
        vector<double> input {trainingSample.at(0)};
        vector<double> output {trainingSample.at(1)};
        cout << "input values: ";
        for (double inputval : input)
        {
            cout << inputval << " ";
        }
        cout << endl;
        cout << "ouput value: ";
        for (double outputval : output)
        {
            cout << outputval << " ";
        }
        cout << endl;
    }
}