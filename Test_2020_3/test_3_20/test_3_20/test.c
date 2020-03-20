#include<stdio.h>


void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void AdjustDown(int *a, int root, int n)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1<n&&a[child]<a[child + 1])
			child++;
		if (a[parent]<a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}

}

int findKthLargest(int* nums, int numsSize, int k){

	for (int i = (numsSize - 2) / 2; i >= 0; i--)
	{
		AdjustDown(nums, i, numsSize);
	}
	for (int i = numsSize - 1; i>numsSize - k; i--)
	{
		swap(&nums[0], &nums[i]);
		AdjustDown(nums, 0, i);
	}
	return nums[0];

}