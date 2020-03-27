#include<stdio.h>
#include<string.h>
//有效的字母异位词
bool isAnagram(char * s, char * t){

	int m = strlen(s);
	int n = strlen(t);
	if (m != n)
		return false;
	int a[26] = { 0 };
	for (int i = 0; i<m; i++)
	{
		a[s[i] - 'a']++;
		a[t[i] - 'a']--;
	}
	for (int i = 0; i<26; i++)
	{
		if (a[i] != 0)
			return false;
	}
	return true;

}