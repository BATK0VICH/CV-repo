#include "arrayStuff.h"
#include <stdio.h>
#include <stdlib.h>

int *create_array(const int length) {

    //allocating array
    int *randomInts = (int *)calloc(length, sizeof(int));
    if (randomInts == NULL) {
        perror("Error in calloc");
        exit(EXIT_FAILURE);
    }

    //fill array with random values
    srand(time(NULL));
    for (int i = 0; i < length; ++i) {
        randomInts[i] = rand() % 1001;
    }
    if (sizeof(randomInts) == 0) {
        perror("Error in malloc");
        exit(EXIT_FAILURE);
    }
    return randomInts;
}

void display_array(const int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
        if (i % 10 == 0) 
            printf("\n");
        
            
    }
    printf("\n---------------------\n");
}