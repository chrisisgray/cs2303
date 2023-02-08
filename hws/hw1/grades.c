#include <stdio.h>
#include <stdlib.h>
#include "calcGrades.h"

/* Simple program to store grades.
 * Created by Cristobal Rincon Rogers, cristobal
 * 
 * Usage:
 *   ./grades some_number some_number ***
 * Example
 *   ./grades 23 79 47
 *
*/


#define MAX_GRADES (20)  // defines the max number of grades accepted as input
int i;                   // index of grades array

int main(int argc, const char* argv[]) {

  if(argc < 2) { // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1;    // return 1 to represent error
  }
  
  int all_grades[MAX_GRADES];      // creates an array size based on the number of grades inputted
  int grade;                           // Integer read from the command line goes here

  for(i = 0; i < argc - 1; i++) { 

    if(i > (MAX_GRADES - 1)) { //last array element
      printf("You have exceeded the possible number of grades\n");
      return 1;
    }
    
    grade = atoi(argv[i + 1]); // Get string from command line; Convert to int
    all_grades[i] = grade;                               // stores grade into array index i
    printf("The grade is %d\n", grade); 
 }

int avgGrade = calcGrades(i, all_grades);  // calculates the average grade by summing all elements and dividing by the total number of elements in the matrix
printf("Avg: %d\n", avgGrade);

  return 0; // Indicates success!
}
