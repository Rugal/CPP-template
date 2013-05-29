/*
 * =====================================================================================
 *
 *       Filename:  Stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/06/2012 11:06:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rugal Bernstein
 *   Organization:  
 *
 * =====================================================================================
 */
#include<malloc.h>
#include"util.h"
#include"Stack.h"
#include"Node.h"


struct Stack
{
	Node* top;
	int depth;
};



bool isNullStack(Stack* stack)
{
	return (stack==NULL);
}
bool isEmptyStack(Stack* stack)
{
	if(!isNullStack(stack))
		if(0==stack->depth)
		  return true;
	return false;
}
int  getDepth(Stack* stack)
{
	if(isNullStack(stack))
		return 0;
	return stack->depth;
}
TYPE getTop(Stack* stack)
{
	if(isNullStack(stack))
	  return -1;
	if(isEmptyStack(stack))
	  return -1;
	return getNodeData(stack->top);
}



void push(Stack* stack ,TYPE data)
{
	Node* node=createNode();
	setNodeData(node,data);

	if(isNullStack(stack))
	  stack=createStack();
	if(isEmptyStack(stack))
	  stack->top=node;
	else
	{
		setNodePosterior(node,stack->top);
		stack->top=node;
	}
	stack->depth+=1;
}
void pop(Stack* stack)
{
	if(isNullStack(stack))
	  return;
	if(isEmptyStack(stack))
	  return;
	int depth=getDepth(stack);
	
	Node* node=NULL;
	if(depth==1)
	{
		node=stack->top;
		clearNode(node);
		stack->top=NULL;
	}
	else
	{
		node=getNodePosterior(stack->top);
		clearNode(stack->top);
		stack->top=node;
	}
	stack->depth-=1;
}
Stack* clearStack(Stack* stack)
{
	if(isNullStack(stack))
	  stack=createStack();
	while(!isEmptyStack(stack))
	  pop(stack);
	return stack;
}



Stack* createStack()
{
	Stack* stack=NULL;
	stack=(Stack*)malloc(sizeof(struct Stack));

	stack->depth=0;
	stack->top=NULL;

	return stack;
}



void destroyStack(Stack* stack)
{
	clearStack(stack);
	free(stack);
}

