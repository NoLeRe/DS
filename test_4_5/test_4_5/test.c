#include<stdio.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
int* exchange(int* nums, int numsSize, int* returnSize){

	/*int *a=(int*)malloc(sizeof(int)*numsSize);
	int i=0,j=numsSize-1;
	for(int k=0;k<numsSize;k++)
	{
	if(nums[k]%2==0)
	{
	a[j--]=nums[k];
	}
	else
	a[i++]=nums[k];
	}
	*returnSize=numsSize;
	return a;*/
	int i = 0, j = numsSize - 1;
	while (i<j)
	{
		while (nums[i] % 2 != 0 && i<j)
			i++;
		while (nums[j] % 2 == 0 && i<j)
			j--;
		swap(&nums[i], &nums[j]);
	}
	*returnSize = numsSize;
	return nums;
}