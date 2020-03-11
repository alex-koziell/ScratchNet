# ScratchNet
A neural network from scratch to improve C++ skills and develop an intuition for backpropagation.

## Linux Instructions using Terminal
In ScratchNet directory:

1. `cmake .`  
2. `make`  
3. and then run either:  
 `apps/dnn XOR`  
 or  
`apps/dnn MNIST`  

The network output, targets and errors are given. Currently MNIST requires some parameter tuning and implemenetation of softmax to perform better, but the backprop seems to work.
