#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning(disable:4996)

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int i = 0, j = 0;
	int *arr = (int*)malloc(sizeof(int)* 2);
	for (i = 0; i<numsSize - 1; i++)
	{
		for (j = i + 1; j<numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				arr[0] = i;
				arr[1] = j;
			}
		}
	}
	*returnSize = 2;
	return arr;
}
char * addBinary(char * a, char * b){
	int len_a = strlen(a), len_b = strlen(b);
	int len = 0;
	int sum = len_a>len_b ? len_a : len_b;

	char temp;
	char *a_1 = (char*)malloc(sizeof(char)*sum); //存放a
	char *b_1 = (char*)malloc(sizeof(char)*sum); //存放b 
	char *c = (char*)malloc(sizeof(char)*(sum + 2)); //存放运算后的值
	for (int i = 0; i<sum + 2; i++)
	{
		c[i] = '0';
	}

	if (len_a>len_b)
	{
		len = len_b - 1;
		for (int i = sum - 1; i >= 0; i--)
		{
			if (len >= 0)
			{
				b_1[i] = b[len];
				len--;
			}
			else
				b_1[i] = '0';
		}
		for (int i = sum - 1; i >= 0; i--)
		{
			a_1[i] = a[i];
		}
	}
	if (len_a<len_b)
	{
		len = len_a - 1;
		for (int i = sum - 1; i >= 0; i--)
		{
			if (len >= 0)
			{
				a_1[i] = a[len];
				len--;
			}
			else
				a_1[i] = '0';
		}
		for (int i = sum - 1; i >= 0; i--)
		{
			b_1[i] = b[i];
		}
	}
	if (len_a == len_b)
	{
		len = len_b - 1;
		for (int i = sum - 1; i >= 0; i--)
		{
			a_1[i] = a[i];
			b_1[i] = b[i];
		}

	}
	len = sum - 1;
	for (int i = sum; i >= 0; i--)
	{
		if (len >= 0)
		{
			temp = a_1[len] + b_1[len] + c[i] - '0'-'0';
			if (temp>'2')
			{
				c[i] = '1';
				c[i - 1] = '1';

			}
			if (temp == '2')
			{
				c[i] = '0';
				c[i - 1] = '1';

			}
			if (temp == '1')
			{
				c[i] = '1';

			}
			if (temp == '0')
			{
				c[i] = '0';

			}
			len--;
		}
		else
		{
			if (temp >= '2')
				c[0] = '1';
			else
			{
				c[sum + 1] = '\0';
				return c + 1;
			}
		}
	}
	c[sum + 1] = '\0';
	return c;
}
int myAtoi(char * str){
	long sum = 0;
	int flag = 1;
	while (*str == ' ')
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	if (*str>'9' || *str<'0')
		return 0;
	while (*str&&*str >= '0'&&*str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
		if (sum>INT_MAX)
			return flag == -1 ? INT_MIN : INT_MAX;
	}
	return sum*flag;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	*returnSize = 2;
	int *arr = (int*)malloc(sizeof(int)* 2);
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{
		if (nums[left] == target)
		{
			if (nums[right] == target)
			{
				arr[0] = left;
				arr[1] = right;
				return arr;
			}
			else
				right--;
		}
		else
			left++;
	}
	arr[0] = -1;
	arr[1] = -1;
	return arr;
}
int main()
{
	/*char s[] = "abcdefgh", *p = s;
	p += 3;*/
	//printf("%d\n", strlen(strcpy(p, "ABCD")));
	char s[] = "abcdef";
	printf("%s\n", strcpy(s, "abc"));
	system("pause");
	return 0;
}