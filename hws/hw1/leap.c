#include <stdio.h>
#include <stdlib.h>

/* A program that determines if a year is a leap year.
 * Created by Cristobal Rincon Rogers, cristobal
 * 
 * Usage:
 *   ./leap some_number
 * Example
 *   ./leap 2303
 *
*/

int zeroRemainder(int year, int divider);

int main(int argc, const char* argv[]) {
  int n; // Integer read from the command line goes here

  if(argc < 2) { // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1;
  }

  n = atoi(argv[1]); // Get string from command line; Convert to int
  if(n < 1752) {
     printf("This program cannot test the year %d. It only handles the year 1752 and after\n", n);
   }
 
  if(((zeroRemainder(n, 4)  && !zeroRemainder(n, 100)) || zeroRemainder(n, 400))){
	printf("%d is a leap year!\n", n);
	} else {
		printf("%d is not a leap year\n", n);
	}
  return 0; // Indicates success!
}

/* Determines if a year devided by a number has a remainder.
 * Returns true true if there is no remainder.
 * Created by Cristobal Rincon
 * */
int zeroRemainder(int year, int divider) {
	return year % divider == 0;
}
