#ifndef _LINEAR_ALGEBRA_HPP_
#define _LINEAR_ALGEBRA_HPP_

#include <iostream>
#include <vector>
#include <assert.h>

#include "../matrix.hpp"

using namespace std;

/*
Idea: create a class that performs the desired function
i.e. an object-oriented function approach.
*/

namespace linalg
{
    Matrix multiplyMatrices(Matrix &A, Matrix &B);
}

#endif