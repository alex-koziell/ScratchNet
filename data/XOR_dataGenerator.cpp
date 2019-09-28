#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    /*
    Generates XOR training data in the following format (where first line in file is line 0):
        input and output layer sizes
        odd lines  inputs
        even lines outputs
    All values on each line are delimited by spaces.
    Compile and run to generate a text file of data.
    */

    ofstream outFile("data/XOR_train.txt");

    outFile << "2 1" << endl; // input and output layer sizes

    for (int i=0; i<5000; ++i) // generate 2000 training samples
    {
        int a { round( rand()/double(RAND_MAX)) };
        int b { round( rand()/double(RAND_MAX)) };

        int c = a^b; // a XOR b

        outFile << a << ".0 " << b << ".0" << endl;
        outFile << c << ".0" << endl;
    }

    return 0;
}