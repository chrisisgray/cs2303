/** Header file for stack data structure implementation
 * Each cell in the stack can hold a pointer to anything
 *
 * @author Blake Nelson, Cristobal Rincon Rogers
 *
 */
#ifndef STACK_H
#define STACK_H


typedef struct stack {
//top of stack increases as elements are pushed

  void **top;               /**< Ptr to next free cell */
  void **base;              /**< Ptr to bottom (base) of the stack */

  int num_elements;         /**< Num elements in the stack - 0 when empty */
  int max_elements;         /**< Maximum number of elements allowed in the stack*/

} Stack;

/** Function prototypes for stack operations 
 */

void * peek (Stack *stack);
void * pop (Stack *stack);
void * push (Stack *stack, void *element);
int isempty (Stack *stack);
int numelements (Stack *stack);
int maxelements (Stack *stack);
Stack * create (int size);
void destroy (Stack *stack);

#endif
