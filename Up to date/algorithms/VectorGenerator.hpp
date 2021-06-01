#ifndef VECTOR_GENERATOR_HPP
#define VECTOR_GENERATOR_HPP

#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

class VectorGenerator
{
public:
    static const int MAX_VALUE{ 264 };
    std::vector<int> vec;
    VectorGenerator(const unsigned int numberOfElements);
    friend std::ostream &operator << (std::ostream &os, const VectorGenerator &vector);
};

VectorGenerator::VectorGenerator(const unsigned int numberOfElements)
{
    srand(time(NULL));
    for (unsigned int i{ 0 }; i < numberOfElements; ++i)
        vec.push_back(rand() % MAX_VALUE);
}

std::ostream &operator << (std::ostream &os, const VectorGenerator &vector) 
{
    std::vector<int> vec = vector.vec;
    for (unsigned int i{ 0 }; i < vec.size(); ++i)
    {
        os << vec.at(i) << " ";
    }
    return os;
}


#endif