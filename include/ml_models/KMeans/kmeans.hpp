#ifndef KMEANS_HPP
#define KMEANS_HPP

#include "common.hpp"
#include "MNIST/mnist_data_handler.hpp"

#include <cmath>
#include <cstdlib>
#include <limits>
#include <map>
#include <unordered_set>

typedef struct cluster
{
    std::vector<double>* centroid;
    std::vector<MNISTData*>* clusterPoints;
    std::map<int, int> classCounts;
    int modalClass;

    cluster(MNISTData* initialPoint)
    {
        centroid = new std::vector<double>;
        clusterPoints = new std::vector<MNISTData*>;

        for (auto value : *(initialPoint->getFeatureVector()))
        {
            centroid->push_back(value);
        }
        clusterPoints->push_back(initialPoint);
        classCounts[initialPoint->getLabel()] = 1;
        modalClass = initialPoint->getLabel();
    }

    void addToCluster(MNISTData* newPoint)
    {
        int previousSize { clusterPoints->size() };
        clusterPoints->push_back(newPoint);
        for (int i=0; i<centroid->size(); ++i)
        {
            double value { centroid->at(i) };
            value *= previousSize;
            value += newPoint->getFeatureVector()->at(i);
            value /= double { clusterPoints->size() };
            centroid->at(i) = value;
        }
        if (classCounts.find(newPoint->getLabel()) == classCounts.end())
        {
            classCounts[newPoint->getLabel()] = 1;
        } else 
        {
            ++classCounts[newPoint->getLabel()];
        }
        setModalClass();
    }

    void setModalClass()
    {
        int bestClass;
        int frequency {0};
        for (auto keyValue : classCounts)
        {
            if (keyValue.second > frequency)
            {
                frequency = keyValue.second;
                bestClass = keyValue.first;
            }
        }
        modalClass = bestClass;
    }


} cluster_t;

class KMeans : public commonData
{
    private:    
        int numClusters;
        std::vector<cluster*>* m_clusters;
        std::unordered_set<int>* usedIndices;

    public:
        KMeans(int k);

        void initClusters();
        void initClustersForEachClass();
        void train();
        double euclideanDistance(std::vector<double>*, MNISTData*);
        double validate();
        double test();
};

#endif