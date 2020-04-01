#include<stdio.h>
#include<stdlib.h>

int compator(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}


int findRepeatNumber(int* nums, int numsSize){
	//时间复杂度O(N),空间复杂度O(N)
	/*int a[numsSize];
	memset(a,0,sizeof(int)*numsSize);
	for(int i=0;i<numsSize;i++)
	{
	a[nums[i]]++;
	if(a[nums[i]]>1)
	return nums[i];

	}
	return -1;
	*/
	//时间复杂度O(NlogN),空间复杂度O(1)
	qsort(nums, numsSize, sizeof(int), compator);
	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i] == nums[i + 1])
			return nums[i];
	}
	return -1;


}