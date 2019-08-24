#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <vector>
using namespace std;

class Matrix {
    public:
        // construction
        Matrix(int numRows, int numCols, bool isRandom);
        double generateRandomNumber();

        Matrix *transpose();

        void setValue(int row, int col, double value);
        double getValue(int row, int col);

        int getNumRows() { return this->numRows; }
        int getNumCols() { return this->numCols; }

        void printToConsole();

    private:
        int numRows;
        int numCols;

        // elements of matrix as vector of vectors
        vector< vector<double> > values;
};

#endif