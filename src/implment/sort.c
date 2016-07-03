#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sort.h"
#include "stack.h"


//------------------------------------------------
void quickSort(int* data, int size)
{
    if(size <= 1)//number of element to be sorted
      return ;
    Stack* ranges = createStack(); //~ Stack of ranges to be sorted
    int first = 0;
    int last = size;
    push(ranges, first);
    push(ranges, last); //~ initial range
    while(!isEmpty(ranges))                    // 1  2  3  4
    {
        int tempLast = last = pop(ranges);
        int tempFirst = first = pop(ranges);
        if(last - first <= 1) //~ range sorted
          continue;
        //~ partition begins
        int pivot = data[tempFirst];
        while(tempFirst < tempLast)
        {
            while(tempFirst < tempLast && data[--tempLast] > pivot);
            data[tempFirst] = data[tempLast];
            while(tempFirst < tempLast && data[++tempFirst] < pivot);
            data[tempLast] = data[tempFirst];
        }
        data[tempFirst] = pivot;
        //~ partition ends
        //~ ranges pushed, with order counting for little
        push(ranges, first); push(ranges, tempFirst);
        push(ranges, tempFirst+1); push(ranges, last);
    }
    deleteStack(ranges);
}

//------------------------------------------------
static void merge(int* data, int first, int mid, int last)
{
    int begin1 = first, end1 = mid;
    int begin2 = mid + 1, end2 = last;
    int* temp = malloc(sizeof(int) * (last - first + 1));
    int count = 0;
    while(begin1 <= end1 && begin2 <= end2)
    {
        //Choose the smallest number to append
        int smallIndex = (data[begin1] < data[begin2])? begin1++ : begin2++;
        temp[count++] = data[smallIndex];
    }
    while(begin1 <= end1)
        temp[count++] = data[begin1++];
    while(begin2 <= end2)
        temp[count++] = data[begin2++];
    for(int i = 0; i < (last - first + 1); i++)
        data[first + i] = temp[i];
    free(temp);
}

static void split(int* data, int first, int last)
{
    if(first < last && data)
    {
        int mid = (first + last) / 2;
        split(data, first, mid);
        split(data, mid + 1, last);
        merge(data, first, mid, last);
    }
}

void mergeSort(int* data, int size)
{
    split(data, 0, size - 1);
}
