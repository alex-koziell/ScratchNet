#ifndef MATRIX_H
#define MATRIX_H

#include "numerical.hpp"

#include <iostream>
#include <iomanip>
#include <vector>

namespace linalg
{
    using namespace std;

    template <class T>
    class Matrix
    {
        /* NOTE: randomize() currently only expected to work with matrices of doubles. */

        public:
            // CONSTRUCTOR
            Matrix(const int numRows, const int numCols, bool random=false)
            {
                m_numRows = numRows;
                m_numCols = numCols;
                m_size    = m_numRows * m_numCols;
                m_values.resize(m_size); // Elements are initialized to default class type (0 for int).
                if (random)
                {
                    randomize();
                }
            }

            // MATRIX PROPERTIES AND ACCESSOR FUNCTIONS
            T& operator() (const int i, const int j) { return m_values[i*m_numCols + j]; } // Element at row i-1 and column j-1.
            
            vector<int> shape() const // Matrix dimensions.
            { 
                const vector<int> shape {m_numRows, m_numCols};
                return shape; 
            }

            int numRows() const { return m_numRows; }
            int numCols() const { return m_numCols; }
            
            int size()  { return m_size; } // Number of elements in the array.

            vector<T>& getValues() { return m_values; }

            // WHOLE-MATRIX OPERATIONS (transpose, randomize)
            Matrix<T> transpose()
            {
                Matrix<T> MT(m_numCols, m_numRows);
                for (int i=0; i<m_numRows; ++i)
                {
                    for (int j=0; j<m_numCols; ++j)
                    {
                        MT(j,i) = operator() (i,j);
                    }
                }
                return MT;
            }

            void randomize()
            {
                for (int i=0; i<m_numRows; ++i)
                {
                    for (int j=0; j<m_numCols; ++j)
                    {
                        operator() (i,j) = numerical::randomDouble();
                    }
                }
            }

            void print()
            {
                for (int i=0; i<m_numRows; ++i)
                {
                    cout << ((i==0) ? "/  " : ((i+1==m_numRows) ? "\\  " : "|  "));
                    for (int j=0; j<m_numCols; ++j)
                    {
                        cout << scientific << setprecision(2) << operator() (i,j) << "  ";
                    }
                    cout << ((i==0) ? "\\" : ((i+1==m_numRows) ? "/" : "|")) << endl;
                }
                cout << endl;
            }


        private:
            int m_numRows;
            int m_numCols;
            int m_size;
            vector<T> m_values;
    };
}

#endif