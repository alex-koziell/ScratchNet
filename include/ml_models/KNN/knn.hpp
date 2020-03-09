#ifndef KNN_HPP
#define KNN_HPP

#include "common.hpp"
#include "MNIST/mnist_data.hpp"
#include <vector>

class KNN : public commonData {
    private:
        int k;
        std::vector<MNISTData*>* neighbours;
        double distance;
        
    public:
        KNN(int initialK);

        void findKNearest(MNISTData* queryPoint);
        void setK(int value);

        int predictClass();
        double calculateDistance(MNISTData* queryPoint, MNISTData* input);
        double getDistance();
        double validateModel();
        double testModel();
};

#endif