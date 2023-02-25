/** short program to demonstrate use of stack
 *
 * @author Blake Nelson, Cristobal Rincon Rogers
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <readline/readline.h>
#include <readline/history.h>
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

  char prompt[] = "Type a string or <Ctrl-d> to end: ";

  while(1) {
    fprintf(stdout, "%s", prompt);
    fflush(stdout);
    if((numChars = getline(&buffer, 
      &sz_buffer, stdin)) == EOF) {
        break;
      }

      char *ptr = mystrdup(buffer);

      push(the_stack, (void *) ptr);
      //fprintf(stdout, "top of stack now %s \n", (char *) (peek(the_stack))); // casting void * and dereferencing it
      //echo line back to user
      //fprintf(stdout, "You typed: %s\n", buffer);
      //fflush(stdout);

      // release memory for next loop iteration
      free(buffer);
      buffer = NULL;
      sz_buffer = 0;
  } // end of while statement


// free up any memory
if(buffer != NULL) {
  free(buffer);
}
printf("num_elements: %d \n", the_stack->num_elements);

int k = the_stack->num_elements;

for (int i = 0; i < k; i++) {
  printf("This is the value of i: %d \n", i);
  printf("top of stack now %s \n", (char *)(pop(the_stack))); // casting void * and dereferencing it
}

  destroy(the_stack);

return 0;

}

