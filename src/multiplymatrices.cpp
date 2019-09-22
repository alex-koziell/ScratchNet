#include "../include/utils/multiplymatrices.hpp"

using namespace std;

utils::MultiplyMatrices::MultiplyMatrices(Matrix *A, Matrix *B) {
    this->A = A;
    this->B = B;

    // Check that the matrix dimensions allow matrix multiplication to actually be carried out.
    if(A->getNumCols() != B->getNumRows())
    {
        cerr << "Matrix A is of dimensions (" << A->getNumRows() << "," << A->getNumCols() << ")," << endl
             << "...but B is of dimensions (" << B->getNumRows() << "," << B->getNumCols() << ")!" << endl;
        assert(false);
    }

    this->C = new Matrix(A->getNumRows(), B->getNumCols(), false);
}

Matrix* utils::MultiplyMatrices::execute() {
    /*
    Brute force matrix multiplication implementation
    ...to be refined (if necessary) after I've studied some more numerical analysis
    20/Sep/2019
    */

   for (int i=0; i < A->getNumRows(); i++)          // row i in matrix A
   {
       for (int j=0; j < B->getNumCols(); j++)      // column j in matrix B
       {
           double C_ij = 0;                         // entry i,j in matrix C
           for (int k=0; k < A->getNumCols(); k++)
           {
               C_ij += this->A->getValue(i, k)      // Perform the dot product of the row vector i in A
                     * this->B->getValue(k, j);     // with column vector j in B
           }
           this->C->setValue(i, j, C_ij);           // Assign the computed dot product to entry i,j of C
        }
    }

   return this->C;
}