/*
 * =====================================================================================
 *
 *       Filename:  BigInt.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月24日 10时32分55秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rugal Bernstein (), ryujinwrath@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdbool.h>
#include "BigInt.h"

#define reverseAt(bi, position) \
	(bi->array[bi->length-1-(position)])

struct BigInt
{
	bool positive;
	unsigned int length;
	unsigned int *array;
};

//-----------------------------------------------
BigInt* initBigInt(BigInt* bi,unsigned int size);
BigInt* clear(BigInt* bi);
BigInt* minus(BigInt* a,BigInt* b);
BigInt* plus(BigInt* a,BigInt* b);
int countForZero(BigInt* bi);
BigInt* shrinkZero(BigInt* bi);


//-----------------------------------------------

BigInt* createBigInt(unsigned int size)
{
	BigInt* bi=(BigInt*)malloc(sizeof(BigInt));
	if(NULL==bi)
	  exit(1);
	initBigInt(bi,size);
	return bi;
}
BigInt* clear(BigInt* bi)
{
	if(NULL==bi)
	  return NULL;
	if(NULL!=bi->array)
	  free(bi->array);
	bi->array=NULL;
	bi->length=0;
	bi->positive=true;
	return bi;
}
BigInt* initBigInt(BigInt* bi,unsigned int size)
{
	if(NULL==bi)
	  return NULL;
	bi->positive=true;
	bi->length=size;
	bi->array=(unsigned int *)malloc(bi->length*sizeof(unsigned int));
	memset(bi->array,0,bi->length);
	return bi;
}
void destroyBigInt(BigInt* bi)
{
	clear(bi);
	if(NULL!=bi)
	  free(bi);
}
BigInt* clearBigInt(BigInt* bi)
{
	return clear(bi);
}
BigInt* setLength(BigInt* bi,unsigned int size)
{
	if(NULL==bi)
	  return NULL;
	bi->length=size;
	return bi;

}
BigInt* inputBigInt(char* string)
{
	if(NULL==string)
	  return NULL;


	unsigned int i=0;	
	int size=0;
	for(i=0;string[i]!='\0';i++)
		if(string[i]!='-')
		  size++;
	BigInt* bi=createBigInt(size);
	i=0;
	if('-'==string[0])
	{
	  bi->positive=false;
	  i=1;
	}
	else
	  bi->positive=true;
	bi->length=0;
	for(;string[i]!='\0';i++,bi->length++)
	  bi->array[bi->length]=string[i]-'0';
	return bi;
}
unsigned int* outputBigInt(BigInt* bi)
{
	if(NULL==bi)
	  return NULL;
	return bi->array;
}
BigInt* plusBigInt(BigInt* a,BigInt* b)
{
	BigInt* bi;
	if(isPositive(a)^isPositive(b))
	{
		bi=minus(a,b);
		//these two bi have diffenerent operator
	}
	else
	{
		//both bi are positive or neaative
		bi=plus(a,b);
	}
	return bi;
}
BigInt* minusBigInt(BigInt* a,BigInt* b)
{
	BigInt* bi;
	if(isPositive(a)^isPositive(b))
	{
		//these two bi have diffenerent operator
		bi=plus(a,b);
	}
	else
	{
		//both bi are positive or neaative
		bi=minus(a,b);
	}

}
BigInt* plus(BigInt* a,BigInt* b)
{
	unsigned int max=(a->length > b->length?a->length:b->length);
	unsigned int i=0;
	BigInt* bi=createBigInt(max+1);
	for(i=0;i<max;i++)
	{
		unsigned first=0,second=0;
		if(i<a->length)
		  first=reverseAt(a,i);
		if(i<b->length)
		  second=reverseAt(b,i);
		reverseAt(bi,i)+=first+second;
		reverseAt(bi,i+1)=(reverseAt(bi,i)/10);
		reverseAt(bi,i)%=10;
	}
	int zero=countForZero(bi);
	if(zero!=0)//shrinking array's length cause the existence of 0
	{
		for(i=0;(i+zero)<bi->length;i++)
		  bi->array[i]=bi->array[i+zero];
		bi->length-=zero;
	}
	if(isPositive(a))
	  bi->positive=true;
	else
	  bi->positive=false;
	return bi;
}
BigInt* minus(BigInt* a,BigInt* b)
{
	//get to know which absolute number is bigger
	BigInt* big,*small;
	if(a->length>b->length)
	{
		big=a;
		small=b;
	}
	else if(a->length<b->length)
	{
		big=b;
		small=a;
	}
	else
	{
		int i=0;
		bool equal=true;
		for(i=0;i<a->length;i++)
		{
			if(a->array[i]==b->array[i])
			  continue;
			equal=false;
			if(a->array[i]>b->array[i])
			{
				big=a;
				small=b;
			}
			else
			{
				big=b;
				small=a;
			}
		}
		return createBigInt(1);
	}

	BigInt* bi=createBigInt(big->length);
	int i=0;
	for(i=0;i<big->length;i++)
	{
		unsigned first=0,second=0;
		if(i<a->length)
		  first=reverseAt(a,i);
		if(i<b->length)
		  second=reverseAt(b,i);
		reverseAt(bi,i)+=first-second;
		if(reverseAt(bi,i)<0)
		{
			reverseAt(bi,i+1)--;
			reverseAt(bi,i)*=-1;
		}
	}
	shrinkZero(bi);
	if(isPositive(big))
	  bi->positive=true;
	else
	  bi->positive=false;
	return bi;
}
bool isPositive(BigInt* a)
{
	return a->positive;
}
int countForZero(BigInt* bi)
{
	if(NULL==bi)
	  return -1;
	int i=0;
	int count=0;
	for(i=0;0==bi->array[i];i++)
	  count++;
	return count;
}
BigInt* setSymbol(BigInt* bi,bool symbol)
{
	if(NULL==bi)
	  return NULL;
	bi->positive=symbol;
	return bi;
}
void printBigInt(BigInt* bi)
{
	if(NULL==bi)
	  return ;
	if(!bi->positive)
	  printf("-");
	int i=0;
	for(i=0;i<bi->length;i++)
	  printf("%d",bi->array[i]);
}
BigInt* shrinkZero(BigInt* bi)
{
	int zero=countForZero(bi);
	if(zero!=0)//shrinking array's length cause the existence of 0
	{
		int i=0;
		for(i=0;(i+zero)<bi->length;i++)
		  bi->array[i]=bi->array[i+zero];
		bi->length-=zero;
	}
	return bi;
}
