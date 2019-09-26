#include "../../include/matrix.hpp"
#include "../../include/utils/linearalgebra.hpp"

#include <vector>

using namespace std;

void test_multiplyMatrices()
{
    /*
    Matrix Multiplication Test
    */
    Matrix A {1, 2, true};
    Matrix B {2, 3, true};

    Matrix C = linalg::multiplyMatrices(A, B);

    cout << "Matrix A:" << endl;
    A.printToConsole();
    cout << endl << "Matrix B:" << endl;
    B.printToConsole();
    cout << endl << "Matrix C = AB:" << endl;
    C.printToConsole();
    cout << endl;

}

void test_matrixVectorProduct()
{
    /*
    Matrix-vector multiplication test.
    */

    vector<double> v {1, 2, 3};
    Matrix A {3, 3, true};
    vector<double> u {linalg::matrixVectorProduct(A, v)};

    cout<<"Matrix A:"<<endl;
    A.printToConsole();
    cout<<"times vector v:"<<endl;
    linalg::printToConsole(v);
    cout<<"equals vector u:"<<endl;
    linalg::printToConsole(u);

}

void test_hadamardProduct()
{
    vector<double> v {1, 2, 3};
    vector<double> u {4, 5, 6};

    vector<double> w = linalg::hadamardProduct(v, u);
    
    cout<<"Vector v:"<<endl;
    linalg::printToConsole(v);
    cout<<"Hadamard Product with vector u:"<<endl;
    linalg::printToConsole(u);
    cout<<"equals vector w:"<<endl;
    linalg::printToConsole(w);
}

void test_transposeMatrix()
{
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

