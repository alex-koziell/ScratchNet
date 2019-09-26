#include "../include/matrix.hpp"
#include "../include/utils/linearalgebra.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Matrix::Matrix(int numRows, int numCols, bool isRandom) {
    m_numRows = numRows;
    m_numCols = numCols;

    // for each row and each column, initialize the matrix either 0s or
    // random doubles in [0, 1)
    for (int i=0; i<numRows; ++i)
    {
        vector<double> colValues;
        for (int j=0; j<numCols; ++j)
        {
            double newValue = 0.00;
            if(isRandom)
            {
                newValue = linalg::generateRandomNumber();
            }
            colValues.push_back(newValue);
        }
       m_values.push_back(colValues);
    }
}

void Matrix::printToConsole() {
    /*
    Prints the matrix to the console.
    */

    for (int i=0; i<m_numRows; ++i)
    {
        for (int j=0; j<m_numCols; ++j)
        {
            cout << setw(15) << setprecision(5) << m_values.at(i).at(j); // TODO: improve formatting to center matrices with arbitrary number of columns
        }
        cout << endl;
    }

}
