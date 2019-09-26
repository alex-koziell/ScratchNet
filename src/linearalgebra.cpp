#include "../include/utils/linearalgebra.hpp"

#include <iomanip>

using namespace std;

Matrix linalg::multiplyMatrices(Matrix &A, Matrix &B)
{
    /*
    Multiplies two matrices in the order AB to return a matrix C
    AB = C
    */

    // Check that the matrix dimensions allow matrix multiplication to actually be carried out.
    if(A.getNumCols() != B.getNumRows())
    {
        cerr << "Matrix A is of dimensions (" << A.getNumRows() << "," << A.getNumCols() << ")," << endl
             << "...but B is of dimensions (" << B.getNumRows() << "," << B.getNumCols() << ")!" << endl;
        assert(false);
    }

    Matrix C{A.getNumRows(), B.getNumCols(), false};

   for (int i=0; i < A.getNumRows(); ++i)          // row i in matrix A
   {
       for (int j=0; j < B.getNumCols(); ++j)      // column j in matrix B
       {
           double C_ij = 0;                         // entry i,j in matrix C
           for (int k=0; k < A.getNumCols(); ++k)
           {
               C_ij += A.getValue(i, k)      // Perform the dot product of the row vector i in A
                     * B.getValue(k, j);     // with column vector j in B
           }
           C.setValue(i, j, C_ij);           // Assign the computed dot product to entry i,j of C
        }
    }

   return C;
}

vector<double> linalg::matrixVectorProduct(Matrix &A, vector<double> &v)
{
    /*
    Multiplys a matrix A with a vector v to return a vector u.
    Av = u
    */

    // check dimensions are correct
    if (A.getNumCols() != v.size())
    {
        cerr << "Matrix A is of dimensions (" << A.getNumRows() << "," << A.getNumCols() << ")," << endl
        << "...but vector v is of size " << v.size() << "!" << endl;
        assert(false);
    }

    vector<double> u;

    for (int i=0; i<A.getNumRows(); ++i)
    {
        double u_i = 0;
        for (int j=0; j<A.getNumCols(); ++j)
        {
            u_i += A.getValue(i,j) * v.at(j);
        }
        u.push_back(u_i);
    }

    return u;
}

vector<double> linalg::hadamardProduct(vector<double> &v, vector<double> &u)
{
    /*
    Computes the Hadamard Product (element-wise multiplication)
    of two vectors v and u, to give a vector w.
    */

    // check dimensions are correct
    if (v.size() != u.size())
    {
        cerr << "Vector v is of size   " << v.size() << endl
        << "...but vector u is of size " << u.size() << "!" << endl;
        assert(false);
    }


   vector<double> w;

    for (int i=0; i<v.size(); ++i)
    {
        w.push_back( v.at(i) * u.at(i) ); // Hadamard Product
    }

    return w;
}

Matrix linalg::transposeMatrix(Matrix &M)
{
    /*
    Returns the transpose of this instance of the matrix.
    */

    Matrix transposedMatrix{M.getNumCols(), M.getNumRows(), false};

    for (int i=0; i<M.getNumRows(); ++i)
    {
        for (int j=0; j<M.getNumCols(); ++j)
        {
            transposedMatrix.setValue(j, i, M.getValue(i,j));
        }
    }

    return transposedMatrix;
}

void linalg::printToConsole(vector<double> &v) {
    /*
    Prints a vector to the console.
    */
    
    cout << setw(15) << "[ ";
    for (int i=0; i<v.size(); ++i)
    {
        cout << setprecision(3) << v.at(i);
        if (i==v.size()-1)
            cout << " ";
        else
            cout << ", " << setw(5);
    }
    cout << "]" << endl;

}