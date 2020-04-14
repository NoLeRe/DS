#include<stdio.h>
#include<stdlib.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int add(int num)
{
	int count = 0;
	while (num)
	{
		if (num & 1)
			count++;
		num >>= 1;
	}
	return count;
}
int compator(const void* a, const void* b)
{
	int x = add(*(int*)a);
	int y = add(*(int*)b);
	if (x == y)
		return *(int*)a>*(int*)b;
	else
		return x>y;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){

	qsort(arr, arrSize, sizeof(int), compator);
	*returnSize = arrSize;
	return arr;

}