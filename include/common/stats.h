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
 * @file stats.h
 * @brief Initializes program for doing statistical analyses on data for find
 * mean, median, highest and lowest numbers
 *
 * @author Pranav Sharma
 * @date 06/30/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


void print_statistics(unsigned char minimum, unsigned char maximum,
					  unsigned char mean, unsigned char media);
/**
 * @brief Prints the neatly formatted analytics to the console
 *
 * @param minimum		minimum value in the dataset
 * @param maximum		maximum value in the dataset
 * @param mean			mean value of the dataset
 * @param median		median value of the dataset
 */

void print_array(unsigned char *data_set, unsigned int length);
/**
 * @brief Prints the array to the console
 *
 * @param *data_set		array that contains the data to be analyzed
 * @param length 		size of the array
 */

unsigned char find_median(unsigned char *data_set, unsigned int length);
/**
 * @brief Finds the median from the provided dataset
 *
 * @param *data_set		array that contains the data to be analyzed
 * @param length 		size of the array
 *
 * @return median value from data
 */

unsigned char find_mean(unsigned char *data_set, unsigned int length);
/**
 * @brief Finds mean from the provided dataset
 *
 * @param *data_set		array that contains the data to be analyzed
 * @param length 		size of the array
 *
 * @return mean value from dataset
 */

unsigned char find_maximum(unsigned char *data_set, unsigned int length);
/**
 * @brief Find the maximum value from the provided dataset
 *
 * @param data_set		array that contains the data to be analyzed
 * @param length 		size of the array
 *
 * @return maximum value from dataset
 */

unsigned char find_minimum(unsigned char *data_set, unsigned int length);
/**
 * @brief Find minimum value from the provided dataset
 *
 * @param *data_set		array that contains the data to be analyzed
 * @param length 		size of the array
 *
 * @return minimum value from data
 */

void sort_array(unsigned char *data_set, unsigned int length);
/**
 * @brief Sort array from largest to smallest
 *
 * @param *data_set 	array that contains the data to be analyzed
 * @param length 		size of the array
 */

#endif /* __STATS_H__ */
