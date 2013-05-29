/*
 * =====================================================================================
 *
 *       Filename:  stack.c
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
#include"stack.h"


struct node
{
	TYPE data;
	struct node *next;
};
struct stack
{
	struct node * bottom;
	int size;
};


node* newNode(TYPE);
void deleteNode(node*);
void deleteStack(stack*);


stack* createStack()
{
	stack* s=(stack*)malloc(sizeof(stack));
	s->bottom=NULL;
	s->size=0;
	return s;
}
void destroyStack(stack* s)
{
	if(NULL!=s)
	{
		while(!isEmpty(s))
		{
			pop(s);
		}
		deleteStack(s);
	}
}
stack* initStack(stack* s)
{
	if(NULL!=s)
	{
		destroyStack(s);
	}
	s=createStack();
	return s;
}

bool isEmpty(stack* s)
{
	return (s->size==0);
}
int  sizeOf(stack* s)
{
	int l=0;
	if(NULL!=s)
	{
		l=s->size;
	}
	return l;
}

TYPE dataOf(node* n)
{
	if(NULL!=n)
	{
		return n->data;
	}
	return (TYPE)NULL;
}

TYPE getTop(stack* s)
{
	TYPE d=(TYPE)NULL;
	if(NULL!=s)
	{
		if(!isEmpty(s))
		{
			d=dataOf(s->bottom);
		}
	}
	return d;
}


node* push(stack* s,TYPE d)
{
	node* n=newNode(d);
	if(NULL==s)
	{
		s=createStack();
	}
	if(!isEmpty(s))
	{
		n->next=s->bottom;
	}
	s->bottom=n;
	s->size++;
	return n;
}
TYPE pop(stack* s)
{
	TYPE data=(TYPE)NULL;
	if(NULL!=s)
	{
		if(!isEmpty(s))
		{
			node* n=s->bottom;
			data=n->data;
			s->bottom=n->next;
			s->size--;
			deleteNode(n);
		}
	}
	return data;
}

node* newNode(TYPE d)
{
	node* n=(node*)malloc(sizeof(node));
	n->data=d;
	n->next=NULL;
	return n;
}
void deleteNode(node* n)
{
	if(NULL!=n)
	{
		n->next=NULL;
		free(n);
		n=NULL;
	}
}
void deleteStack(stack* s)
{
	if(NULL!=s)
	{
		s->bottom=NULL;
		free(s);
	}
}
