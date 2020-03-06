#include "common.hpp"
#include "KMeans/kmeans.hpp"
#include "MNIST/mnist_data_handler.hpp"

#include <cmath>
#include <cstdlib>
#include <limits>
#include <map>
#include <unordered_set>

KMeans::KMeans(int k)
{
    numClusters = k;
    printf("%d", numClusters);
    m_clusters = new std::vector<cluster_t*>;
    usedIndices = new std::unordered_set<int>;
}

void KMeans::initClusters()
{
    printf("%d", numClusters);
    for (int i=0; i<numClusters; ++i)
    {
        int index { rand() % trainingData->size() };
        while (usedIndices->find(index) != usedIndices->end())
        {
            index =  rand() % trainingData->size();
        }
        m_clusters->push_back(new cluster_t(trainingData->at(index)));
        usedIndices->insert(index);    
    }
}

void KMeans::initClustersForEachClass()
{
    std::unordered_set<int> usedClasses;
    for (int i=0; i<trainingData->size(); ++i)
    {
        if (usedClasses.find(trainingData->at(i)->getLabel()) == usedClasses.end())
        {
            m_clusters->push_back(new cluster_t(trainingData->at(i)));
            usedClasses.insert(trainingData->at(i)->getLabel());
            usedIndices->insert(i);
        }
    }
}

void KMeans::train()
{
    while (usedIndices->size() < trainingData->size() )
    {
        int index { rand() % trainingData->size() };
        while (usedIndices->find(index) != usedIndices->end())
        {
            index = rand() % trainingData->size();
        }
        double minDistance { std::numeric_limits<double>::max() };
        int bestCluster {0};
        for (int i=0; i<m_clusters->size(); ++i)
        {
            double currentDistance {euclideanDistance(m_clusters->at(i)->centroid, trainingData->at(index))};
            if (currentDistance < minDistance)
            {
                minDistance = currentDistance;
                bestCluster = i;
            }
        }
        m_clusters->at(bestCluster)->addToCluster(trainingData->at(index));
        usedIndices->insert(index);
    }
    
}

double KMeans::euclideanDistance(std::vector<double>* centroid, MNISTData* dataPoint)
{
    double distance {0.0};
    for (int i=0; i<centroid->size(); ++i)
    {
        distance += pow(centroid->at(i)-dataPoint->getFeatureVector()->at(i), 2);
    }
    return sqrt(distance);
}

double KMeans::validate()
{
    int correctPredictions {0};
    for (auto queryPoint : *validationData)
    {
        double minDistance { std::numeric_limits<double>::max() };
        int bestCluster {0};
        for (int i=0; i<m_clusters->size(); ++i)
        {
            double currentDistance {euclideanDistance(m_clusters->at(i)->centroid, queryPoint)};
            if (currentDistance < minDistance)
            {
                minDistance = currentDistance;
                bestCluster = i;
            }
        }
        if (m_clusters->at(bestCluster)->modalClass == queryPoint->getLabel()) ++correctPredictions;
    }
    double performance {100.0*(correctPredictions/validationData->size())};
    printf("Performance at K = %d: %.3f%%", numClusters, performance);
    return performance;
}

double KMeans::test()
{
    double correctPredictions {0};
    for (auto queryPoint : *testData)
    {
        double minDistance { std::numeric_limits<double>::max() };
        int bestCluster {0};
        for (int i=0; i<m_clusters->size(); ++i)
        {
            double currentDistance {euclideanDistance(m_clusters->at(i)->centroid, queryPoint)};
            if (currentDistance < minDistance)
            {
                minDistance = currentDistance;
                bestCluster = i;
            }
        }
        if (m_clusters->at(bestCluster)->modalClass == queryPoint->getLabel()) ++correctPredictions;
    }
    double performance {100.0*(correctPredictions/double{testData->size()})};
    printf("Test performance at K = %d: %.3f%%", numClusters, performance);
    return performance;
}