#include<stdio.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

	int *arr = (int*)malloc(sizeof(int)* 2);
	int i = 0, j = numsSize - 1;
	while (i<j)
	{
		int sum = nums[i] + nums[j];
		if (sum>target)
			j--;
		else if (sum<target)
			i++;
		else
		{
			arr[0] = nums[i];
			arr[1] = nums[j];
			break;
		}

	}
	*returnSize = 2;
	return arr;

}