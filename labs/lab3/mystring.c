/** mystring.c
 * @author Mike Ciaraldi, Blake Nelson
 * Custom versions of some of the C-style string functions
*/

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/
char* mystrdup(const char* src) {
  int length; 	// Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;  		// Leave space for the terminator
  newstr = (char*) malloc(length); 	// Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) {
	return (char *) 0;
  }

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/**
 * @author Cristobal Rincon Rogers
 * @brief Calculates the length of the string pointed to by src excluding the null terminator
 * 
 * @param src pointer to the string we want to find the length of
 * @return int returns the number of bytes in the string pointed to by src
 */
int mystrlen(const char* src) {
  int i = 0;

  // checks for terminator and increments pointer 
  while (*(src++) != 0) {
   i++; // increase the number of chars seen
  }

  return i; // returns the number of chars seen
}

/**
 * @author Cristobal Rincon Rogers
 * @brief The mystrcpy() function copies the string pointed to by src, 
 * including the null byte ('\0') to the buffer pointed to by des.
 * The strings may not overlap and the destination string must be large enough to receive the copy
 * @param des pointer where string will be copied to
 * @param src pointer to string to copy
 * @return char* return buffer pointer containing the copy of the string
 */
char* mystrcpy(char* des, const char* src) {
  
  // checks for terminator and incremenets pointer
  while (*(src) != 0) {
   *(des++) = *src; //copies the char at src and then increments the pointer value of des
   src++;
  }

  *des = '\0'; //adds terminator at end
  
  return des;  //returns the start of the destination pointer
}
