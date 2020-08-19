/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Initializes program for doing statistical analyses on data for find
 * mean, median, highest and lowest numbers
 *
 * @author Pranav Sharma
 * @date 06/30/2020
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

	unsigned int length = SIZE;

	unsigned char minimum = find_minimum(test, length);
	unsigned char maximum = find_maximum(test, length);
	unsigned char mean = find_mean(test, length);
	unsigned char median = find_median(test, length);

	print_statistics(minimum, maximum, mean, median);

	print_array(test, length);
}


void print_statistics(unsigned char minimum, unsigned char maximum,
					  unsigned char mean, unsigned char median) {
	printf("Minimum value of the dataset is: %d \n", minimum);
	printf("Maximum value of the dataset is: %d \n", maximum);
	printf("   Mean value of the dataset is: %d \n", mean);
	printf(" Median value of the dataset is: %d \n", median);

}

void print_array(unsigned char *data_set, unsigned int length) {
	printf("\nThe rearranged array:\n");

	printf("[");
	for (int i = 0; i < length; i++) {
		printf("%d", data_set[i]);
		if (i < length - 1) printf(", ");
	}
	printf("]\n");
}

unsigned char find_median(unsigned char *data_set, unsigned int length) {

	sort_array(data_set, length); // sorts array from largest to smallest

	if (length % 2 == 0) {
		return (*(data_set + length/2 - 1) + *(data_set + length/2));
	} else {
		return *(data_set + length/2);
	}
}


unsigned char find_mean(unsigned char *data_set, unsigned int length) {

	unsigned int sum = 0; // stores sum of data

	for (int i = 0; i < length; i++) {
		sum += *(data_set + i);
	}

	return sum/length;
}


unsigned char find_maximum(unsigned char *data_set, unsigned int length) {
	sort_array(data_set, length); // sorts array from largest to smallest

	return *data_set; // Returns the first element of the sorted array
}


unsigned char find_minimum(unsigned char *data_set, unsigned int length) {

	sort_array(data_set, length); // sorts array from largest to smallest

	return *(data_set + length - 1); // Returns the last element of the sorted array
}


void sort_array(unsigned char *data_set, unsigned int length) {

	int sorted = 0; // if sorted = 1, that means that data_set array is sorted

	while (sorted == 0) {
		// keep rearranging the array elements
		sorted = 1; // assume data is sorted in the beginning
		for (int i = 0; i < length - 1; i++) {
			if (data_set[i] < data_set[i+1]) {
				sorted = 0; // data is not sorted in descending order
				unsigned char temp = data_set[i];
				data_set[i] = data_set[i+1];
				data_set[i+1] = temp;
			}
		}
	}
}
