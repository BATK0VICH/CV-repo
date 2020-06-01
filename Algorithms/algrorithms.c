#include <stdio.h> 
#include <stdlib.h>
#include <time.h> //for random
#include "arrayStuff.h" //for work with arrays
#include "sort.h" //for sorting algorithms
#include "search.h" //for binarySearch

int main(void) {
    int *arr = NULL;
    size_t length = 0;
    int choice = 0;

    do {
        fputs("1. Create an array\n2. Sort an array\n3. Search in array\n4. Display an array\n0.Quit\n", stdout);
        fputs("Enter your choice: ", stdout);
        scanf("%d", &choice);

        //number to find
        int x = 0;
        //length of the array
        switch (choice)
        {
        case 1:
            fputs("Enter length: ", stdout);
            scanf("%d", &length);
            arr = create_array(length);
            break;
        case 2:
            quickSort(arr, STARTING_INDEX, length);
            break;
        case 3:
            printf("Enter a number you want to find: ");
            scanf("%d", &x);

            if (binarySearch(arr, STARTING_INDEX, length - 1, x) == -1)
                printf("Not in the array\n");
            else {
                int position = binarySearch(arr, STARTING_INDEX, length - 1, x);
                printf("%d is at index %d\n", x, position);
            }
            break;
        case 4:
            display_array(arr, length);
            break;
        case 0:
            free(arr);
            exit(EXIT_SUCCESS);
        default:
            fputs("Unkown choice...\n", stdout);
            break;
        }
    } while(choice != 0);
    
    return 0;
}
