#ifndef ARRAYSTUFF_H_
#define ARRAYSTUFF_H_

//creates dynamically allocated array with random values in it form 0 to RAND_MAX
int *create_array(const int length);

void display_array(const int *arr, int length);

#endif