#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

//for quickSort
void quickSort(int *arr, const int low, const int high) {
    if (high > low) {
        int partIndex = partition(arr, low, high);
        quickSort(arr, low, partIndex - 1);
        quickSort(arr, partIndex + 1, high);
    }
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition (int *arr, int low, int high) {
    int pivot = arr[high];
    int smaller = (low - 1);

    for (int j = low; j <= high; ++j) {
        if (arr[j] < pivot) {
            ++smaller;
            swap(&arr[smaller], &arr[j]);
        }
    }
    swap(&arr[smaller + 1], &arr[high]);
    return (smaller + 1);
}
