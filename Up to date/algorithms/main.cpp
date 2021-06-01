#include "VectorGenerator.hpp"
#include "search/BinarySearch.hpp"
#include "sort/SelectionSort.hpp"

#include <iostream>

int main(void)
{
    VectorGenerator vector(16);
    std::cout << "Unsorted size " << vector.vec.size() << std::endl;
    std::cout << vector << std::endl;
    SelectionSort::sort(vector.vec);
    std::cout << "Sorted size " << vector.vec.size() << std::endl;
    std::cout << vector << std::endl;
    std::cout << BinarySearch::search(8, vector.vec) << std::endl;
    return 0;
}