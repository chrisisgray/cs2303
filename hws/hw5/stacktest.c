/** short program to demonstrate use of stack
 *
 * @author Blake Nelson, Cristobal Rincon Rogers
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/** main function to demonstrate use of stack
 *
 */
int main (int argc, char *argv[]) {
  // Create a stack to hold our test data
  Stack *the_stack;

  int size = atoi(argv[1]); // converts command line input to numeric value

  // Create a stack to hold our test data
  the_stack = create(size);  // creates stack with a size of inputed value
 int test_data[] = {1, 2, 3, 4, 5};


  printf ("sizeof(test_data)) == %ld\n", sizeof(test_data)); // size of test_data. it could be that I am not allocating
                                                            // enough memory for it
  
  // Push some test data onto the stack

  printf("%d\n", sizeof(int*));

  for (int i = 0; i < 5; i++) {

    push(the_stack, (void*) &test_data[i]);
    printf("i is %d\n", i);

#ifdef DEBUG_TEST
    printf("pushing element \"%d\"\n", test_data[i]);

    int *val = (int *) (peek(the_stack));
    printf("top of stack now \"%d\"\n", *val); // casting void * and dereferencing it
#endif
}

return 0;

}

