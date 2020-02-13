#include<stdio.h>
#include<stdlib.h>

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