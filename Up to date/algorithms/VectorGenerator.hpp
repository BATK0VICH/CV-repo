#ifndef VECTOR_GENERATOR_HPP
#define VECTOR_GENERATOR_HPP

#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

class VectorGenerator
{
private:
    static const int MAX_VALUE{ 264 };
public:
    std::vector<int> vec;
    VectorGenerator(const int numberOfElements);
    friend std::ostream &operator << (std::ostream &os, const VectorGenerator &vector);
    static bool isVectorOk(const std::vector<int> &vec);
    static std::vector<int> pop_front(std::vector<int> vecToDeleteFirstItem);
    static int findMax(std::vector<int> vector);
};

#endif