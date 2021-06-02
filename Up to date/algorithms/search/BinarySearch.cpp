#include "BinarySearch.hpp"
#include "../VectorGenerator.hpp"

int BinarySearch::search(const int numberToSearch, const std::vector<int> &vectorToSearch)
{
    if (!VectorGenerator::isVectorOk(vectorToSearch))
        return -1;
    
    unsigned int lowIndex{ 0 };
    long int highIndex{ vectorToSearch.size() - 1 };

    while (lowIndex <= highIndex)
    {
        long unsigned int middleIndex{ lowIndex + highIndex};
        int guess = vectorToSearch.at(middleIndex);
        
        if (guess == numberToSearch)
            return middleIndex;

        if (guess > numberToSearch)
            highIndex = middleIndex - 1;
        else
            lowIndex = middleIndex + 1;
    }
    
    return -1;
}