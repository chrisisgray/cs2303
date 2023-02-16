#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "generate.h"

/* Program which generates random numbers based on number entered in the command line,
 * outputs them, sorts them in descending order, and outputs the sorted list.
 * Program can use array indexing or pointers for sorting
 * Usage:
 *         ./sorttest2 some_number another_number
 * Example:
 *         ./sorttest2 2014 1
 *
 */

/** Main program
 * @param argc Number of words on the command line
 * @param argv[] Array of character strings, the words from the command line.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, const char* argv[]) {

  int *nums; // space to store numbers randomly generated.

  int amount_num; // Integer read from the command line goes here.
  int i; // array index 
  int next_num;  // next number to get

  // Check that there is at least two numbers
  amount_num = argc - 1;
  if (amount_num > 2 || amount_num < 2) { 
    printf("Error with input arguments! Exiting.\n");
    return 1; // Indicate failure
  }
  
  int num_nums = atoi(argv[1]); // Number of random integeres to generate.
  int sorting_function = atoi(argv[2]); // 0 is alt_sort_descending, 1 (default) is sort_descending

  // Allocate an array big enough to hold the numbers
  nums = (int*) calloc(num_nums, sizeof(int));
  if (nums == NULL) {
    fprintf(stderr, "Unable to allocate enougn memory to hold the numbers.\n");
  }

  /* Read all the numbers from the command line and put them into the array */
  for (i = 0; i < num_nums; i++) {
    next_num = generateNumber(); // generate random number
    nums[i] = next_num; // store into the array
  }

  // Now print, sort, and print the array, and time how long the sorting took.
  timesort(nums, num_nums, sorting_function);

  return 0; // Indicate success!
}
