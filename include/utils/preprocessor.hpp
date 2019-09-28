#ifndef _PREPROCESSOR_HPP_
#define _PREPROCESSOR_HPP_

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Preprocessor
{
    public:
        Preprocessor(string filePath);
        vector<vector<vector<double>>> getTrainingData() { return m_data; };
        int getInputSize()  { return m_inputSize;  }
        int getOutputSize() { return m_outputSize; }

    private:
        vector<vector<vector<double>>> m_data;
        int m_inputSize;
        int m_outputSize;
        vector<double> createLayerVector(string values);
};

#endif