#include "SelectionSort.hpp"
#include "../VectorGenerator.hpp"

void SelectionSort::sort(std::vector<int> &toBeSorted)
{
    if (!VectorGenerator::isVectorOk(toBeSorted))
        return;
        
    for (unsigned long int i{ 0 }; i < toBeSorted.size() - 1; ++i)
    {
        unsigned long int minimalIndex = i;
        for (unsigned long int j {minimalIndex + 1}; j < toBeSorted.size(); ++j)
        {
            if (toBeSorted.at(j) < toBeSorted.at(minimalIndex))
                minimalIndex = j;
        }
        std::swap(toBeSorted[minimalIndex], toBeSorted[i]);
    }

}

unsigned int SelectionSort::findSmallest(const std::vector<int> &vec)
{
    int smallestIndex = 0;
    int smallestNumber{ vec.at(smallestIndex) };

    for (unsigned long int i{ 0 }; i < vec.size(); ++i)
    {
        if (vec.at(i) < smallestNumber)
        {
            smallestIndex = i;
            smallestNumber = vec.at(smallestIndex);
        }
    }
    return smallestIndex;
}