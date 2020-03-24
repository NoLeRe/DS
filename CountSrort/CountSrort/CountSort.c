#include<stdio.h>
#include<stdlib.h>


void CountSort(int *a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i]>max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int *arr = (int*)malloc(sizeof(int)*range);
	memset(arr, 0, sizeof(int)*range);
	for (int i = 0; i < n; i++)
	{
		arr[a[i] - min]++;
	}
	for (int i = 0, j = 0; i < range; i++)
	{
		while (arr[i]--)
			a[j++] = i + min;
	}
}

int main()
{
	int a[5] = { 5, 1, 4, 9, 3 };
	CountSort(a, 5);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}