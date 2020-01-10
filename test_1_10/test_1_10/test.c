#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable:4996)
//char *toLowerCase(char * str){
//	if (str == NULL)
//		return str;
//	char *cur = str;
//	while (*cur)
//	{
//		if (*cur >= 'A'&&*cur <= 'Z')
//		{
//			*cur += 32;
//			cur++;
//		}
//		else
//			cur++;
//	}
//	return str;
//}
//
//int main()
//{
//	char* str = "LOVELY";
//	printf("%s\n", toLowerCase(str));
//	system("pause");
//	return 0;
//}
void rotate(int* nums, int numsSize, int k){
	k %= numsSize;
	for (int i = 0, j = numsSize - k - 1; i<j; i++, j--)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	for (int i = numsSize - k, j = numsSize - 1; i<j; i++, j--)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	for (int i = 0, j = numsSize - 1; i<j; i++, j--)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
}
int removeElement(int* nums, int numsSize, int val){

	if (numsSize == 0)
		return 0;
	int count = 0;
	int *cur = nums;
	int *start = nums;
	int *end = nums + numsSize - 1;
	while (start <= end)
	{
		if (*start == val)
			start++;
		else
		{
			*cur = *start;
			cur++;
			start++;
			count++;
		}
	}
	return  count;
}
int searchInsert(int* nums, int numsSize, int target){

	int j = numsSize;
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] == target)
			return i;
	}

	for (j = 0; j<numsSize; j++)
	{
		if (target<nums[j])
			return j;
	}
	if (j == numsSize)
		return numsSize;
	return 0;
}

 // 二分查找法
int searchInsert_2(int* nums, int numsSize, int target){

	int left = 0;
	int right = numsSize-1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
		{
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	if (nums[mid] < target)
		return mid + 1;
	else
		return mid;
}
bool canConstruct(char * ransomNote, char * magazine){
	int bucket[26] = { 0 };
	for (int i = 0; i<strlen(magazine); i++)
	{
		bucket[magazine[i] - 'a']++;
	}
	for (int i = 0; i<strlen(ransomNote); i++)
	{
		if (--bucket[ransomNote[i] - 'a']<0)
			return false;
	}
	return true;

}

bool isPalindrome(int x){
	if (x<0)
		return false;
	char s[10];
	int n = x;
	int top = -1;
	while (n)
	{
		s[++top] = n % 10;
		n /= 10;

	}
	int left = 0;
	while (left<top)
	{
		if (s[left] != s[top])
			return false;
		else
			left++;
		top--;
	}
	return true;
}
int main()
{
	int x = 10;
	int y = 10;
	x = y = ++y;
	printf("%d %d \n", x, y);
	system("pause");
	return 0;
}