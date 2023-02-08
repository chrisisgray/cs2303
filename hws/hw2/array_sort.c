/**
 * @file array_sort.c
 * @author Cristobal Rincon Rogers
 * @brief Functions for sorting arrays
 * @version 0.1
 * @date 2023-01-31
 * 
 * @copyright Copyright (c) 2023
 * 
 * 
 */


#include <stdio.h>
#include "array_sort.h"


/**
 * @brief This function sorts an array of doubles in ascending order (smallest to largest) using bubble sort algorithm
 * 
 * @param array_size Number of items stored in the array
 * @param array Array of doubles to sort
 */
void sort_array(int array_size, double array[]) {
    int step, i;  double tmp;
  
  for(step = 0; step < array_size-1; step++) {
    for (i = 0; i < array_size - step - 1; i++) { 
        if (array[i] > array[i+1]) {        
            tmp = array[i];        
            array[i] = array[i+1];        
            array[i+1] = tmp;      
           }    
        }                
    } 
}

/**
 * @brief This function sorts an array of ints in ascending order using bubble sort
 * 
 * @param array_size Number of items stored in the array
 * @param array_of_int Array of integers to sort
 */
void sort_array_int(int array_size, int array_of_int[]) {
    int step, i;  int tmp;
  
  for(step = 0; step < array_size-1; step++) {
    for (i = 0; i < array_size - step - 1; i++) { 
        if (array_of_int[i] > array_of_int[i+1]) {        
            tmp = array_of_int[i];        
            array_of_int[i] = array_of_int[i+1];        
            array_of_int[i+1] = tmp;      
           }    
        }                
    }
} 
