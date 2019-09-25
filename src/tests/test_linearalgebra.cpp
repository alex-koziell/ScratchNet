#include "../../include/matrix.hpp"
#include "../../include/utils/linearalgebra.hpp"

#include <vector>

using namespace std;

void test_multiplyMatrices()
{
    /*
    Matrix Multiplication Test
    */
    Matrix A = Matrix(1, 2, true);
    Matrix B = Matrix(2, 3, true);

    Matrix C = linalg::multiplyMatrices(A, B);

    cout << "Matrix A:" << endl;
    A.printToConsole();
    cout << endl << "Matrix B:" << endl;
    B.printToConsole();
    cout << endl << "Matrix C = AB:" << endl;
    C.printToConsole();
    cout << endl;

}

void test_transposeMatrix() {
    /*
    Matrix Transpose Test 
    */
    
    cout << "Matrix M:" << endl;
    Matrix M = Matrix(3, 3, true);
    M.printToConsole();
    cout << endl << "M tranposed:" << endl;
    Matrix MT = linalg::transposeMatrix(M);
    MT.printToConsole();
    cout << endl;

}

