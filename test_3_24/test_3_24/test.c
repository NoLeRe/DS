#include<stdio.h>
#include<stdlib.h>


void merge(int *a, int left, int right, int *temp)
{
	int index = left;
	int mid = (left + right) / 2;
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			temp[index++] = a[begin1++];
		else
			temp[index++] = a[begin2++];
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
			temp[index++] = a[begin1++];
	}
	else
	{
		while (begin2 <= end2)
			temp[index++] = a[begin2++];
	}
	memcpy(a + left, temp + left, sizeof(int)*(right - left + 1));

}
void _mergesort(int *a, int k, int n, int *temp)
{

	int i = 0;
	while (i+2*k-1 < n ) //i+2k-1<n     k表示几个元素一组，合并起来下标小于n
	{
		merge(a, i, i + 2 * k - 1, temp);
		i += 2 * k;
	}
	if (i < n - k)  //i+k-1<n-1    右边界下标小于数组最后一个元素下标
	{
		merge(a, i, n - 1, temp);
	}

}

void MergeSortNor(int *a, int n)
{
	int *temp = (int*)malloc(sizeof(int)*n);
	int k = 1;
	while (k < n)
	{
		_mergesort(a, k, n, temp);
		k *= 2;
	}
	free(temp);
}

int main()
{
	int a[7] = { 10, 6, 7, 1, 4, 9, 3 };
	MergeSortNor(a, 7);
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}