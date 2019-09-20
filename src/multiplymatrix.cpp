#include "../include/utils/multiplymatrix.hpp"

using namespace std;

utils::MultiplyMatrix::MultiplyMatrix(Matrix *a, Matrix *b) {
    this->a = a;
    this->b = b;

    // Check that we can actually multiply the input matrices in the order ab
    if(a->getNumCols() != b->getNumRows())
    {
        cerr << "Matrix A is of dimensions (" << a->getNumRows() << "," << a->getNumCols() << ")," << endl
             << "...but B is of dimensions (" << a->getNumRows() << "," << a->getNumCols() << ")!" << endl;
        assert(false);
    }

    this->c = new Matrix(a->getNumRows(), b->getNumCols(), false);
}

Matrix* utils::MultiplyMatrix::execute() {
    /*
    Brute force matrix multiplication implementation
    ...to be refined (if necessary) after I've studied some more numerical analysis
    20/Sep/2019
    */
   for (int i=0; i < a->getNumRows(); i++)
   { // for each row in a
       for (int j=0; j < b->getNumCols(); j++)
       { // for each column in b
           double c_ij = 0; // placeholder for entry ij of our output matrix c
           for (int k=0; k < a->getNumCols(); k++)
           { // for each entry in the current row of a
               c_ij += this->a->getValue(i, k) * this->b->getValue(k, j); // multiply by the corresponding entry of b and add to the placeholder c_ij
           }
           this->c->setValue(i, j, c_ij); // set entry i,j of c to its computed value
        }
    }

   return this->c;
}