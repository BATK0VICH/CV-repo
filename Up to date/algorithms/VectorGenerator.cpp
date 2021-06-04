#include "VectorGenerator.hpp"
#include <stdexcept>

VectorGenerator::VectorGenerator(const int numberOfElements) :
    vec()
{
    if (numberOfElements < 0)
        throw std::runtime_error("Vector size can't be < 0");
    else
    {
        srand(time(NULL));
        for (unsigned int i{ 0 }; i < numberOfElements; ++i)
            vec.push_back(rand() % MAX_VALUE);
    }
}

VectorGenerator::VectorGenerator(const std::vector<int> vector) :
    vec(vector)
{}

std::ostream &operator << (std::ostream &os, const VectorGenerator &vector) 
{
    std::vector<int> vec = vector.vec;
    for (unsigned int i{ 0 }; i < vec.size(); ++i)
    {
        os << vec.at(i) << " ";
    }
    return os;
}

bool VectorGenerator::isVectorOk(const std::vector<int> &vec)
{
    if (vec.size() > 0)
        return true;
    return false;
}

std::vector<int> VectorGenerator::pop_front(std::vector<int> vecToDeleteFirstItem)
{
    std::vector<int> newVector{};
    for (unsigned long int i{ 1 }; i < vecToDeleteFirstItem.size(); ++i)
        newVector.push_back(vecToDeleteFirstItem.at(i));
    return newVector;
}

int VectorGenerator::findMax(std::vector<int> vector)
{
    if (vector.size() == 0)
        return 0;
    int max{ vector.at(0) };
    for (unsigned int i{ 1 }; i < vector.size(); ++i)
    {
        if (vector.at(i) > max)
            max = vector.at(i);
    }
    return max;
}