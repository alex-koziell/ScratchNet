#ifndef _LINEAR_ALGEBRA_HPP_
#define _LINEAR_ALGEBRA_HPP_

#include <iostream>
#include <vector>
#include <assert.h>

#include "../matrix.hpp"

/*
Idea: create a class that performs the desired function
i.e. an object-oriented function approach.
*/

namespace linalg
{
    Matrix multiplyMatrices(Matrix &A, Matrix &B);
    std::vector<double> matrixVectorProduct(Matrix &A, std::vector<double> &v);
    double dotProduct(std::vector<double> &v, std::vector<double>);

    Matrix transposeMatrix(Matrix &M); // Returns the matrix transpose.

    void printToConsole(vector<double> &v);
}

#endif