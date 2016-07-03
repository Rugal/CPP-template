#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct Stack Stack;

  /*
   * Instantiate a stack object.
   */
  Stack* createStack();

  /*
   * Delete an stack object.
   */
  void deleteStack(Stack*);

  /*
   * Push the data onto the top of stack.
   */
  void push(Stack*, int data);

  /*
   * Pop the a data from the top of stack, and delete it from the stack.
   */
  int pop(Stack*);


  /*
   * Peek the a data from the top of stack without deleting it.
   */
  int peek(Stack*);

  /*
   * Peek the a data from the top of stack without deleting it.
   */
  bool isEmpty(Stack*);

#ifdef __cplusplus
}
#endif

#endif /* STACK_H */
