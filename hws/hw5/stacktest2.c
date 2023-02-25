/** short program to demonstrate use of stack
 *
 * @author Blake Nelson, Cristobal Rincon Rogers
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <unistd.h>
#include "mystring.h"


/** main function to demonstrate use of stack
 *
 */
int main (int argc, char *argv[]) {
  // Create a stack to hold our test data
  Stack *the_stack;

  char *buffer = NULL;
  size_t sz_buffer = 0;
  int numChars = 0;

  while(1) {
    if((numChars = getline(&buffer, 
      &sz_buffer, stdin)) == EOF) {
        break;
      }

      int num = mystrlennewline(buffer);

      the_stack = create(num); // creates a stack with size of string
      int i = 0;
      while (*(buffer + i) != '\n') {
        char *ptr = (char *) malloc(sizeof(char *));
        *ptr = *(buffer + i);
        push(the_stack, (void *)ptr);
        i++;
      }

      for (; i > 0; i--) {
        char *temp = (char*) pop(the_stack);
        printf("%c", *temp);
      }

      printf("\n");

      // release memory for next loop iteration
      free(buffer);
      buffer = NULL;
      sz_buffer = 0;
  } // end of while statement


// free up any memory
if(buffer != NULL) {
  free(buffer);
}
 destroy(the_stack); // releases all memory allocated by the program

return 0;

}

