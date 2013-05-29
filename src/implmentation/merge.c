#include<malloc.h>
void merge(int array[],int start,int mid,int last)
{
	int begin1=start,begin2=mid+1,end1=mid,end2=last;
	int * temp=(int*)malloc((last-start+1)*sizeof(int));
	int count=0;
	while(begin1<=end1&&begin2<=end2)
	{
	//choose the smallest number and add to the tail
		if(array[begin1]<array[begin2])
		{
			temp[count++]=array[begin1++];
		}
		else
		{
			temp[count++]=array[begin2++];
		}
	}
	while(begin1<=end1)//put the remain data on to the tail
	{
		temp[count++]=array[begin1++];
	}
	while(begin2<=end2)
	{
		temp[count++]=array[begin2++];
	}
	int i=0;
	for(i=0;i<=(last-start);i++)//copy to origin data
	{
		array[start+i]=temp[i];
	}
	free(temp);
}

void split(int array[],int first,int last)
{
	int mid=0;
	if(first<last)
	{
		mid=(first+last)/2;
		split(array,first,mid);
		split(array,mid+1,last);
		merge(array,first,mid,last);
	}
}

void mergeSort(int array[],int length)
{
	split(array,0,length-1);
}
