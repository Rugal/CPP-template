#include"sort.h"
#include"Stack.h"
#include<malloc.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

TYPE* copyArray(TYPE* array,int length);
void quickSort(TYPE *a, int n);
void  mergeSplit(TYPE*,TYPE*,int,int);
void  mergeSort(TYPE*,TYPE*,int length,int left,int middle,int right);

TYPE* selection(TYPE* array, int length)
{
	TYPE* copy=copyArray(array,length);
    int i = 0, j = 0;
    for (i = 0; i < length; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (copy[i]>copy[j])
            {
                SWAP(copy[i], copy[j]);
            }
        }
    }
    return copy;
}

TYPE* insertion(TYPE*array, int length)
{
    TYPE* copy = copyArray(array,length);
    if (length < 1)
    {
        return array;
    }
    *(copy + 0) = *(array + 0);
    int i, j, currentLast = 0;
    for (i = 1; i < length; i++)
    {
        int insert = *(array + i);
        for (j = 0; j <= currentLast; j++)
        {
            if (j == 0 && (*(copy + j) >= insert))
            {
                // move right and insert at the head
                int k;
                for (k = currentLast + 1; k > 0; k--)
                {
                    *(copy + k) = *(copy + k - 1);
                }
                *(copy + 0) = insert;
                currentLast++;
                break;
            }
            if (j == currentLast && (*(copy + j) <= insert))
            {
                //append at the tail
                *(copy + j + 1) = insert;
                currentLast++;
                break;
            }
            if (*(copy + j - 1) < insert && *(copy + j) >= insert)
            {
                // move right and insert at the j
                int k;
                for (k = currentLast + 1; k > j; k--)
                {
                    *(copy + k) = *(copy + k - 1);
                }
                *(copy + j) = insert;
                currentLast++;
                break;
            }
        }
    }
    return copy;
}

TYPE* bubble(TYPE* array, int length)
{
    TYPE* copy = copyArray(array,length);
    int i, j;
    for (i = 0; i < length; i++)
    {
        for (j = 1; j < length; j++)
        {
            if (*(copy + j - 1)>*(copy + j))
            {
                SWAP(*(copy + j - 1), *(copy + j));
            }
        }
    }
    return copy;
}

TYPE* base(TYPE* array, int length);

TYPE* quick(TYPE *a, int n) //~ qsort of 'iterative version
{
	TYPE* array=copyArray(a,n);
	quickSort(array,n);
	return array;
}

void quickSort(TYPE *a, int n) //~ qsort of 'iterative version
{
	if(n <= 1)//number of element to be sorted
	  return ;
	Stack* ranges=createStack(); //~ Stack of ranges to be sorted
	int l = 0;
	int r = n;
	push(ranges,l);
	push(ranges,r); //~ initial range
	while(!isEmptyStack(ranges))                    // 1  2  3  4
	{
		int tr = r = getTop(ranges); pop(ranges);
		int tl = l = getTop(ranges); pop(ranges);
		if(r - l <= 1) //~ range sorted
		  continue;
		//~ partition begins
		int pivot = a[tl];
		while(tr > tl)
		{
			while(tr > tl && a[--tr] > pivot);
			a[tl] = a[tr];
			while(tr > tl && a[++tl] < pivot);
			a[tr] = a[tl];
		}
		a[tl] = pivot;
		//~ partition ends
		//~ ranges pushed, with order counting for little
		push(ranges,l); push(ranges,tl);
		push(ranges,tl+1); push(ranges,r);
	}
	destroyStack(ranges);
}

TYPE* merge(TYPE* array,int length)
{
	TYPE* result=(TYPE*)malloc(sizeof(TYPE)*length);
	TYPE* copy=copyArray(array,length);
	int split;
	for(split=1;split<length;split*=2)
	{// make a projection of splitting the array by this splitting factor
		mergeSplit(array,result,length,split);
	}
	if(NULL!=copy)
	{
		free(copy);
	}
	return result;
}

void  mergeSplit(TYPE* source,TYPE* result,int length,int split)
{
	int i=0;
	for(i=0;i<length;i=i+2*split)
	{
		mergeSort(source,result,length,i,i+split-1,i+2*split-1);
		//   0  1  2  3  4  5  6  7  8  9  10              length=11
	}
	memcpy(source,result,length*(sizeof(TYPE)));
}

void  mergeSort(TYPE* src,TYPE* result,int length,int left,int middle,int right)
{
	int i=0,j=0,position=left;
	for(i=left,j=middle+1;i<=middle&&j<=right&&i<length&&j<length;position++)
	{
		if(src[i]<src[j])
		{
			result[position]=src[i++];
		}
		else
		{
			result[position]=src[j++];
		}
	}
	int t=0;
	for(t=i;t<=middle&&t<length;t++)
	{
		result[position++]=src[t];
	}
	for(t=j;t<=right&&t<length;t++)
	{
		result[position++]=src[t];
	}
}

TYPE* pile(TYPE*, int);

TYPE* copyArray(TYPE* array,int length)
{
    TYPE* copy = (TYPE*) malloc(sizeof (TYPE) * length);
	memcpy(copy,array,length*(sizeof(TYPE)));
	return copy;
}
