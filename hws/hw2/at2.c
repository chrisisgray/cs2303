/** file at2.c
 * @Cristobal Rincon Rogers
 *
 * Program to print arrays entered in the command line.
 */

#include "print_arrays.h"
#include "array_sort.h"
#include <stdlib.h>
#include <stdio.h>

#define SAMPLE_INT_ARRAY_SIZE (10)

/** Main program for printing arrays. It fills them with floats entered through the command line and prints them.
 * @param argc Number of entries in the command line
 * @param argv Array of 
 * @return 0, Indicating success.
 */

int main(int argc, const char* argv[]) {

	int inputs = argc-1;
	double a[inputs];

	insert_double_into(argc, argv, a, inputs);
	print_double_array(a, inputs);  // unsorted printing

	// add sorting functionality
	printf("\n");
	printf("Sorted stuff incoming:\n");
	sort_array(inputs, a);
	print_double_array(a, inputs);
}
