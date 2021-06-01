#ifndef SORT_H_
#define SORT_H_

#define STARTING_INDEX 0

//sort an array using quck sort algorithm
void quickSort(int *arr, const int low, const int high);
int partition (int *arr, int low, int high);
void swap(int *num1, int *num2);


#endif