#include "QuickSort.hpp"
#include <iostream>

std::vector<int> QuickSort::sort(std::vector<int> &toBeSorted)
{
    if (toBeSorted.size() < 2)
        return toBeSorted;

    int pivot = toBeSorted.at(0);
    auto less = lessThanPivot(pivot, toBeSorted);
    auto greater = greaterThanPivot(pivot, toBeSorted);


    std::vector<int> sortedLess{ QuickSort::sort(less) };
    std::vector<int> sortedGreater{ QuickSort::sort(greater) };
    std::cout << "Before concatenation" << std::endl;
    std::vector<int> newArray{ makeVectorWith(sortedLess, pivot, sortedGreater) };

    return  newArray;
}

 std::vector<int> QuickSort::lessThanPivot(const int pivot, const std::vector<int> toBeSorted)
 {
     std::vector<int> lessPart{ };
     for (auto it = toBeSorted.cbegin(); it != toBeSorted.cend(); ++it)
     {
        if (*it <= pivot)
            lessPart.push_back(*it);
        continue;
     }
     return lessPart;
 }

 std::vector<int> QuickSort::greaterThanPivot(const int pivot, const std::vector<int> toBeSorted)
 {
     std::vector<int> greaterPart{ };
     for (auto it = toBeSorted.cbegin(); it != toBeSorted.cend(); ++it)
     {
         if (*it > pivot)
             greaterPart.push_back(*it);
     }
     std::cout << "I'm in greater" << std::endl;
     return greaterPart;
 }

std::vector<int> QuickSort::makeVectorWith(std::vector<int> less, int pivot, std::vector<int> greater)
 {
    std::vector<int> newArray{ };
    std::cout << "I'm in concatenation" << std::endl;
    newArray.insert(newArray.end(), less.begin(), less.end());
    newArray.push_back(pivot);
    newArray.insert(newArray.end(), greater.begin(), greater.end());
    
    return newArray;
 }