#include<stdio.h>

int compator(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int majorityElement(int* nums, int numsSize){

	//暴力求解
	/*qsort(nums,numsSize,sizeof(int),compator);
	int num=0;
	int maxnum=0;
	int max=nums[0];
	int i=0;
	int model=nums[0];
	while(i<numsSize)
	{
	if(nums[i]==max)
	{
	num++;
	if(num>maxnum)
	{
	maxnum=num;
	model=nums[i];
	}
	i++;
	}
	else
	{
	num=0;
	max=nums[i];
	}
	}
	return model;*/

	//快排返回中位数
	/*int target=numsSize/2;
	qsort(nums,numsSize,sizeof(int),compator);
	return nums[target];*/

	//投票法
	int vote = 0;
	int model;
	for (int i = 0; i<numsSize; i++)
	{
		if (vote == 0)
		{
			model = nums[i];
			vote++;
		}
		else
		{
			if (nums[i] == model)
				vote++;
			else
				vote--;
		}
	}
	return model;
}