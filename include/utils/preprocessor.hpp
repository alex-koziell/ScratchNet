#ifndef _PREPROCESSOR_HPP_
#define _PREPROCESSOR_HPP_

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Preprocessor
{
    public:
        Preprocessor(string filePath);
        void readData();
        vector<vector<vector<double>>> createData();

    private:
        const string m_FILEPATH;
        vector<vector<double>> m_inputData;
        vector<vector<double>> m_targetData;
};

#endif