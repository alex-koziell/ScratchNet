#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <vector>
using namespace std;

class Matrix {
    /*
    A 2-dimensional vector of doubles, with the ability to be initialized with either zeros
    or random double from the half-open interval [0,1).
    Unless specified otherwise, we will denote row indices by the letter 'i', and column
    indices by 'j'.
    */

    public:
        Matrix(int numRows, int numCols, bool isRandom);
        double generateRandomNumber();

        Matrix* transpose(); // Returns the matrix transpose.

        /*
        These are most likely the simplest and most computationally efficient way to set and get
        values, so the implementations of these two functions are defined in the header file.
        */
        void   setValue(int row, int col, double value) { this->values.at(row).at(col) = value; }
        double getValue(int row, int col)               { return this->values.at(row).at(col); }

        int getNumRows() { return this->numRows; }
        int getNumCols() { return this->numCols; }

        void printToConsole();

    private:
        int numRows;
        int numCols;

        vector< vector<double> > values; // The entries of the matrix, stored as a multi-dimensional vector.
};

#endif