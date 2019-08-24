#include <iostream>
#include "../include/neuron.hpp"
using namespace std;

int main() {
    Neuron *n = new Neuron(20);

    cout << "val " << n->getVal() << endl;
    cout << "activatedVal " << n->getActivatedVal() << endl;
    cout << "derivedVal " << n->getDerivedVal() << endl;

    return 0;
}
