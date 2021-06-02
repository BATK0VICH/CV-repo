#include "Recurtion.hpp"
#include "../VectorGenerator.hpp"

int Recurtion::countElementsInVector(const std::vector<int> toCount)
{
    if (toCount.size() == 0)
        return 0;
    std::vector<int> new_vec = VectorGenerator::pop_front(toCount);
    return  1 + Recurtion::countElementsInVector(new_vec);
}

int Recurtion::findMaximumNumber(const std::vector<int> vector)
{
    if (vector.size() == 2)
    {
        if (vector.at(0) > vector.at(1))
            return vector.at(0);
        return vector.at(1);
    }
    auto newArray = VectorGenerator::pop_front(vector);
    int subMax = findMaximumNumber(newArray);
    
    if (vector.at(1) > subMax)
        return vector.at(1);
    return subMax;
}

unsigned int Recurtion::binarySearch(int number, std::vector<int> numbers)
{
    return 0;
}