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

int generateRandom(int max);
void populate_arr_with_rand(int maxCount, int maxRandom, int *des);

int main(int argc, const char* argv[]) {

	if(argc < 2) {
		printf("not enough arguments entered!\n");
	}

	int max_random = atoi(*(++argv));
	int num_randoms = atoi(*(++argv));

	int rand_array[num_randoms];
	populate_arr_with_rand(num_randoms, max_random, rand_array);
	print_int_array(rand_array, num_randoms);

	printf("\nSorted random array!\n");
	sort_array_int(num_randoms, rand_array);
	print_int_array(rand_array, num_randoms);
}

int generateRandom(int max) {
	int random = rand();
	printf("random number: %d \n", random);
	if(random > max) {
		random = random % max;
		printf("This is the new value: %d\n", random);
	}

	return (random);
}

void populate_arr_with_rand(int maxCount, int maxRandom,  int* des) {
	int i;

	for (i = 0; i < maxCount; i++) {
		*des = generateRandom(maxRandom);
		des++;
	}
}
