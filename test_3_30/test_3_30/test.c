#include<stdio.h>



//连续子数组的最大和
int maxSubArray(int* nums, int numsSize){

	int sum = 0;
	int max = nums[0];

	for (int i = 0; i<numsSize; i++)
	{
		sum += nums[i];
		if (sum<0)
		{
			sum = 0;
			if (nums[i]>max)
				max = nums[i];
		}
		else if (sum>max)
			max = sum;
	}
	return max;
}