#ifndef _LINEAR_ALGEBRA_HPP_
#define _LINEAR_ALGEBRA_HPP_

#include <iostream>
#include <vector>
#include <assert.h>

#include "../matrix.hpp"

namespace linalg
{
    double generateRandomNumber();

    Matrix multiplyMatrices(Matrix &A, Matrix &B);
    std::vector<double> matrixVectorProduct(Matrix &A, std::vector<double> &v);
    double dotProduct(std::vector<double> &v, std::vector<double>);
    std::vector<double> hadamardProduct(std::vector<double> &v, std::vector<double> &u);

    Matrix transposeMatrix(Matrix &M); // Returns the matrix transpose.

    void printToConsole(vector<double> &v);
}

#endif