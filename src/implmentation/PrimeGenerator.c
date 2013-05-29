/*
 * =====================================================================================
 *
 *       Filename:  PrimeGenerator.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月23日 10时42分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rugal Bernstein (), ryujinwrath@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "PrimeGenerator.h"

struct PrimeGenerator 
{
	unsigned int actualSize;
	unsigned int targetSize;
	unsigned int primeCount;
	short    *array;
};

PrimeGenerator* initPrimeGenerator(PrimeGenerator* pg);
PrimeGenerator* initSize(PrimeGenerator* pg);
PrimeGenerator* create(PrimeGenerator* pg);
PrimeGenerator* clear(PrimeGenerator* pg);
void destroy(PrimeGenerator* pg);
PrimeGenerator* doGeneratePrimes(PrimeGenerator* pg);
//--------------------------------------------------------------

PrimeGenerator* initPrimeGenerator(PrimeGenerator* pg)
{
	if(NULL!=pg)
	{
		pg->actualSize=3;
		pg->primeCount=1;
		initSize(pg);
	}
	return pg;
}
PrimeGenerator* initSize(PrimeGenerator* pg)
{
	if(NULL==pg)
	  return NULL;
	pg->array=malloc(sizeof(short)*(pg->targetSize+1));
	if(NULL==pg->array)
	{
		exit(1);
	}
	memset(pg->array,0,pg->targetSize);
	pg->array[2]=1;
	return pg;
}
PrimeGenerator* create(PrimeGenerator* pg)
{
	pg=(PrimeGenerator*)malloc(24);
	if((PrimeGenerator*)NULL==pg)
	{
		exit(1);
	}
	return pg;
}
PrimeGenerator* clear(PrimeGenerator* pg)
{
	if(NULL!=pg->array)
	  free(pg->array);
	return pg;
}
void destroy(PrimeGenerator* pg)
{
	clear(pg);
	free(pg);
}






PrimeGenerator* createPrimeGenerator(int size)
{
	PrimeGenerator * pg=NULL;
	create(pg);
	pg->targetSize=size;
	initPrimeGenerator(pg);
	return pg;
}
void destroyPrimeGenerator(PrimeGenerator* pg)
{
	if(NULL!=pg)
	{
		destroy(pg);
	}
}
PrimeGenerator* execute(PrimeGenerator* pg)
{
	if(NULL==pg)
		exit(1);
	clear(pg);
	initSize(pg);
	doGeneratePrimes(pg);
	return pg;
}
void setTargetSize(PrimeGenerator* pg,int size)
{
	if(NULL==pg)
	{
		create(pg);
	}
	pg->targetSize=size;
}
PrimeGenerator* doGeneratePrimes(PrimeGenerator* pg)
{
	int i=0;
	short* array=pg->array;
	for(i=2;i<pg->targetSize;i++)
	{
		if(0==array[i])
		{
			array[i]++;
			pg->primeCount++;
		}
		unsigned int j=0;
		for(j=1; i*j < pg->targetSize ;j++)
		{
			if(0==array[i*j])
			{
				array[i*j]--;
			}
			if(i*j >= pg->actualSize)
			{
				pg->actualSize=i*j+1;
			}
		}
	}
	return pg;
}
