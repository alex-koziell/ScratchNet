#ifndef _MULTIPLY_MATRIX_HPP_
#define _MULTIPLY_MATRIX_HPP_

#include <iostream>
#include <vector>
#include <assert.h>

#include "../matrix.hpp"

using namespace std;

/*
Idea: create a class that performs the desired function
i.e. an object-oriented function approach.
*/

namespace utils
{
    class MultiplyMatrix
    /* 
    Performs matrix multiplication in the order ab to output matrix c:
    ab = c
    */
   
    {
        public:
            MultiplyMatrix(Matrix *a, Matrix *b);

            Matrix *execute();

        private:
            Matrix *a;
            Matrix *b;
            Matrix *c;

    };
}

#endif