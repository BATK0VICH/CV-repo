#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include "../VectorGenerator.hpp"

#include <vector>

class QuickSort
{
private:
    static std::vector<int> lessThanPivot(const int pivot, const std::vector<int> toBeSorted);
    static std::vector<int> greaterThanPivot(const int pivot, const std::vector<int> toBeSorted);
    static std::vector<int> makeVectorWith(std::vector<int>, int pivot, std::vector<int>);
public:
   static std::vector<int> sort(std::vector<int> toBeSorted);
};

#endif