#include "VectorGenerator.hpp"
#include "search/BinarySearch.hpp"
#include "sort/SelectionSort.hpp"
#include "recursion/Sum.hpp"
#include "recursion/Recurtion.hpp"
#include "sort/QuickSort.hpp"
#include "sort/MergeSort.hpp"
#include <iostream>

int main(void)
{
    VectorGenerator unsorted(16);
    VectorGenerator quickSorted(QuickSort::sort(unsorted.vec));
    std::cout << "Quick Sorted size " << quickSorted.vec.size() << std::endl;
    std::cout << quickSorted << std::endl;
    
    VectorGenerator mergeSorted(MergeSort::sort(unsorted.vec));
    std::cout << "Merge Sorted size " << mergeSorted.vec.size() << std::endl;
    std::cout << mergeSorted << std::endl;

    return 0;
}