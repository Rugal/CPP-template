/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/06/2012 10:59:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rugal Bernstein
 *   Organization:  
 *
 * =====================================================================================
 */
/**
 * \file stack.h
 * \brief declaration of stack container
 */
#pragma once
#include"util.h"

/**
 * \struct node
 * \brief node is a basic container of data.
 * used by local stack
 */
typedef struct node node;
/**
 * \struct stack
 * \brief stack is used by some sorting method
 */
typedef struct stack stack;
/**
 * \fn stack* createStack()
 * \brief create and initialize a empty stack
 * \return this stack pointer
 */
stack* createStack();
/**
 * \fn void destroyStack(stack* s)
 * \brief clear and destroy a stack,free memory space.
 * \param s the stack to be destroyed
 */
void destroyStack(stack*s);
/**
 * \fn stack* initStack(stack*s)
 * \brief clear a stack.
 * \param s the stack to be clear
 * \return the stack has been cleared
 */
stack* initStack(stack*s);
/**
 * \fn bool isEmpty(stack*s)
 * \brief judge a stack if it is empty(not null stack)
 * \param s the stack to be judge
 * \return true if the stack is really empty,other will be false
 */
bool isEmpty(stack*s);
/**
 * \fn int sizeOf(stack*s)
 * \brief return the length or size of this stack.
 * \param s the stack to be measured.
 * \return return the length of this stack.If stack is null ,return 0
 */
int  sizeOf(stack*s);
/**
 * \fn node* push(stack*s,TYPE data)
 * \brief push a data onto this stack's top level
 * \param s the target stack
 * \param data the number to be pushed
 * \return A node pointer to this newly pushed data node
 */
node* push(stack*s,TYPE data);
/**
 * \fn TYPE pop(stack*s)
 * \brief pop a data node from the top level
 * \param s the target stack
 * \return A node pointer to this newly poped data node
 */
TYPE pop(stack*s);
/**
 * \fn  TYPE dataOf(node*n)
 * \brief get the data of this node.
 * \param n is the target node
 * \return the number data inside this node
 */
TYPE dataOf(node*n);
/**
 * \fn TYPE getTop(stack*s)
 * \brief get the top node of this stack
 * \param s is the target node
 * \return the number data inside this stack's top node
 */
TYPE getTop(stack*s);
