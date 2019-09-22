#ifndef _MULTIPLY_MATRICES_HPP_
#define _MULTIPLY_MATRICES_HPP_

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
    class MultiplyMatrices
    /* 
    Performs matrix multiplication in the order ab to output matrix C:
    AB = C
    */
   
    {
        public:
            MultiplyMatrices(Matrix *A, Matrix *B);

            Matrix* execute();

        private:
            Matrix *A;
            Matrix *B;
            Matrix *C;

    };
}

#endif