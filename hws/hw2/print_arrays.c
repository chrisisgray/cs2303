/** file print_arrays.c
 * @author Cristobal Rincon Rogers 
 *
 * Functions for printing arrays.
 */

#include <stdio.h>
#include "print_arrays.h"
#include <stdlib.h>
/** Print an array of ints, one per line.
    @param a Array to print
    @param num_entries Number of entries in the array

*/

void print_int_array(int a[], int num_entries) {
  int i; // Loop counter

  for (i = 0; i < num_entries; i++) {
    printf("%d\n", a[i]);
  }
}

/** Print an array of doubles, one per line.
 *  @param a Array to print of doubles
 *  @param num_entries Number of entries in the array
 */
void print_double_array(double a[], int num_entries) {

	int i; // loop counter

	for(i = 0; i < num_entries; i++) {
		printf("%f\n", a[i]);
	}
}

/**
 * @brief This function inserts floats entered from the command line, converts them to doubles,
 * 		  and copies the doubles into another array
 * 
 * @param inputs the number of inputs entered from the command line
 * @param src the values entered from the command line that we wish to convert and copy
 * @param des the array where the values from src get inserted into
 * @param length the length of the des array
 * @return int value of 0 indicates success
 */
    int insert_double_into(int inputs, const char** src, double* des, int length) {
	int i;

	for(i=0; i < length; i++) {
	*des = atof(*(++src));
	des++; // increment memory adding
	}

	if(inputs - length > 1){
	printf("you done goofed\n");
	return 1; // Not all values fit into the destination array 
	}

	return 0;
}