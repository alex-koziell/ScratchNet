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

        Matrix transpose(); // Returns the matrix transpose.

        void   setValue(int row, int col, double value) { m_values.at(row).at(col) = value; }
        double getValue(int row, int col)               { return m_values.at(row).at(col);  }

        int getNumRows() { return m_numRows; }
        int getNumCols() { return m_numCols; }

        void printToConsole();

    private:
        int m_numRows;
        int m_numCols;

        vector<vector<double>> m_values; // The entries of the matrix, stored as a multi-dimensional vector.
};

#endif