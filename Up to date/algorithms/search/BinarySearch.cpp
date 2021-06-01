#include "BinarySearch.hpp"
#include <iostream>

int BinarySearch::search(const int numberToSearch, const std::vector<int> &vectorToSearch)
{
    unsigned int lowIndex{ 0 };
    long unsigned int highIndex{ vectorToSearch.size() - 1};
    int numberOfOperations{ 0 };

    while (lowIndex <= highIndex)
    {
        long unsigned int middleIndex{ lowIndex + highIndex};
        int guess = vectorToSearch.at(middleIndex);
        
        if (guess == numberToSearch)
        {
            std::cout << "Number of operations required: " << numberOfOperations << std::endl;
            return middleIndex;
        }
            

        if (guess > numberToSearch)
            highIndex = middleIndex - 1;
        else
            lowIndex = middleIndex + 1;
        numberOfOperations++;
    }
    
    return -1;
}