#include "../../include/MNIST/mnist_data_handler.hpp"

MNISTDataHandler::MNISTDataHandler()
{
    allData = new std::vector<MNISTData*>;
    trainingData = new std::vector<MNISTData*>;
    testData = new std::vector<MNISTData*>;
    validationData = new std::vector<MNISTData*>;
}

MNISTDataHandler::~MNISTDataHandler()
{
    // free dynamically allocated memory
}

void MNISTDataHandler::readFeatureVector(std::string path)
{
    uint32_t header[4]; // MAGIC|NUMIMAGES|ROWSIZE|COLSIZE
    unsigned char bytes[4];
    FILE* f = fopen(path.c_str(), "r");

    if (f)
    {
        for (int i=0; i<4; ++i)
        {
            if (fread(bytes, sizeof(bytes), 1, f))
            {
                header[i] = convertToLittleEndian(bytes);
            }
        }
        printf("Done getting image file header.\n");
        
        int imageSize = header[2]*header[3];
        printf("Num samples: %d\n", header[1]);
        printf("Image size: %d pixels\n", imageSize);
        for (int i=0; i<header[1]; ++i)
        {
            MNISTData* data = new MNISTData();
            uint8_t element[1];
            for (int j=0; j<imageSize; ++j)
            {
                if (fread(element, sizeof(element), 1, f))
                {
                    data->appendToFeatureVector(element[0]);
                } else
                {
                    printf("Error reading from file.\n");
                    exit(1);
                }
            }
            allData->push_back(data);
        }
        printf("Successfully read and stored %lu feature vectors.\n", allData->size());
    } else
    {
        printf("Could not find file.\n");
        exit(1);
    }

}

void MNISTDataHandler::readLabels(std::string path)
{
    uint32_t header[2]; // MAGIC|NUMIMAGES
    unsigned char bytes[4];
    FILE* f = fopen(path.c_str(), "r");

    if (f)
    {
        for (int i=0; i<2; ++i)
        {
            if (fread(bytes, sizeof(bytes), 1, f))
            {
                header[i] = convertToLittleEndian(bytes);
            }
        }
        printf("Done getting label file header.\n");
        
        for (int i=0; i<header[1]; ++i)
        {
            uint8_t element[1];
            if (fread(element, sizeof(element[0]), 1, f))
            {
                allData->at(i)->setLabel(element[0]);
            } else
            {
                printf("Error reading from file.\n");
                exit(1);
            }
        }
        printf("Successfully read and stored %lu labels.\n", allData->size());
    } else
    {
        printf("Could not find file.\n");
        exit(1);
    }
}

void MNISTDataHandler::splitData()
{
    std::unordered_set<int> usedIndices;
    int trainingSetSize = allData->size()*TRAIN_SET_PERCENT;
    int testSetSize = allData->size()*TEST_SET_PERCENT;
    int validationSetSize = allData->size()*VALIDATION_SET_PERCENT;

    // Training Data
    int count = 0;
    while (count<trainingSetSize)
    {
        int randIdx = rand() % allData->size();
        if (usedIndices.find(randIdx) == usedIndices.end())
        {
            trainingData->push_back(allData->at(randIdx));
            usedIndices.insert(randIdx);
            ++count;
        }
    }
    // Test Data
    count = 0;
    while (count<testSetSize)
    {
        int randIdx = rand() % allData->size();
        if (usedIndices.find(randIdx) == usedIndices.end())
        {
            testData->push_back(allData->at(randIdx));
            usedIndices.insert(randIdx);
            ++count;
        }
    }
    // Validation Data
    count = 0;
    while (count<validationSetSize)
    {
        int randIdx = rand() % allData->size();
        if (usedIndices.find(randIdx) == usedIndices.end())
        {
            validationData->push_back(allData->at(randIdx));
            usedIndices.insert(randIdx);
            ++count;
        }
    }

    printf("Training data size: %lu\n", trainingData->size());
    printf("Test data size: %lu\n", testData->size());
    printf("Validation data size: %lu\n", validationData->size());
}

void MNISTDataHandler::countClasses()
{
    int count = 0;
    for (unsigned i=0; i<allData->size(); ++i)
    {
        if (classMap.find(allData->at(i)->getLabel()) == classMap.end())
        {
            classMap[allData->at(i)->getLabel()] = count;
            allData->at(i)->setEnumLabel(count);
            ++count;
        }
    }
    numClasses = count;
    printf("Successfully extracted %d unique classes.\n", numClasses);
}

uint32_t MNISTDataHandler::convertToLittleEndian(const unsigned char* bytes)
{
    return (uint32_t) ((bytes[0]<<24) |
                       (bytes[1]<<16) |
                       (bytes[2]<<8)  |
                        bytes[3]);
}

std::vector<MNISTData*>* MNISTDataHandler::getTrainingData() { return trainingData; }
std::vector<MNISTData*>* MNISTDataHandler::getTestData() { return testData; }
std::vector<MNISTData*>* MNISTDataHandler::getValidationData() { return validationData; }

int main()
{
    MNISTDataHandler *dataHandler = new MNISTDataHandler();
    dataHandler->readFeatureVector("data/train-images-idx3-ubyte");
    dataHandler->readLabels("data/train-labels-idx1-ubyte");
    dataHandler->splitData();
    dataHandler->countClasses();

    return 0;
}