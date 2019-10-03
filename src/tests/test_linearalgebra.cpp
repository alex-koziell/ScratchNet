#include "../../include/math/matrix.h"
#include "../../include/math/linearalgebra.h"

#include <vector>

using namespace std;

void test_transposeMatrix()
{
    /*
    Matrix transposition test.
    */
    cout << endl << "Matrix A:" << endl;
    linalg::Matrix<double> A(3,3,true);
    A.print();
    cout << endl << "A transpose:" << endl;
    linalg::Matrix<double> AT = A.transpose();
    AT.print();
    cout << endl;
}

void test_matrixMultiplication()
{
    /*
    Matrix multiplication test
    */
    linalg::Matrix<double> A {1, 2, true};
    linalg::Matrix<double> B {2, 3, true};

    linalg::Matrix<double> C = A*B;

    cout << "Matrix A:" << endl;
    A.print();
    cout << endl << "Matrix B:" << endl;
    B.print();
    cout << endl << "Matrix C = AB:" << endl;
    C.print();
    cout << endl;
}

void test_matrixVectorMultiplication()
{
    /*
    Matrix-vector multiplication test.
    */
    linalg::Matrix<double> A(3,3,true);
    vector<double> v {1, 2, 3};

    vector<double> u {A*v};

    cout<<"Matrix A:"<<endl;
    A.print();
    cout<<"times vector v:"<<endl;
    linalg::print(v);
    cout<<"equals vector u:"<<endl;
    linalg::print(u);
    cout<<endl;
}

void test_hadamardProduct()
{
    vector<double> v {1, 2, 3};
    vector<double> u {4, 5, 6};

    vector<double> w = linalg::hadamardProduct(v, u);
    
    cout<<"Vector v:"<<endl;
    linalg::print(v);
    cout<<"Hadamard Product with vector u:"<<endl;
    linalg::print(u);
    cout<<"equals vector w:"<<endl;
    linalg::print(w);
    cout<<endl;
}
