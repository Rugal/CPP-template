#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "stack.h"

typedef struct Node Node;

static struct Node
{
    int data;
    Node* next;
};

static Node* node(int data)
{
    Node* n = malloc(sizeof(Node));
    assert(NULL != n);
    memset(n, 0, sizeof(Node));
    n->data = data;
    return n;
}

static void delete(Node* n)
{
    assert(n != NULL);
    free(n);
}


struct Stack
{
    Node* top;
    unsigned int size;
};

//-----------------------------Private functions---------------------------

static void clear(Stack* s)
{
    assert(s != NULL);
    while(!isEmpty(s))
        pop(s);
}

//-----------------------------Public functions----------------------------

bool isEmpty(Stack* s)
{
    assert(s != NULL);
    return s->size == 0;
}

/*
 * Instantiate a stack object.
 */
Stack* createStack()
{
    Stack* s = malloc(sizeof(Stack));
    assert(NULL != s);
    memset(s, 0, sizeof(Stack));
    return s;
}

/*
 * Delete an stack object.
 */
void deleteStack(Stack* s)
{
    if(s != NULL)
        clear(s);
}

/*
 * Push the data onto the top of stack.
 */
void push(Stack* s, int data)
{
    assert(NULL != s);
    Node * n = node(data);
    if(isEmpty(s))
        s->top = n;
    else
    {
        n->next = s->top;
        s->top = n;
    }
    s->size++;
}

/*
 * Pop the a data from the top of stack, and delete it from the stack.
 */
int pop(Stack* s)
{
    int data = peek(s);
    Node* top = s->top;
    s->top = top->next;
    delete(top);
    s->size--;
    return data;
}


/*
 * Peek the a data from the top of stack without deleting it.
 */
int peek(Stack* s)
{
    assert(NULL != s);
    assert(!isEmpty(s));
    return s->top->data;
}
