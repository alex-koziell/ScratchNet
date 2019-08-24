#include <iostream>
#include "../include/neuron.hpp"
#include "../include/matrix.hpp"

using namespace std;

int main() {
    cout << "Am I working?" << endl << endl; 

    Neuron *n = new Neuron(20);

    cout << "val " << n->getVal() << endl;
    cout << "activatedVal " << n->getActivatedVal() << endl;
    cout << "derivedVal " << n->getDerivedVal() << endl << endl;

    Matrix *m = new Matrix(3, 3, true);
    m->printToConsole();

    return 0;
}
