#include <stdio.h>
#include <stdlib.h>

/* Very simple program to demo reading a number from the command line.
 * Created by Cristobal Rincon Rogers, cristobal
 * 
 * Usage:
 *   ./num some_number
 * Example
 *   ./num 2303
 *
*/

int main(int argc, const char* argv[]) {
  int n; // Integer read from the command line goes here

  if(argc < 2) { // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1;
  }

  n = atoi(argv[1]); // Get string from command line; Convert to int
  printf("The number you entered was: %d\n" , n);
  return 0; // Indicates success!
}
