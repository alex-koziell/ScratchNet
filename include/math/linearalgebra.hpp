#ifndef LINALG_H
#define LINALG_H

#include "./matrix.hpp"

#include <assert.h>


using namespace std;
using namespace linalg;

template <typename T>
vector<T> operator+(const vector<T> &v, const vector<T> &u)
{
    /*
    Standard vector addition as defined for Cartesian product vectors.
    v + u = w
    */

    if (v.size() != u.size())
    {
        cerr << "Vector v is of size   " << v.size() << endl
        << "...but vector u is of size " << u.size() << "!" << endl;
        assert(false);
    }

    vector<T> w;
    for (int i=0; i<v.size(); ++i)
    {
        w.push_back( v.at(i) + u.at(i) );
    }
    return w;
}

template <typename T>
void operator+=(vector<T> &v, const vector<T> &u)
{
    /*
    Standard vector addition as defined for Cartesian product vectors.
    v += w
    */
    
    if (v.size() != u.size())
    {
        cerr << "Vector v is of size   " << v.size() << endl
        << "...but vector u is of size " << u.size() << "!" << endl;
        assert(false);
    }

    for (int i=0; i<v.size(); ++i)
    {
        v.at(i) += u.at(i);
    }
}

template <typename T>
Matrix<T> operator* (Matrix<T> &A, Matrix<T> &B)
{
    /*
    Multiplies two matrices using the iterative (naive) algorithm.
    */

    Matrix<T> C(A.shape()[0], B.shape()[1]);
    for (int i=0; i<A.shape()[0]; ++i)     // for each row of A
    {
        for (int j=0; j<B.shape()[1]; ++j) // for each column of B
        {
            for (int k=0; k<A.shape()[1]; ++k)
            {
                C(i,j) += A(i,k) * B(k,j);
            }
        }
    }
    return C;
}

template <typename T>
vector<T> operator* (Matrix<T> &A, vector<T> &v)
{
    /*
    Multiplys a matrix A with a vector v to return a vector u.
    Av = u
    */

    // check dimensions are correct
    if (A.shape()[1] != v.size())
    {
        cerr << "Matrix A is of dimensions (" << A.shape()[0] << "," << A.shape()[1] << ")," << endl
        << "...but vector v is of size " << v.size() << "!" << endl;
        assert(false);
    }

    vector<T> u;
    for (int i=0; i<A.shape()[0]; ++i)
    {
        T u_i {};
        for (int j=0; j<A.shape()[1]; ++j)
        {
            u_i += A(i,j) * v.at(j);
        }
        u.push_back(u_i);
    }
    return u;
}

namespace linalg
{
    template <typename T>
    vector<T> hadamardProduct (vector<T> &u, vector<T> &v)
    {
        /*
        Computes the Hadamard Product (element-wise multiplication)
        of two vectors v and u, to give a vector w.
        */
        if (v.size() != u.size())
        {
            cerr << "Vector v is of size   " << v.size() << endl
            << "...but vector u is of size " << u.size() << "!" << endl;
            assert(false);
        }

        vector<T> w;
        for (int i=0; i<v.size(); ++i)
        {
            w.push_back( v.at(i) * u.at(i) );
        }
        return w;
    }

    template <typename T>
    void print(vector<T> &v) {
    /*
    Prints a vector to the console.
    */
    
    cout << "[ ";
    for (int i=0; i<v.size(); ++i)
    {
        cout << setprecision(2) << v.at(i);
        if (i==v.size()-1)
            cout << " ";
        else
            cout << ", ";
    }
    cout << "]" << endl;
    }
}

// the following need to be declared at global scope
// https://stackoverflow.com/questions/14420209/overloading-operators-for-vectordouble-class

#endif