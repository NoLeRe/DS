#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning(disable:4996)

int myAtoi(char * str){
	int flag = 1;
	long sum = 0;
	while (*str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = -1;
		str++;
	}
	if (*str>'9' || *str<'0')
		return 0;
	while (*str >= '0'&&*str <= '9')
	{
		sum = sum * 10 + *str - '0';
		str++;
		if (sum>INT_MAX)
			return flag == 1 ? INT_MAX : INT_MIN;
	}
	return sum*flag;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int *arr = (int*)malloc(sizeof(int)* 2);
	*returnSize = 2;
	int left = 0;
	int right = numsSize - 1;
	while (left <= right)
	{

		while (nums[left] == target)
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
		left++;
	}
	arr[0] = -1;
	arr[1] = -1;
	return arr;
}

struct ListNode {
     int val;
     struct ListNode *next;
};
typedef struct ListNode ListNode;

bool isPalindrome(struct ListNode* head)   //»ØÎÄÁ´±í
{
	if (head == NULL || head->next == NULL)
		return true;
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *nextp = NULL;
	ListNode *pre = NULL;
	while (head != slow)
	{
		nextp = head->next;
		head->next = pre;
		pre = head;
		head = nextp;
	}
	if (fast&&fast->next == NULL)
		slow = slow->next;
	while (pre)
	{
		if (pre->val != slow->val)
			return false;
		pre = pre->next;
		slow = slow->next;
	}
	return true;
}
int compress(char* chars, int charsSize){
	int cur = 0;
	for (int i = 0, j = 0; i<charsSize; j = i)
	{
		while (i<charsSize&&chars[i] == chars[j])
			i++;
		chars[cur++] = chars[j];
		if (i - j == 1)
			continue;
		char str[1000];
		sprintf(str, "%d", i - j);
		for (int k = 0; k<strlen(str); k++)
			chars[cur++] = str[k];
	}
	return cur;
}

int comparator(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int findUnsortedSubarray(int* nums, int numsSize){
	int arr[numsSize];
	for (int i = 0; i<numsSize; i++)
		arr[i] = nums[i];
	qsort(arr, numsSize, sizeof(int), comparator);
	int left = 0;
	int right = numsSize - 1;
	while (left<right)
	{
		while (nums[left] != arr[left])
		{
			if (nums[right] != arr[right])
			{
				return right - left + 1;
			}
			else
				right--;
		}
		left++;
	}
	return 0;
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
			arr[top++] = atoi(tokens[i]);
	}
	return arr[--top];
}
int main()
{
	int nums[2] = { 2, 1 };
	findUnsortedSubarray(nums, 2);
	system("pause");
	return 0;
}
