#include <stdio.h>
#include "sort.h"


int main()
{
    Stack* s=createStack();
    push(s,1);
    int data = pop(s);
    printf("%d", data);
    deleteStack(s);
    return 0;
}
