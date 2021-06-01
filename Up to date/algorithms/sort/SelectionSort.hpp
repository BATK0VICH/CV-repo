#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>

class SelectionSort
{
private:
    static unsigned int findSmallest(const std::vector<int> &vec);
public:
    static void sort(std::vector<int> &toBeSorted);
};


#endif