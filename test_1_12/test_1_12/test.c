#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lengthOfLastWord(char * s){
	char *flag = s;
	char *cur = s;
	int count = 0;
	while (*cur)
	{
		while (*cur != ' '&&*cur != '\0')
		{
			cur++;
		}
		if (*cur == ' '&&*(cur + 1) != '\0')
		{
			cur++;
			flag = cur;
		}
	}
	while (*flag)
	{
		count++;
		flag++;
	}
	return count;

}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

	int end = m + n - 1;
	int end1 = m - 1;
	int end2 = n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1]<nums2[end2])
		{
			nums1[end] = nums2[end2];
			end--;
			end2--;
		}
		else
		{
			nums1[end] = nums1[end1];
			end--;
			end1--;
		}
	}
	while (end2 >= 0)
	{
		nums1[end] = nums2[end2];
		end2--;
		end--;
	}
	while (end1 >= 0)
	{
		nums1[end] = nums1[end1];
		end1--;
		end--;
	}
}
int lengthOfLastWord2(char * s){
	int count = 0;
	int len = strlen(s);
	if (len == 0 || *s == " ")
		return 0;
	int i, j;
	for (i = len - 1; i >= 0 && s[i] == ' '; i--);
	for (j = i; j >= 0 && s[j] != ' '; j--);
	return i - j;
}
int comp(const void *a, const void *b){
	return (*(int*)a > *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize){

	qsort(nums, numsSize, sizeof(int), comp);
	for (int i = 1; i<numsSize; i++)
	{
		if (nums[i - 1] == nums[i])
			return true;
	}
	return false;
}
void my_qsort(int *num, int numsize)
{
	for (int i = 0; i < numsize - 1; i++)  //ÂÖÊý
	{
		for (int j = 0; j < numsize - i - 1;)  
		{
			if (num[j] > num[j + 1])
			{
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

}
bool isLongPressedName(char * name, char * typed){
	char* cur_1 = name;
	char* cur_2 = typed;
	while (*cur_1&&*cur_2)
	{
		if (*cur_1 == *cur_2)
		{
			int flag_1 = 1;
			int flag_2 = 1;
			while (*cur_1 == *(cur_1 + 1))
			{
				flag_1++;
				cur_1++;
			}
			cur_1++;
			while (*cur_2 == *(cur_2 + 1))
			{
				flag_2++;
				cur_2++;
			}
			cur_2++;
			if (flag_2<flag_1)
				return false;
		}
		else
			return false;

	}
	if (*cur_1 != '\0')
		return false;
	else
		return true;
}
int* sortedSquares(int* A, int ASize, int* returnSize){
	int *arr = (int*)malloc(sizeof(int)*ASize);
	for (int i = 0; i<ASize; i++)
	{
		arr[i] = A[i] * A[i];
	}
	qsort(arr, ASize, sizeof(int), comparator);
	*returnSize = ASize;
	return arr;
}
char * reverseOnlyLetters(char * S){

	char *cur = S;
	char s[100];
	int top = -1;
	while (*cur)
	{
		if ((*cur >= 'A'&&*cur <= 'Z') || (*cur >= 'a'&&*cur <= 'z'))
		{
			s[++top] = *cur;
			cur++;
		}
		else
			cur++;
	}
	cur = S;
	while (*cur)
	{
		if ((*cur >= 'A'&&*cur <= 'Z') || (*cur >= 'a'&&*cur <= 'z'))
		{
			*cur = s[top--];
			cur++;
		}
		else
			cur++;
	}
	return S;
}

int main()
{
	char *s = "a ";
	lengthOfLastWord(s);
	printf("%d\n", lengthOfLastWord(s));
	system("pause");
	return 0;
}