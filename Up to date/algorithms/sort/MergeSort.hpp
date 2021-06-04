#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>

class MergeSort
{
public:
    static std::vector<int> sort(std::vector<int> toBeSorted);
private:
    static std::vector<int> concatenateVectors(std::vector<int> leftPart, std::vector<int> rightPart);
};

#endif