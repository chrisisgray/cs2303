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

  int size = atoi(argv[1]); // converts command line input to numeric value

  // Create a stack to hold our test data
  the_stack = create(size);  // creates stack with a size of inputed value

  char *buffer = NULL;
  size_t sz_buffer = 0;
  int numChars = 0;
 

  while(1) {

     #ifdef DEBUG_TEST
        char prompt[] = "Type a string or <Ctrl-d> to end: ";
        fprintf(stdout, "%s", prompt);
        fflush(stdout);
    #endif
   
    if((numChars = getline(&buffer, 
      &sz_buffer, stdin)) == EOF) {
        break;
      }

      char *ptr = mystrdup(buffer);

      push(the_stack, (void *) ptr);

      #ifdef DEBUG_TEST
      fprintf(stdout, "top of stack now %s \n", (char *) (peek(the_stack))); // casting void * and dereferencing it
      //echo line back to user
      fprintf(stdout, "%s\n", buffer);
      fflush(stdout);
      #endif

      // release memory for next loop iteration
      free(buffer);
      buffer = NULL;
      sz_buffer = 0;
  } // end of while statement


// free up any memory
if(buffer != NULL) {
  free(buffer);
}

int k = the_stack->num_elements; // get the total number of elements in the stack

for (int i = 0; i < k; i++) {
  // no need for newline character because strings already contain them
  printf("%s", (char *)(pop(the_stack))); // casting void * to char * and dereferencing it
}

  destroy(the_stack); // releases all memory allocated by the program

return 0;

}

