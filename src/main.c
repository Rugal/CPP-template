#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"util.h"
#include"Stack.h"


int main()
{
	Stack* s=createStack();
	push(s,1);
	TYPE date=getTop(s);
	pop(s);
	return 0;
}
