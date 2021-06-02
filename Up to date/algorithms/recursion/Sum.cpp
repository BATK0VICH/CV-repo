#include "Sum.hpp"
#include "../VectorGenerator.hpp"

int Sum::sumArray(const std::vector<int> vecToSum)
{
    if (vecToSum.size() == 0)
        return 0;
    if (vecToSum.size() == 1)
        return vecToSum.at(0);
    
    return vecToSum.at(0) + sumArray(VectorGenerator::pop_front(vecToSum));
}