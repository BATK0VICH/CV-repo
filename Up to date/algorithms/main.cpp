#include "VectorGenerator.hpp"
#include "search/BinarySearch.hpp"
#include "sort/SelectionSort.hpp"
#include "recursion/Sum.hpp"
#include "recursion/Recurtion.hpp"
#include "sort/QuickSort.hpp"
#include <iostream>

int main(void)
{
    VectorGenerator vector(3);
    std::cout << "Unsorted size " << vector.vec.size() << std::endl;
    std::cout << vector << std::endl;
    vector.vec = QuickSort::sort(vector.vec);
    std::cout << "Sorted size " << vector.vec.size() << std::endl;
    std::cout << vector << std::endl;
    std::cout << BinarySearch::search(8, vector.vec) << std::endl;
    std::cout << Sum::sumArray(vector.vec) << std::endl;

    std::cout << "Vector.size(): " << vector.vec.size() << std::endl 
    << "Recursive vector size(): " <<  Recurtion::countElementsInVector(vector.vec) << std::endl;
    
    std::cout << "Maximum number: " << VectorGenerator::findMax(vector.vec) << std::endl 
    << "Recursive maximum number: " << Recurtion::findMaximumNumber(vector.vec);

    
    return 0;
}