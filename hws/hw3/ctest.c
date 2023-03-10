// string.h covers the C-style string functions.
#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"
#include "employee.h"
#include "generate.h"

/** ctest.c
 * Program to demonstrate character arrays and dynamically-allocated memory.
 * @author Mike Ciaraldi, Blake Nelson, Cristobal Rincon Rogers
 */

const int MAX_CHARS = 20;       // Maximum number of characters in array

int main()
{
  char a1[MAX_CHARS + 1]; 	// Character array--initially empty
  char a2[] = "Hello"; 		// Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; 	// Character array--we will underfill it
  const char *p1 = "Hello";     // Pointer to constant string
  char *p2;           		// Will be a pointer to dynamically-allocated string
  int copy_limit;     		// Maximum characters to copy.


  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Arrays:   a1: %p, a2: %p, a3: %p\n", a1, a2, a3);
  printf("Pointers: p1: %p, p2: %p\n", p1, p2);

  mystrcpy(a1, "Hi"); 		// Initialize character array a1 with some text
  mystrcpy(a3, "Hello, also");    // Initialize uinderfilled character array


  // Print the values of the C-style strings
  printf("\n");
  printf("C-string values:\n");
  printf("a1: %s\n", a1);
  printf("a2: %s\n", a2);
  printf("a3: %s\n", a3);

  /* Concatenate two character arrays, then print.
  *  Terminator character in the last element of the array as well as after "Hi"
  */
  a1[MAX_CHARS] = '\0';		
  mystrcat(a1, a2);
  printf("\n");
  printf("After concatenating a2 to the end of a1\n");
  printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - mystrlen(a1); 	// How much space is left?
  
  printf("\n");
  printf("Concatenating a2 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
	mystrncat(a1, a2, copy_limit);
  }
  printf("a1: %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - mystrlen(a1); 	// How much space is left?
  printf("\n");
  printf("Concatenating a3 to a1, with copy_limit = %d\n", copy_limit);
  if (copy_limit > 0) {
	mystrncat(a1, a3, copy_limit);
  }
  printf("a1: %s\n", a1);

  // Duplicate a string, using my function, then print
  printf("\n");
  printf("Before dup, array a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("After dup, pointer p2 =  %p, contents = %s\n", p2, p2);

  // Free the memory allocated on our behalf by mystrdup()
  free(p2);

//------------------------ My test arrays---------------------------------//

  char good[20];
  char bad[20];
  char* goofy;

  mystrcpy(good, "phrase"); // copies string into good
  printf("When I copied this string, I got string %s\n", good);

  mystrncpy(bad, "cristobal", 3);  //copies first 3 chars in cristobal --> cri
  printf("the first three chars of the word cristobal are %s\n", bad);

// returns the length of arrays with data copied into them
  printf("the size of good is %d \n", mystrlen(good));
  printf("the size of bad is %d \n", mystrlen(bad));

// concatenates two bad with good
  mystrcat(bad, good);
  printf("the new string is %s\n", bad);

// concatenatest the first character of good into bad
  mystrncat(bad, good,1);
  printf("the new string is %s\n", bad);

// dooplicates bad into goofy
  goofy = mystrndup(bad, 5);
  printf("goofy is %s\n", goofy);


// create some employees manually
  char *someName = "Cristobal\0";
  char *sisName = "Arisa\0";
  Employee *newEmployee;
  Employee *newEmployee2;
  Employee *newEmployee3;
  Employee *newEmployee4;

  newEmployee = make_employee(someName, 2002, 2019);
  newEmployee2 = make_employee(sisName, 2004, 2021);
  newEmployee3 = generateEmployee(9);  //auto-fill employees with name length of 9 chars
  newEmployee4 = generateEmployee(7);

  Employee *work[4] = {newEmployee, newEmployee2, newEmployee3, newEmployee4}; // creates an array of employees

  printEmployee(newEmployee);
  printEmployee(newEmployee2);
  printEmployee(newEmployee3);
  printEmployee(newEmployee4);


// determines the size of work array
  int d = sizeof(work) / sizeof(Employee*);
  printf("this is the number of people working here: %d\n", d);

// test for function that returns array of 3 auto generated employees
  printf("\n\n\n");
  Employee **bestWorkforce = generateWorkforce(3);
  printWorkforce(bestWorkforce, 3);

// shallow copies the previously made array
  printf("\n\n Here comes the replica\n\n");
  Employee **replica = copyWorkforce(bestWorkforce, 3);
  printWorkforce(replica, 3);

  printf("\n\n Here comes the deep copy\n\n");
  // deep copies the best work force arrray
  Employee **existing = deepCopyWorkforce(bestWorkforce, 3);

  printf("\n\n Time to free the employees\n\n");
  // function that frees all of the original arrays
  freeTheEmployees(bestWorkforce, 3);

  printf("\n\n workforce still exists even though I freed previous pointers!\n\n");
  // EXTRA CREDIT: proof of deep copy since elements stll exist.
  printWorkforce(existing, 3);

  free(newEmployee);
  free(newEmployee2);
  free(newEmployee3);
  free(newEmployee4);

  return 0;
}



