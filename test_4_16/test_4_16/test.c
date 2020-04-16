#include<stdio.h>

char * findLongestWord(char * s, char ** d, int dSize){

	char *str = "";
	int max = -1;
	for (int i = 0; i<dSize; i++)
	{
		char* p = s;
		char* q = d[i];
		int j = 0, k = 0;
		while (p[j] != '\0'&&q[k] != '\0')
		{
			if (p[j] == q[k])
			{
				k++;
			}
			j++;
		}
		if (q[k] == '\0')
		{
			if (k>max)
			{
				max = k;
				str = d[i];
			}
			else if (k == max)
			{
				if (q[0] - str[0]<0)
					str = d[i];
			}
		}
	}
	return str;

}