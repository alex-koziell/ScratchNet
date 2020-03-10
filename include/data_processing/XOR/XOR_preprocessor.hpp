#ifndef _PREPROCESSOR_HPP_
#define _PREPROCESSOR_HPP_

#include <string>
#include <vector>

using namespace std;

class XORPreprocessor
{
    public:
        XORPreprocessor(string filePath);
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