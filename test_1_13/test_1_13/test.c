#include<stdio.h>
#include<stdlib.h>
#include<string.h>

float func(float a, int b)
{
	float m = 1, n = 1;
	int i;
	for (i = 1; i <b; i++)
	{
		m *= a / i;
		n += m;
	}
	return n;
}
int* sortArrayByParity(int* A, int ASize, int* returnSize) //按奇偶排序数组
{
	int *arr = (int*)malloc(sizeof(int)*ASize);
	int left = 0;
	int right = ASize - 1;
	for (int i = 0; i<ASize; i++)
	{
		if (A[i] % 2 == 0)
		{
			arr[left] = A[i];
			left++;
		}
		else
		{
			arr[right] = A[i];
			right--;
		}
	}
	*returnSize = ASize;
	return arr;
}
int pivotIndex(int* nums, int numsSize) //寻找数组的中心索引
{
	int sum = 0;
	int left_sum = 0;
	for (int i = 0; i<numsSize; i++)
	{
		sum += nums[i];
	}
	for (int i = 0; i<numsSize; i++)
	{
		if (left_sum * 2 == (sum - nums[i]))
			return i;
		left_sum += nums[i];
	}
	return -1;
}
int* plusOne(int* digits, int digitsSize, int* returnSize)// 加一
{

	for (int i = digitsSize - 1; i >= 0; i--)
	{
		digits[i] = (digits[i] + 1) % 10;
		if (digits[i] != 0)
			break;
	}
	*returnSize = digitsSize;
	if (digits[0] == 0)
	{
		int *arr = (int*)malloc(sizeof(int)*(digitsSize + 1));
		arr[0] = 1;
		for (int i = 1, j = 0; j<digitsSize; i++, j++)
		{
			arr[i] = digits[j];
		}
		*returnSize = digitsSize + 1;
		return arr;
	}
	else
	{
		*returnSize = digitsSize;
		return digits;
	}
}
int* plusOne(int* digits, int digitsSize, int* returnSize)// 加一
{

	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			digits[i]++;
			*returnSize = digitsSize;
			return digits;
		}
		digits[i] = 0;
	}
	int *arr = (int*)malloc(sizeof(int)*(digitsSize + 1));
	arr[0] = 1;
	for (int i = 1, j = 0; j<digitsSize; i++, j++)
	{
		arr[i] = digits[j];
	}
	*returnSize = digitsSize + 1;
	return arr;
}
int thirdMax(int* nums, int numsSize)  // 第三大的数
{
	long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i]>first)
		{
			first = nums[i];
		}
	}
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i]>second&&nums[i] != first)
		{
			second = nums[i];
		}
	}
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i]>third&&nums[i] != first&&nums[i] != second)
		{
			third = nums[i];
		}
	}
	if (third != LONG_MIN)
		return third;
	else
		return first;

}
int main()
{
	/*char *p = "abcdefgh", *r;
	long *q;
	q = (long*)p;
	q++;
	r = (char*)q;
	printf("%s\n", r);*/
	int arr[3] = { 3, 2, 1 };
	printf("%d", thirdMax(arr, 3));
	system("pause");
	return 0;
}