#include "MergeSort.hpp"
#include <iostream>

std::vector<int> MergeSort::sort(std::vector<int> toBeSorted)
{
    if (toBeSorted.size() < 2)
        return toBeSorted;
    
    unsigned int middleIndex = toBeSorted.size() / 2;
    std::vector<int> leftPart{}, rightPart{};
    leftPart.insert(leftPart.cbegin(), toBeSorted.cbegin(), 
                    toBeSorted.cbegin() + (middleIndex));
    rightPart.insert(rightPart.cbegin(), 
                    (toBeSorted.cbegin() + middleIndex), toBeSorted.cend());

    leftPart = MergeSort::sort(leftPart);
    rightPart = MergeSort::sort(rightPart);

    std::vector<int> sortedVector{};
    sortedVector = MergeSort::concatenateVectors(leftPart, rightPart);
    return sortedVector;
}

std::vector<int> MergeSort::concatenateVectors(std::vector<int> leftPart, std::vector<int> rightPart)
{
    std::vector<int> concatenatedVector{};
    unsigned int i{ 0 }, j{ 0 };

    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart.at(i) <= rightPart.at(j)) {
            concatenatedVector.push_back(leftPart.at(i));
            i++;
        }
        else {
            concatenatedVector.push_back(rightPart.at(j));
            j++;
        }
    }
 
    while (i < leftPart.size()) {
        concatenatedVector.push_back(leftPart.at(i));
        i++;
    }
 
    while (j < rightPart.size()) {
        concatenatedVector.push_back(rightPart.at(j));
        j++;
    }

    return concatenatedVector;
}