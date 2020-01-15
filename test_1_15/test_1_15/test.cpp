#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool isPalindrome(char * s){


	int len = strlen(s);
	char *arr = (char*)malloc(sizeof(char)*len);
	int top = -1;
	for (int i = 0; i<len; i++)
	{
		if (s[i] >= 'A'&&s[i] <= 'Z')
			arr[++top] = s[i] + 32;
		else if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= '0'&&s[i] <= '9'))
			arr[++top] = s[i];
	}
	int left = 0, right = top;
	while (left<right)
	{
		if (arr[left] == arr[right])
		{
			left++;
			right--;
		}
		else
			return false;

	}
	return true;
}
int compress(char* chars, int charsSize){

	int num = 0;
	char *slow = chars, *fast = chars;
	while (*fast)
	{
		int n = 0;
		while (*slow == *fast)
		{
			n++;
			fast++;
		}
		num++;
		slow++;
		if (n == 1)
			continue;
		char s[1000];
		sprintf(s, "%d", n);
		for (int i = 0; i<strlen(s); i++)
		{
			*slow = s[i];
			slow++;
			num++;
		}
	}
	return num;
}
int com(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int findUnsortedSubarray(int* nums, int numsSize){

	int left = 0;
	int right = numsSize - 1;
	int *arr = (int*)malloc(sizeof(int)*numsSize);
	for (int i = 0; i<numsSize; i++)
	{
		arr[i] = nums[i];
	}
	qsort(nums, numsSize, sizeof(int), com);
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] == arr[i])
			left++;
		else
			break;
	}
	for (int i = numsSize - 1; i >= 0; i--)
	{
		if (nums[i] == arr[i])
			right--;
		else
			break;
	}
	if (left == numsSize)
		return 0;
	else
		return right - left + 1;
}
int evalRPN(char ** tokens, int tokensSize)
{
	int arr[20000];
	int top = 0;
	int num_1, num_2;
	for (int i = 0; i<tokensSize; i++)
	{
		if (tokens[i][1] == '\0' && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
		{
			num_2 = arr[--top];
			num_1 = arr[--top];
			switch (tokens[i][0])
			{
			case '+':
				arr[top++] = num_1 + num_2;
				break;
			case '-':
				arr[top++] = num_1 - num_2;
				break;
			case '*':
				arr[top++] = num_1*num_2;
				break;
			case '/':
				arr[top++] = num_1 / num_2;
				break;
			default:
				break;
			}
		}
		else
		{
			arr[top++] = atoi(tokens[i]);
		}
	}
	return arr[--top];
}

int main()
{
	char* s = "aabbccc";
	
	
	
	printf("%d", compress(s,7));
	system("pause");
	return 0;
}