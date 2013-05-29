/*
 * =====================================================================================
 *
 *       Filename:  Stack.h
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
 * \file Stack.h
 * \brief declaration of Stack container
 */
#pragma once
#include"util.h"
#include"Node.h"


/**
 * \typedef typedef struct Stack Stack
 * \brief define the name of struct Stack used in this project
 */
typedef struct Stack Stack;

/**
 * \fn Stack* createStack()
 * \brief used to create and initialize a stack
 * \return a stack pointer
 */
Stack* createStack();


/**
 * \fn void destroyStack(Stack* stack)
 * \brief to destroy and revoke memory of a stack
 * \param stack is the target stack to be processed
 */
void destroyStack(Stack* stack);


/**
 * \fn Stack* clearStack(Stack* stack)
 * \brief to clear a stack but not revoke the memory
 * \param stack is the target stack to be cleared
 * \return give back the cleared stack pointer
 */
Stack* clearStack(Stack* stack);
/**
 * \fn void push(Stack* stack ,TYPE data)
 * \brief push a data into a stack
 * \param stack the target stack 
 * \param data the number that will be pushed
 */
void push(Stack* stack ,TYPE data);
/**
 * \fn void pop(Stack* stack)
 * \brief pop the top from a stack
 * \param stack the target stack 
 */
void pop(Stack* stack);



/**
 * \fn bool isEmptyStack(Stack* stack)
 * \brief judge is this stack is empty (not null)
 * \param stack the target stack 
 * \return true if is really empty&not null;false if null or not empty
 */
bool isEmptyStack(Stack* stack);
/**
 * \fn TYPE getTop(Stack* stack)
 * \brief get top data of this stack
 * \param stack the target stack 
 * \return get data of stack top,;or -1 or is null stack
 */
TYPE getTop(Stack* stack);
/**
 * \fn int  getDepth(Stack* stack)
 * \brief get the depth os this stack;0 of it is null or empty
 * \param stack the target stack 
 * \return the depth of this stack
 */
int  getDepth(Stack* stack);
/**
 * \fn bool isNullStack(Stack* stack)
 * \brief judge if this stack is NULL pointer
 * \param stack the target stack 
 * \return true if this stack is really NULL pointer;other return false
 */
bool isNullStack(Stack* stack);
