/** mystring.c
 * @authors Mike Ciaraldi, Blake Nelson, Cristobal Rincon Rogers
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

char * mychardup(const char* src) {
  char *newStr = (char *)malloc(2);

  if(newStr == 0) {
  return (char *)0;
  }

  mystrncpy(newStr, src, 1);
  return newStr;
}

/**
 * @brief The mystrndup() function returns a pointer to a new string which
 * is a duplicate up to n chars of the string src. Memory for the new string is obtained malloc()
 * and can be freed with free(). 
 * 
 * @warning if src is longer than n, only n bytes are copied, and a terminating null byte ('\0')
 * is added
 * 
 * @param src 
 * @return char* 
 */
char* mystrndup(const char *src, size_t n) {
  int length;     // Length of the source string
  char *newstr;   // Pointer to memory which will hold new string
  int copySize;   // size of string to copy

  length = mystrlen(src) + 1;      // Add space for the terminator

  if(length > (n + 1)) {
    newstr = (char *) malloc(n + 1); // allocates space for n chars
    copySize = (n + 1);
  }
  else
  {
    newstr = (char *)malloc(length); // allocates space for full string
    copySize = length;
  }

  // if no memory is available, return null pointer immediately
  if(newstr == 0) {
    return (char *) 0;
  }

  // Otherwose, copy the string and return pointer to new string
  mystrncpy(newstr, src, copySize);

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

/**
 * @author Cristobal Rincon Rogers
 * @brief The mystrncpy() function copies the first n chars in string pointed to by src, including
 * If the length of src is less than n, mystrncpy() writes additional null bytes to des
 * to ensure that a total of n bytes are written. 
 * 
 * @warning If there is no null byte among the first n bytes of src, the string placed in des
 * will not be null terminated
 * 
 * @param des pointer where string will be copied to
 * @param src pointer to string to copy
 * @param n number of chars to copy
 * @return char* pointer to destination string
 */
char* mystrncpy(char* des, const char* src, size_t n) {
  
  size_t i = 0;
  // checks for terminator and incremenets pointer
  while (*(src) != 0 && i < n) {
   *(des++) = *src; //copies the char at src and then increments the pointer value of des
   src++;
   i++;
  }

  for (; i < (n+1); i++) {
   *(des++) = '\0';
  }
  
  return des;  //returns the start of the destination pointer
}

/**
 * @brief the mystrcat() function appends the src string to the des string,
 * overwriting the terminating null byte ('\0') at the end of des, and then
 * adding a terminating null byte. The strings may not overlap and the des 
 * string must have enough space for the result. If the des is not large enough,
 * program behavior is unpredictable
 * 
 * @param des string receiving the append
 * @param src string to append
 * @return char* returns pointer of string
 */
char* mystrcat(char* des, const char* src) {  
  size_t des_len = mystrlen(des);
  size_t i;

  for (i = 0; *src != '\0'; i++) {
    des[des_len + i] = *src;
    src++;
  }

  des[des_len + i] = '\0';
  return des;

}

char* mystrncat(char* des, const char* src, size_t n) {
  
  size_t des_len = mystrlen(des);
  size_t i;

  for (i = 0; i < n && *src != '\0'; i++) {
    des[des_len + i] = *src;
    src++;
  }

  des[des_len + i] = '\0';
  return des;

}

