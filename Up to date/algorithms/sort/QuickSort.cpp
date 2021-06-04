#include "QuickSort.hpp"
#include <iostream>


std::vector<int> QuickSort::sort(std::vector<int> toBeSorted)
{
    if (toBeSorted.size() < 2)
        return toBeSorted;

    int pivot = toBeSorted.at(0);
    auto less = QuickSort::lessThanPivot(pivot, toBeSorted);
    auto greater = QuickSort::greaterThanPivot(pivot, toBeSorted);


    std::vector<int> sortedLess = QuickSort::sort(less);
    std::vector<int> sortedGreater = QuickSort::sort(greater);
    std::vector<int> newArray = makeVectorWith(sortedLess, pivot, sortedGreater);

    return  newArray;
}

 std::vector<int> QuickSort::lessThanPivot(const int pivot, const std::vector<int> toBeSorted)
 {
     std::vector<int> lessPart{};
    for (unsigned long int i{ 0 }; i < toBeSorted.size(); ++i)
    {
        if (toBeSorted.at(i) < pivot)
            lessPart.push_back(toBeSorted.at(i));
    }
    return lessPart;
 }

 std::vector<int> QuickSort::greaterThanPivot(const int pivot, const std::vector<int> toBeSorted)
 {
    std::vector<int> greaterPart{};
     for (unsigned long int i{ 0 }; i < toBeSorted.size(); ++i)
     {
         if (toBeSorted.at(i) > pivot)
            greaterPart.push_back(toBeSorted.at(i));
     }
     return greaterPart;
 }

std::vector<int> QuickSort::makeVectorWith(std::vector<int> less, int pivot, std::vector<int> greater)
 {
    std::vector<int> newArray{ };
    newArray.insert(newArray.end(), less.begin(), less.end());
    newArray.push_back(pivot);
    newArray.insert(newArray.end(), greater.begin(), greater.end());
    
    return newArray;
 }